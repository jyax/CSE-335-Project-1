/**
 * @file NullBug.cpp
 * @author Alexandra Bannon
 * @author Nicole Kuang
 * @author Jacob Yax
 * @author Gaya Kanagaraj
 */

#include "pch.h"
#include "NullBug.h"

using namespace std;

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
void NullBug::XmlLoad(wxXmlNode *node, std::shared_ptr<Program> program)
{
    Bug::XmlLoad(node, program);

	auto child = node->GetChildren();
	for (; child; child = child->GetNext())
	{
		auto name = child->GetName();
		if (name == L"code")
		{
			this->SetIsFatBug(true);
		}
	}
}
/**
 * Draw this bug
 * @param graphics graphics context to draw on
 */
void NullBug::Draw(shared_ptr<wxGraphicsContext> graphics)
{
    Bug::Draw(graphics);
}
/**
 * Handle updates in time of the bug
 *
 * This is called before we draw and allows us to
 * move the bugs
 * @param elapsed Time elapsed since the class call
 */
void NullBug::Update(double elapsed)
{
    Bug::Update(elapsed);
}