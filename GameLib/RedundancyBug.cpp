/**
 * @file RedundancyBug.cpp
 * @author Alexandra Bannon
 * @author Jacob Yax
 * @author Gaya Kanagaraj
 */

#include "pch.h"
#include "RedundancyBug.h"
#include "PlayingArea.h"
#include <stdlib.h>


using namespace std;

/// The bug base image
const std::wstring RedundancyFlyImageName = L"images/redundancy-fly-base.png";

/// The bug top image
const std::wstring RedundancyFlyTopImageName = L"images/redundancy-fly-top.png";

/// The left wing image
const std::wstring RedundancyFlyLeftWingImageName = L"images/redundancy-fly-lwing.png";

/// The right wing image
const std::wstring RedundancyFlyRightWingImageName = L"images/redundancy-fly-rwing.png";

/// The splat image
const std::wstring RedundancyFlySplatImageName = L"images/redundancy-fly-splat.png";

/// Wing flapping period in seconds
const double WingPeriod = 0.2;
/// FrameRate in seconds
const double FrameRate = 0.03;
///Frames for the wings
const int Frames = WingPeriod / FrameRate;

/// Starting rotation angle for wings in radians
const double WingRotateStart = 0.0;



/// End rotation angle for wings in radians
const double WingRotateEnd = 1.5;

/// How many sets of wings does this bug have?
const int NumberOfSetsOfWings = 4;

/// Number of virtual pixels between each of the wing sets
const int WingSetXOffset = 12;

/// X position relative to center of bug for the first (back) wing set
const int FirstWingSetX = -36;

/// Y position relative to center of bug for the right wings. The negative
/// of this is the Y position for the left wings.
const int WingSetY = 5;

/// frams for the splatter redundancy
const int Frame = 1;


/**
 * Constructor
 * @param area Area we are playing in
 */
RedundancyBug::RedundancyBug(PlayingArea *area) : Bug(area, RedundancyFlySplatImageName, Frame)
 {
    SetIsHit(false);
    SetMultiplied(false);
    mSplatImage = std::make_shared<wxImage>(RedundancyFlySplatImageName, wxBITMAP_TYPE_ANY);

    mRedundancyFlyBaseImage = make_unique<wxImage>(RedundancyFlyImageName, wxBITMAP_TYPE_ANY);

    mRedundancyFlyLeftWingImage = make_unique<wxImage>(RedundancyFlyLeftWingImageName, wxBITMAP_TYPE_ANY);

    mRedundancyFlyRightWingImage = make_unique<wxImage>(RedundancyFlyRightWingImageName, wxBITMAP_TYPE_ANY);

    mRedundancyFlyTopImage = make_unique<wxImage>(RedundancyFlyTopImageName, wxBITMAP_TYPE_ANY);
 }

 /**
  * Copy Constructor for the multiplying of the redundancy fly
  */
RedundancyBug::RedundancyBug(const RedundancyBug &original) : Bug(original)
{
    std::default_random_engine gen;
    std::normal_distribution<double> d(200.0, 30.0);
    int num = d(gen);
    double x = rand() % num - num;
    double y = pow(pow(num, 2) - pow(x, 2), 0.5);
    SetLocation(original.GetX() + x, original.GetY() + y);
    mHasMultiplied = original.mHasMultiplied;
    mRedundancyFlyLeftWingImage = make_unique<wxImage>(RedundancyFlyLeftWingImageName, wxBITMAP_TYPE_ANY);
    mRedundancyFlyRightWingImage = make_unique<wxImage>(RedundancyFlyRightWingImageName, wxBITMAP_TYPE_ANY);
    mRedundancyFlyTopImage = make_unique<wxImage>(RedundancyFlyTopImageName, wxBITMAP_TYPE_ANY);
    mRedundancyFlyBaseImage = make_unique<wxImage>(RedundancyFlyImageName, wxBITMAP_TYPE_ANY);
    mSplatImage = std::make_shared<wxImage>(RedundancyFlySplatImageName, wxBITMAP_TYPE_ANY);
}

/**
 * Draw function for Redundancy Bug
 * @param graphics graphics context to draw on
 */
void RedundancyBug::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{

    if(GetIsHit())
    {
        if(mSplatBitmap.IsNull()) { mSplatBitmap = graphics->CreateBitmapFromImage(*mSplatImage); }

        double width = mSplatImage->GetWidth();
        double height = mSplatImage->GetHeight();
        graphics->PushState();
        graphics->Translate(GetX(), GetY());
        graphics->Rotate(GetAngle());
        graphics->DrawBitmap(mSplatBitmap, int(-width / 2), int(-height / 2), width, height);
        graphics->PopState();
    }
    else {
        /// Handles if there currently isn't a set bitmap for all of the images
        if (mRedundancyFlyBaseBitmap.IsNull()) {
            mRedundancyFlyBaseBitmap = graphics->CreateBitmapFromImage(*mRedundancyFlyBaseImage);
        }
        if (mRedundancyFlyTopBitmap.IsNull()) {
            mRedundancyFlyTopBitmap = graphics->CreateBitmapFromImage(*mRedundancyFlyTopImage);
        }

        graphics->PushState();
        graphics->Translate(GetX(), GetY());
        graphics->Rotate(GetAngle());

        /// Drawing the base image (the body) of the fly
        wxSize baseSize = mRedundancyFlyBaseImage->GetSize();
        graphics->DrawBitmap(mRedundancyFlyBaseBitmap,
                             -baseSize.GetWidth() / 2,
                             -baseSize.GetHeight() / 2,
                             baseSize.GetWidth(), baseSize.GetHeight());

        /// Time to draw the fly wings!
        mRedundancyFlyLeftWingBitmap = graphics->CreateBitmapFromImage(*mRedundancyFlyLeftWingImage);
        mRedundancyFlyRightWingBitmap = graphics->CreateBitmapFromImage(*mRedundancyFlyRightWingImage);

        wxSize wingSize = mRedundancyFlyLeftWingImage->GetSize();
        double x = FirstWingSetX;
        double y = WingSetY;
        graphics->Translate(0,y);
        for (int i = 0; i < NumberOfSetsOfWings; i++)
        {
            graphics->PushState();
            graphics->Translate(x, 0);
            graphics->Rotate(mDirection * mCurrentAngle);
            graphics->DrawBitmap(mRedundancyFlyLeftWingBitmap,
                                 -(wingSize.GetWidth() / 2),
                                 -(wingSize.GetHeight() / 2),
                                 wingSize.GetWidth(), wingSize.GetHeight());
            graphics->PopState();
            x += WingSetXOffset;
        }

        x = FirstWingSetX;
        y = -WingSetY;
        graphics->Translate(0, y);
        for (int i = 0; i < NumberOfSetsOfWings; i++) {
            graphics->PushState();
            graphics->Translate(x, 0);
            graphics->Rotate(-mDirection * mCurrentAngle);
            graphics->DrawBitmap(mRedundancyFlyRightWingBitmap,
                                 -(wingSize.GetWidth() / 2),
                                 -(wingSize.GetHeight() / 2),
                                 wingSize.GetWidth(), wingSize.GetHeight());
            graphics->PopState();

            x += WingSetXOffset;
        }

        /// Draw Top image of the Fly
        wxSize topSize = mRedundancyFlyTopImage->GetSize();
        graphics->DrawBitmap(mRedundancyFlyTopBitmap,
                             -(topSize.GetWidth() / 2),
                             -(topSize.GetHeight() / 2),
                             topSize.GetWidth(), topSize.GetHeight());
        graphics->PopState();
    }
}

/**
 * Update function for wings
 * @param elapsed
 */
void RedundancyBug::Update(double elapsed)
{
    Bug::Update(elapsed);
    /// If current elapsed time is greater than the last wing period,
    /// we set it to a new wing period
    if(elapsed > (mCurrentWingPeriod + WingPeriod))
    {
        mCurrentWingPeriod += elapsed;
        Reverse();
    }
    double animation_smoothness = 1.5;
    double angle = (WingRotateEnd - WingRotateStart) / (Frames * animation_smoothness);


    if(mCurrentAngle > GetAngle() + WingRotateEnd)
    {
        mChangeDirection = true;
    }
    else if(mCurrentAngle < GetAngle() + WingRotateStart)
    {
        mChangeDirection = false;
    }

    if(mChangeDirection)
    {
        mCurrentAngle -= angle;
    } else
    {
        mCurrentAngle += angle;
    }
}

/**
 * Multiply Function when Redundancy Fly is clicked
 */
void RedundancyBug::Multiply()
{
    /// Creates Copies of the Redundancy Fly and adds it to the playing area
    int extraFlies = rand() % 3 + 3;
    while(extraFlies > 1)
    {
        auto bug = make_shared<RedundancyBug>(*this);
        GetArea()->Add(bug);
        extraFlies--;
    }

    /// RNG based on normal distribution for the placement for multiplying!
    std::default_random_engine gen;
    std::normal_distribution<double> d(200.0, 30.0);
    int num = d(gen);
    double x = rand() % num - num;
    double y = pow(pow(num, 2) - pow(x, 2), 0.5);
    if(x < 0) { y = y * - 1; }
    SetLocation(GetX() + x, GetY() + y);
}

/**
 * Reverse wing direction?
 */
void RedundancyBug::Reverse()
{
    mDirection = mDirection * -1;
}

/**
* Load attributes for a Redundancy
 *
 * @param node The xml node we are loading attributes from
 * @param item destination for the bug
*/
void RedundancyBug::XmlLoad(wxXmlNode *node, std::shared_ptr<Item> item)
{
    Bug::XmlLoad(node, item);
}