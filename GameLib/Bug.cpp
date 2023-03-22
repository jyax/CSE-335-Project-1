/**
 * @file Bug.cpp
 * @author Alexandra Bannon
 * @author Nicole Kuang
 * @author Jacob Yax
 * @author Gaya Kanagaraj
 * @author Jacob Meier
 */

#include "pch.h"
#include "Bug.h"
#include <wx/graphics.h>
#include <wx/regex.h>
#include "Program.h"
#include "PlayingArea.h"

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
    mArea = area;
}

/**
 * Constructor for Redundancy Fly
 *
 * @param area The playing area this is in
 */
Bug::Bug(PlayingArea *area, const std::wstring &filename) : Item(area, filename)
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

	if (!GetIsHit())
    {
        mStartMove += elapsed;
        if(mStartMove >= mStart)
		{
			SetLocation(GetX() + (elapsed * mSpeed * cos(GetAngle())), GetY() + (elapsed * mSpeed * sin(GetAngle())));

            if(DistanceTo(mDestination) < BugHitRange)
            {
                mArea->RemoveItem(this);
            }
		}
    }
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
	}
    else
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

		graphics->Translate(GetX(), GetY());
		graphics->Rotate(GetAngle());

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
void Bug::XmlLoad(wxXmlNode *node, std::shared_ptr<Program> program)
{
    Item::XmlLoad(node, program);

    int speed, start;
    node->GetAttribute(L"speed",L"0").ToInt(&speed);
    node->GetAttribute(L"start",L"0").ToInt(&start);

	mSpeed = (int)speed;
	mStart = (int)start;
    mDestination = program;
}

/**
 * Copy constructor
 */
Bug::Bug(const Bug &bug) : Item(bug)
{
	mSpeed = bug.mSpeed;
    mDestination = bug.mDestination;
    mStart = bug.mStart;
    mStartMove = bug.mStartMove;
    mIsHit = bug.mIsHit;
    mSplatImage = bug.mSplatImage;
    mSplatBitmap = bug.mSplatBitmap;
	//would mStart need to be different if this for redundancy bugs only?
	//mStart = 0; ?
}

/**
 * Constructor
 */
Bug::Bug()
{

}
/**
* angle between program and the bug
* @return double angel
*/
double Bug::GetAngle()
{
	double angleX = mDestination->GetX() - GetX();
	double angleY = mDestination->GetY() - GetY();

	return atan2(angleY, angleX);

}
Bug::~Bug()
{

}

/**
 * Check if the fat bug code has been fixed using regex
 * @return true if fixed, false otherwise
 */
bool Bug::CheckCode()
{
	wxRegEx phrase;
	if (phrase.Compile(mPass))
		return phrase.Matches(mCode);

	return false;
}
