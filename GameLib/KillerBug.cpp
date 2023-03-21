/**
 * @file KillerBug.cpp
 * @author Alexandra Bannon
 */

#include "pch.h"
#include "KillerBug.h"
#include "Game.h"
#include "Bug.h"

using namespace std;

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
/**
 * Draw this bug
 * @param graphics graphics context to draw on
 */
void KillerBug::Draw(shared_ptr<wxGraphicsContext> graphics)
{
    Bug::Draw(graphics);
}
/**
 * Handle updates in time of the bugs
 *
 * This is called before we draw and allows us to
 * move the bugs
 * @param elapsed Time elapsed since the class call
 */
void KillerBug::Update(double elapsed) // Change image swatch images here!!!
{
    Bug::Update(elapsed);
}