/**
 * @file GarbageBug.cpp
 * @author Alexandra Bannon
 * @author Nicole Kuang
 * @author Jacob Yax
 * @author Gaya Kanagaraj
 */

#include "pch.h"
#include "GarbageBug.h"
#include "Game.h"
#include "Bug.h"

using namespace std;

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
 * @param item destination for the bug
*/
void GarbageBug::XmlLoad(wxXmlNode *node, std::shared_ptr<Item> item)
{
    Bug::XmlLoad(node, item);

	auto child = node->GetChildren();
	for (; child; child = child->GetNext())
	{
		auto name = child->GetName();
		if (name == L"code")
		{
			// Set the fat bug regex matcher
			this->SetIsFatBug(true);
			SetPass(child->GetAttribute(L"pass", L"0").ToStdWstring());

			// Set the fat bug's broken code
			auto code = child->GetChildren();
			SetCode(code->GetContent().ToStdWstring());
		}
	}
}

/**
 * Draw this bug
 * @param graphics graphics context to draw on
 */
void GarbageBug::Draw(shared_ptr<wxGraphicsContext> graphics)
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
void GarbageBug::Update(double elapsed) // Change image swatch images here!!!
{
    Bug::Update(elapsed);
}