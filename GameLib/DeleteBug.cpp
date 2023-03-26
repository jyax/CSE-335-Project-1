/**
 * @file DeleteBug.cpp
 * @author Nicole Kuang
 */

#include "pch.h"
#include "DeleteBug.h"
#include "GarbageBug.h"
#include "NullBug.h"
#include "RedundancyBug.h"
#include "KillerBug.h"
#include "Game.h"

/**
 * Visit a GarbageBug object
 * @param bug the garbage bug to visit
 */
void DeleteBug::VisitGarbage(GarbageBug *bug)
{
	bug->GetArea()->GetGame()->GetScoreboard()->CalculateScore(false, false, true);
}

/**
 * Visit a NullBug object
 * @param bug the null bug to visit
 */
void DeleteBug::VisitNull(NullBug *bug)
{
	bug->GetArea()->GetGame()->GetScoreboard()->CalculateScore(false, false, true);
}

/**
 * Visit a RedundancyBug object
 * @param bug the redundancy bug to visit
 */
void DeleteBug::VisitRedundancy(RedundancyBug *bug)
{
	bug->GetArea()->GetGame()->GetScoreboard()->CalculateScore(false, false, true);
}

/**
 * Visit a Feature object
 * @param feature the feature 'bug' to visit
 */
void DeleteBug::VisitFeature(Feature *feature)
{

}

/**
 * Visit a Program object
 * @param program the program to visit
 */
void DeleteBug::VisitProgram(Program *program)
{

}

/**
 * Visit a KillerBug object
 * @param bug Killer bug to visit
 */
void DeleteBug::VisitKiller(KillerBug *bug)
{
	bug->GetArea()->GetGame()->GetScoreboard()->CalculateScore(false, false, true);
}
