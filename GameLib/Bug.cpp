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
 * @param game The game we are in
 * @param filename Filename for the image we use
 */
Bug::Bug(Game *game, const std::wstring &filename) : Item(game, filename)
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
