/**
 * @file Bug.cpp
 * @author Alexandra Bannon
 * @author Nicole Kuang
 */

#include "pch.h"
#include "Bug.h"

/// Base Bug speed
const int BugSpeed = 40;

/// The range from the center of the bug to see if hit or not
const int BugHitRange = 50;

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

/**
 * Hit test x,y to see if they are clicking on this bug.
 * @param x X location in pixels
 * @param y Y location in pixels
 * @return true if clicked on bug
 */
bool Bug::HitTest(double x, double y)
{
	double dx = x - GetX();
	double dy = y - GetY();

	return sqrt(dx * dx + dy * dy) < BugHitRange;
}
