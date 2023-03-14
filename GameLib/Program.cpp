/**
 * @file Program.cpp
 *
 * @author Jacob Yax
 */

#include "pch.h"
#include "Program.h"

/// Program image filename
const std::wstring ProgramImage = L"images/laptop.png";

/// Program name font size
const int ProgramNameFontSize = 22;



/**
 * Constructor
 * @param game The game we are in
 */
Program::Program(Game* game) : Item(game, ProgramImage)
{
}
