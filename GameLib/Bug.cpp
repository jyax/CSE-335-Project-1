/**
 * @file Bug.cpp
 * @author Alexandra Bannon
 * @author Nicole Kuang
 * @author Jacob Yax
 */

#include "pch.h"
#include "Bug.h"
#include <wx/graphics.h>

using namespace std;

/// Base Bug speed
const int BugSpeed = 40;

/// The range from the center of the bug to see if hit or not
const int BugHitRange = 50;

/**
 * Constructor
 * @param area The playing area we are in
 * @param filename Filename for the image we use
 * @param frames number of frames the bug has
 */
Bug::Bug(PlayingArea *area, const std::wstring &filename, double frames) : Item(area, filename)
{
	//mSpeed = BugSpeed;
	mFrames = frames;
	//mStopWatch.Start();
}

/**
 * Constructor for Redundancy Fly
 *
 * @param area The playing area this is in
 */
Bug::Bug(PlayingArea *area) : Item(area)
{
}

/**
 * Handle updates in time of the bugs
 *
 * This is called before we draw and allows us to
 * move the bugs
 * @param elapsed Time elapsed since the class call
 */
void Bug::Update(double elapsed) // Change image swatch images here!!!
{
	//Currently commented out so you can exit the program

	if (!GetIsHit())
		SetLocation(GetX() + elapsed * mSpeed * .1, GetY() + elapsed * mSpeed * .1);


	//mIteration does 'something' for animation. I had it incrementing with modulo to loop
	//i.e. mIteration = (int(mIteration)+1) % 5;
	//but that only sort of worked. I  also think the null bug frames/rectangles need to be adjusted
	//as they might be too big - a weird clipping happens to them
}

/**
 * Hit test x,y to see if they are clicking on this bug.
 * @param x X location in pixels
 * @param y Y location in pixels
 * @return true if clicked on bug
 */
bool Bug::HitTest(double x, double y)
{
	double dx = x - GetX();
	double dy = y - GetY();

	return sqrt(dx * dx + dy * dy) < BugHitRange;
}

/**
 * Draw this item
 * @param graphics graphics context to draw on
 */
void Bug::Draw(shared_ptr<wxGraphicsContext> graphics)
{
	if (GetIsHit()) // Draw the splat image
	{
		if (mSplatBitmap.IsNull())
			mSplatBitmap = graphics->CreateBitmapFromImage(*mSplatImage);

		double wid = mSplatImage->GetWidth();
		double hit = mSplatImage->GetHeight();

		graphics->DrawBitmap(mSplatBitmap, int(GetX() - wid / 2), int(GetY() - hit / 2), wid, hit);
	} else
	{
		// only initialize when drawing required
		if(this->GetBitmap().IsNull())
		{
			this->SetBitmap(graphics->CreateBitmapFromImage(*this->GetImage()));
		}

		double wid = this->GetImage()->GetWidth();
		double hit = this->GetImage()->GetHeight();
		double figureHit = hit/mFrames;
		double shift = figureHit * (mIteration-1);

		wxRect rect = wxRect( - wid/2,  - hit/2 - shift, wid, figureHit);
		graphics->PushState();  // Save the graphics state

		graphics->Translate(GetX()/2, GetY());
		graphics->Rotate(0.5);

		if (mIsFatBug)
		{
			graphics->Scale(1.25, 1.25);
		}

		graphics->Translate(0, hit/2 - figureHit/2 - shift);
		graphics->Clip(rect);


		// Draws from top left corner
		graphics->DrawBitmap(this->GetBitmap(), int(- wid / 2), int(- hit / 2), wid, hit);
		graphics->PopState();
	}


}





/**
* Load attributes for a Bug
 *
 * @param node The xml node we are loading attributes from
*/
void Bug::XmlLoad(wxXmlNode *node)
{
    Item::XmlLoad(node);

    int speed, start;
    node->GetAttribute(L"speed",L"0").ToInt(&speed);
    node->GetAttribute(L"start",L"0").ToInt(&start);

	mSpeed = (int)speed;
	mStart = (int)start;




}