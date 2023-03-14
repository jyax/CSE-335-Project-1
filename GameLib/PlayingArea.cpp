/**
* @file PlayingArea.cpp
 * @author Gaya Kanagaraj
 *
 * Playing area for the game
 */

#include "pch.h"
#include <wx/graphics.h>
#include "PlayingArea.h"

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
    graphics->PopState();
}

/**
* Draw  scoreboard
* @param graphics
*/
void PlayingArea::DrawScoreBoard(std::shared_ptr<wxGraphicsContext> graphics)
{

    mScoreBoard.Draw(graphics);

}
/**
* Set level files  to the playing area
*
*/
void PlayingArea::SetLevelFile()
{
    mLevelZero->ReadLevel(Level0FileName);
    mLevelOne->ReadLevel(Level1FileName);
    mLevelTwo->ReadLevel(Level2FileName);
    mLevelThree->ReadLevel(Level3FileName);
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
        mCurrentLevel = make_shared<Level>(*mLevelZero);

    }
    else if (mLevelNum == 1)
    {
        mCurrentLevel = make_shared<Level>(*mLevelOne);

    }
    else if (mLevelNum == 2)
    {
        mCurrentLevel = make_shared<Level>(*mLevelTwo);

    }
    else if (mLevelNum == 3)
    {
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