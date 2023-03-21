/**
 * @file FixBug.cpp
 * @author Nicole Kuang
 */

#include "pch.h"
#include "FixBug.h"
#include "GarbageBug.h"
#include "NullBug.h"
#include "Game.h"

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
			mBug = bug;
			mCode = mBug->GetCode();
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
			mBug = bug;
			mCode = mBug->GetCode();
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

/**
 * Checks the fat bug code to see if it is fixed.
 *
 * If so, splats the bug and increments score
 */
void FixBug::CheckCode()
{
	if (mBug->CheckCode())
	{
		mBug->SetIsHit(true);
		mBug->GetArea()->GetGame()->GetScoreboard()->CalculateScore(true, false, false);
	}
}
