/**
 * @file Bug.cpp
 * @author Alexandra Bannon
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