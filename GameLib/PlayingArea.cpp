/**
* @file PlayingArea.cpp
 * @author Gaya Kanagaraj
 * Playing area for the game
 */
#include "pch.h"
#include <wx/graphics.h>
#include "PlayingArea.h"
/**
 * Draws the starting text
 * @param graphics
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