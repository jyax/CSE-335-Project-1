/**
* @file PlayingArea.cpp
 * @author Gaya Kanagaraj
 * @author Nicole Kuang
 *
 * Playing area for the game
 */

#include "pch.h"
#include <wx/graphics.h>
#include "PlayingArea.h"
#include "Game.h"
#include "Program.h"
#include "ItemVisitor.h"
//#include "SplatBug.h"

using namespace std;

///  The time the text appears on screen
const double TextOnScreenDuration = 2.0;
/// File name for Level 0
const std::wstring Level0FileName = L"data/level0.xml";

/// File name for Level 1
const std::wstring Level1FileName = L"data/level1.xml";

/// File name for Level 2
const std::wstring Level2FileName = L"data/level2.xml";

/// File name for Level 3
const std::wstring Level3FileName = L"data/level3.xml";

/// The range from the center of the bug to see if hit or not
const int BugHitRange = 50;

/**
 * Draws the starting text
 * @param graphics the graphics context
 * @param width the width of the screen
 * @param height the height of the screen
 */
void PlayingArea::DrawPlayingArea(std::shared_ptr<wxGraphicsContext> graphics, const int width, const int height)
{
    graphics->PushState();

    // Create a white background bitmap
    wxBitmap bitmap(width, height);
    wxMemoryDC dc(bitmap);
    dc.SetBackground(*wxWHITE_BRUSH);
    dc.Clear();

    // Draw the bitmap onto the graphics context
    graphics->DrawBitmap(bitmap, 0, 0, width, height);
    mCurrentLevel->DrawLevelName(graphics);
    if(mLevelStart)
    {
        // Draw the game items
        for (auto item : mItems)
        {
            if (item != nullptr)
                item->Draw(graphics);

        }
        mCurrentLevel->DrawLevelName(graphics);

    }
    if(mLevelComplete && mCompleteDuration < TextOnScreenDuration)
    {
        mCurrentLevel->DrawLevelFinish(graphics);

    }


    graphics->PopState();
}

/**
 * Add a game item to the playing area
 * @param item a pointer to an item
 */
void PlayingArea::Add(shared_ptr<Item> item)
{
	mItems.push_back(item);
}

/**
* Set level files  to the playing area
*
*/
void PlayingArea::SetLevelFile()
{
//    mLevelZero->ReadLevel(Level0FileName);
//    mLevelOne->ReadLevel(Level1FileName);
//    mLevelTwo->ReadLevel(Level2FileName);
//    mLevelThree->ReadLevel(Level3FileName);
}

/**
 * Sets the level and passes the xmlfile to Level
 * @param level
 */
void PlayingArea::SetLevel(int level)
{
    mLevelNum = level;

    if (mLevelNum == 0)
    {
        mLevelZero->ReadLevel(Level0FileName);
        mCurrentLevel = make_shared<Level>(*mLevelZero);

    }
    else if (mLevelNum == 1)
    {
        mLevelOne->ReadLevel(Level1FileName);
        mCurrentLevel = make_shared<Level>(*mLevelOne);

    }
    else if (mLevelNum == 2)
    {
        mLevelTwo->ReadLevel(Level2FileName);
        mCurrentLevel = make_shared<Level>(*mLevelTwo);

    }
    else if (mLevelNum == 3)
    {
        mLevelThree->ReadLevel(Level3FileName);
        mCurrentLevel = make_shared<Level>(*mLevelThree);

    }
}

/**
 * Test an x,y click location to see if clicked
 * on some item in the game.
 * @param virX X location in virtual coordinate pixels
 * @param virY Y location in virtual coordinate pixels
 * @returns Pointer to item we clicked on or nullptr if none.
*/
std::shared_ptr<Item> PlayingArea::Click(double virX, double virY)
{
	for (auto i = mItems.rbegin(); i != mItems.rend();  i++)
	{
		if ((*i)->HitTest(virX, virY))
		{
			return *i;
		}
	}

	return nullptr;
}

/**
 * Moves an item in the game to the front of the screen (end of list) when clicked on
 * @param item pointer to item clicked on
 */
void PlayingArea::MoveToFront(std::shared_ptr<Item> item)
{
	auto loc = find(begin(mItems), end(mItems), item);
	if (loc != end(mItems))
	{
		// Create another of the found item, remove the original, then push the new one back
		std::shared_ptr<Item> foundItem = *loc;
		mItems.erase(loc);
		mItems.push_back(foundItem);
	}
}

/**
 * Accept a visitor for the collection
 * @param visitor The visitor for the collection
 */
void PlayingArea::Accept(ItemVisitor *visitor)
{
	for (auto item : mItems)
	{
		item->Accept(visitor);
	}
}

/**
* sets the level text duration
 * @param duration for the start text duration to start
*/
void PlayingArea::SetTextDuration(double duration)
{
    mCurrentLevel->SetTextDuration(duration);
}

/**
 * It sets the mLevelStart if the level clicked
 * @param value
 */
void PlayingArea::LevelStart(bool value)
{
    mLevelStart = value;
}

/**
* Clears the Itemlist
*/
void PlayingArea::Clear()
{
    mItems.clear();
}

/**
 * Updates the game
 * @param elapsed
 */
void PlayingArea::Update(double elapsed)
{

    mCurrentLevel->Update(elapsed);

    for (auto item : mItems)
    {
        item->Update(elapsed);
    }

    if(LevelComplete())
    {
        mCompleteDuration += elapsed;
    }
    if( mLevelComplete && mCompleteDuration > TextOnScreenDuration )
    {
        NextLevel();
        mCompleteDuration = 0.0;
    }


}


/**
 * move an item around the screen when clicked
 *
 * @param item the item to be moved
*/
void PlayingArea::MoveItem(std::shared_ptr<Item> item)
{
	auto loc = find(begin(mItems), end(mItems), item);
}

/**
 * Delete if the bug reaches to the program
 * @param bug the bug to be deleted
 */
void PlayingArea::RemoveItem(Item* bug)
{
    mDeleteItems.push_back(bug);
}

/**
 * call the CheckItem function for deleting the bug which
 * reaches to the program
 */
void PlayingArea::DeleteItem()
{
    for (auto item : mDeleteItems)
    {
        CheckItem(item);

    }
    mDeleteItems.clear();
}

/**
 * Deletes the bug which
 * reaches to the program
 * @param itemDelete  the bug pointer to delete
 */
void PlayingArea::CheckItem(Item *itemDelete)
{

    auto i = mItems.begin();
    while( i != mItems.end())
   {
       if( itemDelete == i->get() )
       {
            mItems.erase(i);
            break;
       }
       else{
           ++i;
       }
   }
}

/**
 * It check whether the level is complete or not
 * using Bug Visitor
 * @return true if completed else false
 */
bool PlayingArea::LevelComplete()
{
    ItemVisitor visitor;
    this->Accept(&visitor);
    int cnt = visitor.GetNumOfBugs();
    if (cnt == 0)
    {
        mLevelComplete = true;
        return true;
    }
    else if( cnt > 0)
    {
        int countSplat = 0;
        for (auto item : mItems)
        {
            if(item->GetIsHit())
            {
                countSplat ++;
            }
        }
        if ( cnt == countSplat)
        {
            mLevelComplete = true;
            return true;
        }
    }
    return false;
}

/**
 * Sets the nextlevel if there is no levelclicked
 */
void PlayingArea::NextLevel()
{
    if( mLevelComplete)
    {
        if (mLevelNum < 3)
        {
            mLevelNum += 1;
        }
        else
        {
            mLevelNum = 0;
        }
        mGame->SetLevel(mLevelNum);
        mLevelComplete = false;

    }
}