/**
 * @file GarbageBug.cpp
 * @author Alexandra Bannon
 * @author Nicole Kuang
 * @author Jacob Yax
 */

#include "pch.h"
#include "GarbageBug.h"
#include "Game.h"
#include "Bug.h"

/// The bug sprite image
const std::wstring GarbageBugSpriteImageName = L"images/blue-maize-bug.png";

/// The splat image
const std::wstring GarbageBugSplatImageName = L"images/blue-maize-splat.png";

/// Number of sprite images
const int GarbageBugNumSpriteImages = 6;


/**
 * Constructor
 * @param area The playing area we are in
 */
GarbageBug::GarbageBug(PlayingArea *area) : Bug(area, GarbageBugSpriteImageName, GarbageBugNumSpriteImages)
{
	mSplatImage = std::make_shared<wxImage>(GarbageBugSplatImageName, wxBITMAP_TYPE_ANY);
}

/**
* Load attributes for a Garbage Bug
 *
 * @param node The xml node we are loading attributes from
*/
void GarbageBug::XmlLoad(wxXmlNode *node, std::shared_ptr<Program> program)
{
    Bug::XmlLoad(node, program);
}