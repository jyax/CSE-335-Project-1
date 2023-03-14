/**
 * @file Bug.cpp
 * @author Alexandra Bannon
 * @author Nicole Kuang
 */

#include "pch.h"
#include "Bug.h"

/// Base Bug speed
const int BugSpeed = 40;


/**
 * Constructor
 * @param area The playing area we are in
 * @param filename Filename for the image we use
 */
Bug::Bug(PlayingArea *area, const std::wstring &filename) : Item(area, filename)
{
	mSpeed = BugSpeed;
}

/**
 * Handle updates in time of the bugs
 *
 * This is called before we draw and allows us to
 * move the bugs
 * @param elapsed Time elapsed since the class call
 */
void Bug::Update(double elapsed) // Change image swatch images here!!!
{
	Item::Update(elapsed);
}
