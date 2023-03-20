/**
 * @file KillerBug.cpp
 * @author Alexandra Bannon
 */

#include "pch.h"
#include "KillerBug.h"
#include "Game.h"
#include "Bug.h"

/// The bug sprite image
const std::wstring KillerBugSpriteImageName = L"images/killer-bug.png";

/// Number of sprite images
const int KillerBugNumSpriteImages = 6;


/**
 * Constructor
 * @param area The playing area we are in
 */
KillerBug::KillerBug(PlayingArea *area) : Bug(area, KillerBugSpriteImageName, KillerBugNumSpriteImages)
{

}

/**
* Load attributes for a Killer Bug
 *
 * @param node The xml node we are loading attributes from
*/
void KillerBug::XmlLoad(wxXmlNode *node, std::shared_ptr<Program> program)
{
	Bug::XmlLoad(node, program);
}