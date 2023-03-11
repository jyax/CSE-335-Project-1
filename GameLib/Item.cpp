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
 * @param game The current Game
 * @param filename The name of the file to display for this item
 */
Item::Item(Game *game, const std::wstring &filename) : mGame(game)
{
	mItemImage = make_shared<wxImage>(filename, wxBITMAP_TYPE_ANY);
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
 * @return true if hit.
 */
bool Item::HitTest(int x, int y)
{
	double wid = mItemImage->GetWidth();
	double hit = mItemImage->GetHeight();

	// Make x and y relative to the top-left corner of the bitmap image
	// Subtracting the center makes x, y relative to the image center
	// Adding half the size makes x, y relative to the image top corner
	double testX = x - GetX() + wid / 2;
	double testY = y - GetY() + hit / 2;

	// Test to see if x, y are in the image
	if (testX < 0 || testY < 0 || testX >= wid || testY >= hit)
	{
		// We are outside the image
		return false;
	}

	// Test to see if x, y are in the drawn part of the image
	// If the location is transparent, we are not in the drawn
	// part of the image
	return !mItemImage->IsTransparent((int)testX, (int)testY);
}

/**
 * Test to see if we double-clicked this object with a mouse.
 * @param x X position to test
 * @param y Y position to test
 * @return true if double-clicked
 */
bool Item::DoubleClickTest(int x, int y) // Implement only for fat bugs, return false otherwise
{
	return false;
}

/**
 * Draw this item
 * @param graphics graphics context to draw on
 */
void Item::Draw(shared_ptr<wxGraphicsContext> graphics)
{
	// only initialize when drawing required
	if(mItemBitmap.IsNull())
	{
		mItemBitmap = graphics->CreateBitmapFromImage(*mItemImage);
	}

	double wid = mItemImage->GetWidth();
	double hit = mItemImage->GetHeight();

	// Draws from top left corner
	graphics->DrawBitmap(mItemBitmap, int(GetX() - wid / 2), int(GetY() - hit / 2), wid, hit);
}
