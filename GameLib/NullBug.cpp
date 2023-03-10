/**
 * @file NullBug.cpp
 * @author Alexandra Bannon
 */

#include "pch.h"
#include "NullBug.h"

/// The bug sprite image
const std::wstring NullBugSpriteImageName = L"scarlet-gray-bug.png";

/// The splat image
const std::wstring NullBugSplatImageName = L"scarlet-gray-splat.png";

/// Number of sprite images
const int NullBugNumSpriteImages = 6;


/**
 * Constructor
 * @param game The game we are in
 */
NullBug::NullBug(Game* game) : Bug(game, NullBugSpriteImageName)
{
}