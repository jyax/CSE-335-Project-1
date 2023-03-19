/**
 * @file NullBug.cpp
 * @author Alexandra Bannon
 * @author Nicole Kuang
 * @author Jacob Yax
 */

#include "pch.h"
#include "NullBug.h"

/// The bug sprite image
const std::wstring NullBugSpriteImageName = L"images/scarlet-gray-bug.png";

/// The splat image
const std::wstring NullBugSplatImageName = L"images/scarlet-gray-splat.png";

/// Number of sprite images
const int NullBugNumSpriteImages = 6;


/**
 * Constructor
 * @param area The playing area we are in
 */
NullBug::NullBug(PlayingArea *area) : Bug(area, NullBugSpriteImageName, NullBugNumSpriteImages)
{
	mSplatImage = std::make_shared<wxImage>(NullBugSplatImageName, wxBITMAP_TYPE_ANY);
}

/**
* Load attributes for null bug
*/
void NullBug::XmlLoad(wxXmlNode *node)
{
    Bug::XmlLoad(node);

}