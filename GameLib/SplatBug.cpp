/**
 * @file SplatBug.cpp
 * @author Nicole Kuang
 */

#include "pch.h"
#include "SplatBug.h"

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
	// Check if the game item is a garbage bug - PROBLEM HERE!!!
	//if (mItem.get() == bug)
	//{
		//mSquashed = bug;
	//}
}

/**
 * Visit a NullBug object
 * @param bug the null bug to visit
 */
void SplatBug::VisitNull(NullBug *bug)
{
	ItemVisitor::VisitNull(bug);
}

/**
 * Visit a RedundancyBug object
 * @param bug the redundancy bug to visit
 */
void SplatBug::VisitRedundancy(RedundancyBug *bug)
{
	ItemVisitor::VisitRedundancy(bug);
}

/**
 * Visit a Feature object
 * @param feature the feature 'bug' to visit
 */
void SplatBug::VisitFeature(Feature *feature)
{
	mIsFeature = true;
}

void SplatBug::Squash()
{
	// Change image

	// Increment score
}