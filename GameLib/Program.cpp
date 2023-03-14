/**
 * @file Program.cpp
 *
 * @author Jacob Yax
 */

#include "pch.h"
#include <wx/graphics.h>
#include "Program.h"

/// Program image filename
const std::wstring ProgramImage = L"laptop.png";

/// Program name font size
const int ProgramNameFontSize = 22;

/// Program font color
const wxColour ProgramFontColor = wxColour(0 ,0, 0);



/**
 * Constructor
 * @param game The game we are in
 */
Program::Program(Game* game) : Item(game, ProgramImage)
{
}

/**
 * Draw Program onto playing area
 * @param graphics Graphics Context to draw on
 */
void Program::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    this->Draw(graphics);
    graphics->SetFont(wxFont(ProgramNameFontSize, wxFONTFAMILY_SWISS,
                             wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD), ProgramFontColor);

    double width, length;
    graphics->GetTextExtent(mProgramName, &width, &length);
    graphics->DrawText(mProgramName, this->GetX() / 2, this->GetY() / 2);

}