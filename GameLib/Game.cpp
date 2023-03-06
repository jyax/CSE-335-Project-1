/**
 * @file Game.cpp
 *
 * @author Gaya Kanagaraj
 *
 *  Class that implements a simple Game with items we can manipulate
 */
#include "pch.h"
#include <wx/graphics.h>
#include "Game.h"



/// Shrinkable
const double ShrinkScale = 0.75;

/**
 * Constructor
*/
Game::Game(){}

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
        mScale = std::max(scaleX, scaleY);
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

    graphics->PopState();
}
