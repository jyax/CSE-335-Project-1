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
#include "DeleteBug.h"

using namespace std;

/// The scale difference in size between normal bugs and fat bugs
const double FatBugScale = 1.25;

/**
 * Constructor
 * @param area The playing area we are in
 * @param filename Filename for the image we use
 * @param frames number of frames the bug has
 */
Bug::Bug(PlayingArea *area, const std::wstring &filename, double frames) : Item(area, filename, frames)
{
	mFrames = frames;
    mArea = area;
}


/**
 * Handle updates in time of the bugs
 *
 * This is called before we draw and allows us to
 * move the bugs
 * @param elapsed Time elapsed since the class call
 */
void Bug::Update(double elapsed)
{

	if(!GetIsHit())
	{
		mStartMove += elapsed;
		if(mStartMove >= mStart)
		{
			mIteration = (mIteration + 1) % mFrames;

			SetLocation(GetX() + (elapsed * mSpeed * cos(GetAngle())), GetY() + (elapsed * mSpeed * sin(GetAngle())));

            if(DistanceTo(mDestination) < BugHitRange)
            {
				mArea->RemoveItem(this);

				// Increments score only for bad bugs
				DeleteBug visitor;
				Accept(&visitor);
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
	random_device rd;
	mRandom.seed(rd());
	int random = mRandom();
	if(GetIsHit()) // Draw the splat image
	{
		if(mSplatBitmap.IsNull())
			mSplatBitmap = graphics->CreateBitmapFromImage(*mSplatImage);

		double wid = mSplatImage->GetWidth();
		double hit = mSplatImage->GetHeight();
		graphics->PushState();
		graphics->Translate(GetX(), GetY());
		graphics->Rotate(GetAngle());
		graphics->DrawBitmap(mSplatBitmap, int(-wid / 2), int(-hit / 2), wid, hit);
		graphics->PopState();
	}
    else
	{
		// only initialize when drawing required
		if(this->GetBitmap().IsNull())
		{
			this->SetBitmap(graphics->CreateBitmapFromImage(*this->GetImage()));
		}
		graphics->PushState();

		double wid = this->GetImage()->GetWidth();
		double hit = this->GetImage()->GetHeight();
		double figureHit = hit / mFrames;

		graphics->Translate(GetX(), GetY());
		if(random > 100000000)
		{
			if(!test)
			{
				graphics->Rotate(GetAngle() + .15);
			}

			else
			{
				graphics->Rotate(GetAngle() - .15);
			}
		}
		else
		{
			test = !test;
			graphics->Rotate(GetAngle());
		}
		if(mIsFatBug)//this->GetIsFatBug())
		{
			graphics->Scale(FatBugScale, FatBugScale);

		}
		graphics->Clip(-wid / 2, -figureHit / 2, wid, figureHit);

		// Draws from top left corner
		graphics->DrawBitmap(this->GetBitmap(), int(-wid / 2), -(mIteration * figureHit) - (figureHit / 2), wid, hit);
		graphics->PopState();

	}


}

/**
* Load attributes for a Bug
 *
 * @param node The xml node we are loading attributes from
 * @param item destination for the bug
*/
void Bug::XmlLoad(wxXmlNode *node, std::shared_ptr<Item> item)
{
    Item::XmlLoad(node, item);

    int speed, start;
    node->GetAttribute(L"speed",L"0").ToInt(&speed);
    node->GetAttribute(L"start",L"0").ToInt(&start);

	mSpeed = (int)speed;
	mStart = (int)start;
    mDestination = item;
}

/**
 * Copy constructor
 * @param bug the bug to copy attributes from
 */
Bug::Bug(const Bug &bug) : Item(bug),mFrames(bug.mFrames),mArea(bug.mArea)
{
	mSpeed = bug.mSpeed;
    mDestination = bug.mDestination;
    mStart = bug.mStart;
    mStartMove = bug.mStartMove;
    mIsHit = bug.mIsHit;
    mSplatImage = bug.mSplatImage;
    mSplatBitmap = bug.mSplatBitmap;
}


/**
* angle between program and the bug
* @return double that is the bug's angle
*/
double Bug::GetAngle()
{
	double angleX = mDestination->GetX() - GetX();
	double angleY = mDestination->GetY() - GetY();

	return atan2(angleY, angleX);

}
/**
 * Destructor
 */
Bug::~Bug(){}

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
