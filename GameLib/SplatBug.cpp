/**
 * @file SplatBug.cpp
 * @author Nicole Kuang
 */

#include "pch.h"
#include "SplatBug.h"

/**
 * Visit a GarbageBug object
 * @param bug the garbage bug to visit
 */
void SplatBug::VisitGarbage(GarbageBug *bug)
{
	ItemVisitor::VisitGarbage(bug);
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
	ItemVisitor::VisitFeature(feature);
}
