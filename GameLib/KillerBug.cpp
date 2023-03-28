/**
 * @file KillerBug.cpp
 * @author Alexandra Bannon
 */

#include "pch.h"
#include "KillerBug.h"
#include "Game.h"
#include "Bug.h"
#include "SplatBug.h"

using namespace std;

/// The bug sprite image
const std::wstring KillerBugSpriteImageName = L"images/killer-bug.png";

/// The splat image
const std::wstring KillerBugSplatImageName = L"images/killer-bug-splat.png";

/// Number of sprite images
const int KillerBugNumSpriteImages = 6;


/**
 * Constructor
 * @param area The playing area we are in
 */
KillerBug::KillerBug(PlayingArea *area) : Bug(area, KillerBugSpriteImageName, KillerBugNumSpriteImages)
{
	SetSplatImage(std::make_shared<wxImage>(KillerBugSplatImageName, wxBITMAP_TYPE_ANY));
	mArea = area;

}

/**
* Load attributes for a Killer Bug
 *
 * @param node The xml node we are loading attributes from
 * @param item destination for the bug
*/
void KillerBug::XmlLoad(wxXmlNode *node, std::shared_ptr<Item> item)
{
	Bug::XmlLoad(node, item);
    mDestination = item;
}
/**
 * Draw this bug
 * @param graphics graphics context to draw on
 */
void KillerBug::Draw(shared_ptr<wxGraphicsContext> graphics)
{
	Bug::Draw(graphics);
}
void KillerBug::CalculateScore(KillerBug *item)
{
	this->GetArea()->GetGame()->GetScoreboard()->CalculateScore(false, false, true);
	AlreadyCalled = true;
}
/**
 * Handle updates in time of the bugs
 *
 * This is called before we draw and allows us to
 * move the bugs
 * @param elapsed Time elapsed since the class call
 */
void KillerBug::Update(double elapsed) // Change image swatch images here!!!
{

	/**if(this->DistanceTo(mDestination) <= (BugHitRange + 10))
	{
		SplatBug visitor;
		Accept(&visitor);
		mArea->RemoveDestination(mDestination);

	}

	else
	{
		Bug::Update(elapsed);
	}*/
	if(this->DistanceTo(mDestination) <= (BugHitRange + 10))
	{
		this->SetIsHit(true);
		if(!AlreadyCalled)
		{
			CalculateScore(this);
		}
		mArea->RemoveDestination(mDestination);

	}

	else
	{
		Bug::Update(elapsed);
	}
	//if(!this->GetIsHit())
	//	Bug::Update(elapsed);

	//else
	//{
	//	this->GetArea()->GetGame()->GetScoreboard()->CalculateScore(false, false, true);
	//}


}