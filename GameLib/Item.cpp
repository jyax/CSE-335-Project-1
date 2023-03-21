/**
 * @file Item.cpp
 * @author Jacob Meier
 * @author Nicole Kuang
 */

#include "pch.h"
#include <wx/graphics.h>
#include "Item.h"

using namespace std;

/**
 * Constructor
 * @param area The current playing area
 * @param filename The name of the file to display for this item
 */
Item::Item(PlayingArea *area, const std::wstring &filename) : mArea(area)
{
	mItemImage = make_shared<wxImage>(filename, wxBITMAP_TYPE_ANY);
}

Item::Item(PlayingArea *area) : mArea(area)
{

}


/**
 * Destructor
 */
Item::~Item()
{
}

/**
 * Test to see if we hit this object with a mouse.
 * @param x X position to test
 * @param y Y position to test
 * @return false
 */
bool Item::HitTest(double x, double y)
{
	return false;
}

/**
 * Draw this item
 * @param graphics graphics context to draw on
 */
void Item::Draw(shared_ptr<wxGraphicsContext> graphics)
{
//	// only initialize when drawing required
//	if(mItemBitmap.IsNull())
//	{
//		mItemBitmap = graphics->CreateBitmapFromImage(*mItemImage);
//	}
//
//	double wid = mItemImage->GetWidth();
//	double hit = mItemImage->GetHeight();
//
//	// Draws from top left corner
//	graphics->DrawBitmap(mItemBitmap, int(GetX() - wid / 2), int(GetY() - hit / 2), wid, hit);
}

/**
 * Load in Item coordinates
 * @param node the node to load
 */
void Item::XmlLoad(wxXmlNode *node, std::shared_ptr<Program> program)
{
	long x, y;
	node->GetAttribute(L"x", L"0").ToLong(&x);
	node->GetAttribute(L"y", L"0").ToLong(&y);
	mX = (int)x;
	mY = (int)y;
}

/**
 * Copy constructor
 */
Item::Item(const Item &)
{

}

/**
 * Constructor
 */
Item::Item()
{

}
