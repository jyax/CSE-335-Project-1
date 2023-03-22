/**
 * @file ItemOrder.cpp
 * @author Nicole Kuang
 */

#include "pch.h"
#include "ItemOrder.h"

/**
 * Visit a GarbageBug object
 * @param bug the garbage bug to visit
 */
void ItemOrder::VisitGarbage(GarbageBug *bug)
{
	ItemVisitor::VisitGarbage(bug);
}

/**
 * Visit a NullBug object
 * @param bug the null bug to visit
 */
void ItemOrder::VisitNull(NullBug *bug)
{
	ItemVisitor::VisitNull(bug);
}

/**
 * Visit a RedundancyBug object
 * @param bug the redundancy bug to visit
 */
void ItemOrder::VisitRedundancy(RedundancyBug *bug)
{
	ItemVisitor::VisitRedundancy(bug);
}

/**
 * Visit a Feature object
 * @param feature the feature 'bug' to visit
 */
void ItemOrder::VisitFeature(Feature *feature)
{
	ItemVisitor::VisitFeature(feature);
}

/**
 * Visit a Program object
 * @param program the program to visit
 */
void ItemOrder::VisitProgram(Program *program)
{
	ItemVisitor::VisitProgram(program);
}
