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
    random_device rd;
    mRandom.seed(rd());
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


    // draws the playing area, including all the game items
    mPlayingArea.DrawPlayingArea(graphics, Game::Width, Game::Height);
	
	// draw the scoreboard
	mScoreBoard.Draw(graphics);

    graphics->PopState();
}

/**
 * Test an x,y click location to see if clicked
 * on some item in the game.
 * @param x X location in screen coordinate pixels
 * @param y Y location in screen coordinate pixels
 * @returns Pointer to item we clicked on or nullptr if none.
*/
std::shared_ptr<Item> Game::SingleClick(int x, int y)
{
	// Calculate virtual coordinates from screen coordinates
	mXVirtual = (x - mXOffset) / mScale;
	mYVirtual = (y - mYOffset) / mScale;

	return mPlayingArea.SingleClick(mXVirtual, mYVirtual);
}

/**
 * Test an x,y click location to see if double clicked
 * on some item in the game.
 * @param x X location in screen coordinate pixels
 * @param y Y location in screen coordinate pixels
 * @returns Pointer to item we double clicked on or nullptr if none.
*/
std::shared_ptr<Item> Game::DoubleClick(int x, int y)
{
	mXVirtual = (x - mXOffset) / mScale;
	mYVirtual = (y - mYOffset) / mScale;

	return mPlayingArea.DoubleClick(mXVirtual, mYVirtual);
}

/**
 * Converts screen coords to virtual coords and sends over to Item::SetLocation()
 * @param item the item to drag
 * @param x x location in screen coordinates
 * @param y y location in screen coordinates
 */
void Game::SetLocation(std::shared_ptr<Item> item, int x, int y)
{
	mXVirtual = (x - mXOffset) / mScale;
	mYVirtual = (y - mYOffset) / mScale;

	item->SetLocation(mXVirtual, mYVirtual);
}

/**
 * Moves an item in the game to the front of the screen (end of list) when clicked on
 * @param item pointer to item clicked on
 */
void Game::MoveToFront(std::shared_ptr<Item> item)
{
	mPlayingArea.MoveToFront(item);
}

/**
 * Handle updates for animation
 * @param elapsed The time since the last update
 */
void Game::Update(double elapsed)
{
    mPlayingArea.Update(elapsed);
}
/**
 * Sets the level and passes the xmlfile to Level
 * @param level
 */
void Game::SetLevel(int level)
{

    if (mPlayingArea.GetLevelStart()) {
        mPlayingArea.Clear();
        mPlayingArea.LevelStart(false);
    }
    mPlayingArea.SetLevel(level);
    mPlayingArea.SetTextDuration(0.0);
    mPlayingArea.LevelStart(true);
}


/**
 * move an item around the screen when clicked
 *
 * @param item the item to be moved
*/
void Game::MoveItem(std::shared_ptr<Item> item)
{
	mPlayingArea.MoveItem(item);
}

/**
 * Send the bug over to PlayingArea to be squashed
 * @param bug the bug to squash
 */
void Game::Squash(std::shared_ptr<Item> bug)
{
	mPlayingArea.Squash(bug);
}

/**
 * Send the bug over to PlayingArea to be fixed
 * @param bug the bug to fix
 */
void Game::FixCode(std::shared_ptr<Item> bug)
{
	mPlayingArea.FixCode(bug);
}
