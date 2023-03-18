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
 * Handle updates in time of the bugs
 *
 * This is called before we draw and allows us to
 * move the bugs
 * @param elapsed Time elapsed since the class call
 */
void Bug::Update(double elapsed) // Change image swatch images here!!!
{
	//Currently commented out so you can exit the program


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


	// only initialize when drawing required
	if(this->GetBitmap().IsNull())
	{
		this->SetBitmap(graphics->CreateBitmapFromImage(*this->GetImage()));
	}

	double wid = this->GetImage()->GetWidth();
	double hit = this->GetImage()->GetHeight();
	double shift = hit/mFrames * (mIteration-1);

	wxRect rect = wxRect(this->GetX() - wid/2, this->GetX() - hit/2 - shift, wid, hit/mFrames);
	graphics->PushState();  // Save the graphics state
	graphics->Translate(0, shift);
	graphics->Clip(rect);

	// Draws from top left corner
	graphics->DrawBitmap(this->GetBitmap(), int(GetX() - wid / 2), int(GetY() - hit / 2), wid, hit);
	graphics->PopState();
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