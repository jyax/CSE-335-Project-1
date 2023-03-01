/**
 * @file Level.cpp
 * @author Jacob Meier
 */

#include "pch.h"
#include "Level.h"

//Working with the idea of a switch case, currently trying
//to figure out where the commandevent function would be binded from

//Update - currently bound in GameView class for Level0 only
//works on event as anticipated, trying to figure out what this class would
//do with that information, or if that's the appropriate place for the function
//For clarity: added Line 21, and Lines 24-26 to GameView

/**
 * Loads in the xml file based on what level number it is
 */
void Level::Load()
{
	switch(mNum)
	{
		case LevelNum::Zero:
			// fill in test stuff here first
			break;

		case LevelNum::One:
			break;

		case LevelNum::Two:
			break;
	}
}
