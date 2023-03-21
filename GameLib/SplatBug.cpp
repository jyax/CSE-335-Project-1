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
#include "PlayingArea.h"
#include "Game.h"

/**
 * Visit a GarbageBug object
 * @param bug the garbage bug to visit
 */
void SplatBug::VisitGarbage(GarbageBug *bug)
{
	if (!bug->GetIsFatBug())
	{
		if (!bug->GetIsHit())
		{
			bug->SetIsHit(true);
			bug->GetArea()->GetGame()->GetScoreboard()->CalculateScore(true, false, false);
		}
	}
}

/**
 * Visit a NullBug object
 * @param bug the null bug to visit
 */
void SplatBug::VisitNull(NullBug *bug)
{
	if (!bug->GetIsFatBug())
	{
		if (!bug->GetIsHit())
		{
			bug->SetIsHit(true);
			bug->GetArea()->GetGame()->GetScoreboard()->CalculateScore(true, false, false);
		}
	}
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
	if (!feature->GetIsHit())
	{
		feature->SetIsHit(true);
		feature->GetArea()->GetGame()->GetScoreboard()->CalculateScore(false, true, false);
	}
}

/**
 * Visit a Program object
 * @param program the program to visit
 */
void SplatBug::VisitProgram(Program *program)
{

}
