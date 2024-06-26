/**
 * @file Item.cpp
 * @author Jacob Meier
 * @author Nicole Kuang
 * @author Alexandra Bannon
 * @author Gaya Kanagaraj
 * Items (program and bugs) for Game
 */

#include "pch.h"
#include <wx/graphics.h>
#include "Item.h"

using namespace std;

/**
 * Constructor
 * @param area The current playing area
 * @param filename The name of the file to display for this item
 * @param frame the number of images in the image file
 */
Item::Item(PlayingArea *area, const std::wstring &filename, double frame) : mArea(area)
{
	mItemImage = make_shared<wxImage>(filename, wxBITMAP_TYPE_ANY);
}

/**
 * Destructor
 */
Item::~Item(){}

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
void Item::Draw(shared_ptr<wxGraphicsContext> graphics){}

/**
 * Load in Item coordinates
 * @param node the node to load
 * @param item item (for bug) that will be its destination
 */
void Item::XmlLoad(wxXmlNode *node, std::shared_ptr<Item> item)
{
	long x, y;
	node->GetAttribute(L"x", L"0").ToLong(&x);
	node->GetAttribute(L"y", L"0").ToLong(&y);
	mX = (int)x;
	mY = (int)y;
}


/**
 * Copy constructor
 * @param original an Item reference to copy attributes from
 */
Item::Item(const Item &original)
{
    mArea = original.mArea;
}

/**
 * Constructor
 */
Item::Item(){}

/**
* Compute the distance from this to another item
* @param item Item we are computing the distance to
* @return Distance in pixels
*/
double Item::DistanceTo(std::shared_ptr<Item> item)
{
    auto dx = item->GetX() - GetX();
    auto dy = item->GetY() - GetY();
    return sqrt(dx * dx + dy * dy);
}
