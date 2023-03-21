/**
 * @file FixBug.cpp
 * @author Nicole Kuang
 */

#include "pch.h"
#include "FixBug.h"
#include "GarbageBug.h"
#include "NullBug.h"

/**
 * Visit a GarbageBug object
 * @param bug the garbage bug to visit
 */
void FixBug::VisitGarbage(GarbageBug *bug)
{
	if (bug->GetIsFatBug())
	{
		if (!bug->GetIsHit())
		{
			mIsFat = true;
		}
	}
}

/**
 * Visit a NullBug object
 * @param bug the null bug to visit
 */
void FixBug::VisitNull(NullBug *bug)
{
	if (bug->GetIsFatBug())
	{
		if (!bug->GetIsHit())
		{
			mIsFat = true;
		}
	}
}

/**
 * Visit a RedundancyBug object
 * @param bug the redundancy bug to visit
 */
void FixBug::VisitRedundancy(RedundancyBug *bug)
{

}

/**
 * Visit a Feature object
 * @param feature the feature 'bug' to visit
 */
void FixBug::VisitFeature(Feature *feature)
{

}

/**
 * Visit a Program object
 * @param program the program to visit
 */
void FixBug::VisitProgram(Program *program)
{

}
