/**
 * @file Game.cpp
 * @author Gaya Kanagaraj
 * @author Nicole Kuang
 */

#include "pch.h"
#include <wx/graphics.h>
#include "Game.h"
#include <wx/graphics.h>

using namespace std;

/// Shrinkable
const double ShrinkScale = 0.75;

/**
 * Constructor
*/
Game::Game()
{
    mPlayingArea.SetGame(this);
    mPlayingArea.SetLevelFile();
}

/**
 * Draw the game area
 * @param graphics The graphics context to draw on
 * @param width Width of the client window
 * @param height Height of the client window
 */
void Game::OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
    //
    // Automatic Scaling
    //
    auto scaleX = double(width) / double(Width);
    auto scaleY = double(height) / double(Height);
    mScale = std::min(scaleX, scaleY);

    if(mShrinked)
    {
        mScale *= ShrinkScale;
    }
    else{

        mScale = std::min(scaleX, scaleY);
    }

    mXOffset = (width - Width * mScale) / 2;
    mYOffset = (height - Height * mScale) / 2;

    graphics->PushState();

    graphics->Translate(mXOffset, mYOffset);
    graphics->Scale(mScale, mScale);


    //draws the playing area
    mPlayingArea.DrawPlayingArea(graphics, Game::Width, Game::Height);
    // draws the score
    mPlayingArea.DrawScoreBoard(graphics);

    if (mLevel)
    {
        for (auto item : mPlayingArea.GetItemList())
        {
            if (item != nullptr)
            {
                item->Draw(graphics);
            }
        }
    }
    graphics->PopState();
}

/**
 * Test an x,y click location to see if clicked
 * on some item in the game.
 * @param x X location in pixels
 * @param y Y location in pixels
 * @returns Pointer to item we clicked on or nullptr if none.
*/
std::shared_ptr<Item> Game::SingleClick(int x, int y)
{
	// Calculate virtual coordinates from screen coordinates
	mXVirtual = (x - mXOffset) / mScale;
	mYVirtual = (y - mYOffset) / mScale;

	for (auto i = mItems.rbegin(); i != mItems.rend();  i++)
	{
		if ((*i)->HitTest(mXVirtual, mYVirtual))
		{
			return *i;
		}
	}

	return nullptr;
}

/**
 * Test an x,y click location to see if double clicked
 * on some item in the game.
 * @param x X location in pixels
 * @param y Y location in pixels
 * @returns Pointer to item we double clicked on or nullptr if none.
*/
std::shared_ptr<Item> Game::DoubleClick(int x, int y)
{
	mXVirtual = (x - mXOffset) / mScale;
	mYVirtual = (y - mYOffset) / mScale;

	for (auto i = mItems.rbegin(); i != mItems.rend();  i++)
	{
		if ((*i)->DoubleClickTest(mXVirtual, mYVirtual))
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
void Game::MoveToFront(std::shared_ptr<Item> item)
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
 * Handle updates for animation
 * @param elapsed The time since the last update
 */
void Game::Update(double elapsed)
{

//    for (auto item : mPlayingArea.GetItemList())
//    {
//        item->Update(elapsed);
//    }
}
/**
 * Sets the level and passes the xmlfile to Level
 * @param level
 */
void Game::SetLevel(int level)
{
    mPlayingArea.SetLevel(level);
}