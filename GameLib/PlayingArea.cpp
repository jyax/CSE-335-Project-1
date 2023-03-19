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
#include "SplatBug.h"

using namespace std;

/// File name for Level 0
const std::wstring Level0FileName = L"data/level0.xml";

/// File name for Level 1
const std::wstring Level1FileName = L"data/level1.xml";

/// File name for Level 2
const std::wstring Level2FileName = L"data/level2.xml";

/// File name for Level 3
const std::wstring Level3FileName = L"data/level3.xml";

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




    graphics->PopState();
}

/**
 * Add a game item to the playing area
 * @param item a pointer to an item
 */
void PlayingArea::Add(shared_ptr<Item> item)
{
	if (item->IsProgram())
	{
		mItems.insert(mItems.begin(), item);
	}
	else
	{
		mItems.push_back(item);
	}
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
std::shared_ptr<Item> PlayingArea::SingleClick(double virX, double virY)
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
 * Test an x,y click location to see if double clicked
 * on some item in the game.
 * @param virX X location in virtual coordinate pixels
 * @param virY Y location in virtual coordinate pixels
 * @returns Pointer to item we double clicked on or nullptr if none.
*/
std::shared_ptr<Item> PlayingArea::DoubleClick(double virX, double virY)
{
	for (auto i = mItems.rbegin(); i != mItems.rend();  i++)
	{
		if ((*i)->DoubleClickTest(virX, virY))
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
 * Squashes the bug that is clicked on
 * @param bug the bug to be squashed
 */
void PlayingArea::Squash(std::shared_ptr<Item> bug) // NOT DONE!!!
{
	for (auto item : mItems)
	{
		if (item == bug)
		{
			SplatBug visitor;
			bug->Accept(&visitor); // only visit the hit item

			// only squash if the item isn't a program or is fat
			if (!visitor.IsProgram() && !visitor.IsFat())
			{
				// Swap out image - NOT DONE!!!


				if (visitor.IsFeature()) // May put code in VisitFeature() in the future
				{
					// if we hit a feature,
					mGame->GetScoreboard()->CalculateScore(false, true, false);
				}
				else // hit a garbage/null/redundancy bug
					mGame->GetScoreboard()->CalculateScore(true, false, false);
			}

		}
	}
}

/**
 * Bring up a dialog window to fix the fat bug code
 * @param bug the bug to fix
 */
void PlayingArea::FixCode(std::shared_ptr<Item> bug)
{
	for (auto item : mItems)
	{
		if (item == bug)
		{
			SplatBug visitor;
			bug->Accept(&visitor);

			if (visitor.IsFat())
			{
				// Open up dialog box
				// Create own dialog box class?
				// Need to work on squashing bug after fixing code.
				wxMessageBox(L"Sample text", L"Bug Squash IDE");
			}
		}
	}
}
