/**
 * @file GarbageBug.cpp
 * @author Alexandra Bannon
 */

#include "pch.h"
#include "GarbageBug.h"
#include "Game.h"
#include "Bug.h"

/// The bug sprite image
const std::wstring GarbageBugSpriteImageName = L"blue-maize-bug.png";

/// The splat image
const std::wstring GarbageBugSplatImageName = L"blue-maize-splat.png";

/// Number of sprite images
const int GarbageBugNumSpriteImages = 5;


/**
 * Constructor
 * @param game The game we are in
 */
GarbageBug::GarbageBug(Game* game) : Bug(game, GarbageBugSpriteImageName)
{
}
