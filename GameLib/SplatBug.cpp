/**
 * @file SplatBug.cpp
 * @author Nicole Kuang
 */

#include "pch.h"
#include "SplatBug.h"
#include "Feature.h"
#include "GarbageBug.h"
#include "NullBug.h"
#include "RedundancyBug.h"

/**
 * Constructor
 * @param item the game item clicked on
 */
/*SplatBug::SplatBug(std::shared_ptr<Item> item)
{
	mItem = item;
}*/

/**
 * Visit a GarbageBug object
 * @param bug the garbage bug to visit
 */
void SplatBug::VisitGarbage(GarbageBug *bug)
{
	bug->SetIsHit(true);

	if (bug->GetIsFatBug())
		mIsFat = true;
}

/**
 * Visit a NullBug object
 * @param bug the null bug to visit
 */
void SplatBug::VisitNull(NullBug *bug)
{
	bug->SetIsHit(true);

	if (bug->GetIsFatBug())
		mIsFat = true;
}

/**
 * Visit a RedundancyBug object
 * @param bug the redundancy bug to visit
 */
void SplatBug::VisitRedundancy(RedundancyBug *bug)
{
    if(bug->GetMultiplied())
    {
        bug->SetIsHit(true);
    }
    else
    {
        bug->SetMultiplied(true);
        bug->Multiply();
    }
}

/**
 * Visit a Feature object
 * @param feature the feature 'bug' to visit
 */
void SplatBug::VisitFeature(Feature *feature)
{
	mIsFeature = true;
	feature->SetIsHit(true);
}

/**
 * Visit a Program object
 * @param program the program to visit
 */
void SplatBug::VisitProgram(Program *program)
{
	mIsProgram = true;
}

void SplatBug::Squash()
{
	// Change image

	// Increment score
}
