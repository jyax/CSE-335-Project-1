/**
 * @file Program.cpp
 * @author Jacob Yax
 * @author Nicole Kuang
 * @author Gaya Kanagraj
 */

#include "pch.h"
#include <wx/graphics.h>
#include "Program.h"
#include "PlayingArea.h"

/// Program image filename
const std::wstring ProgramImage = L"images/laptop.png";

/// Program name font size
const int ProgramNameFontSize = 16;

/// Program font color
const wxColour ProgramFontColor = wxColour(*wxWHITE);



/**
 * Constructor
 * @param game The game we are in
 */
Program::Program(PlayingArea *area) : Item(area, ProgramImage)
{
    mPlayingArea = area;
}

/**
 * Draw Program onto playing area
 * @param graphics Graphics Context to draw on
 */
void Program::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{

    if(this->GetBitmap().IsNull())
    {
        this->SetBitmap(graphics->CreateBitmapFromImage(*this->GetImage()));
    }

    // Step 2: Get the dimensions of the image
    wxSize imageSize = this->GetImage()->GetSize();

    // Step 4: Draw the image at the calculated position
    graphics->DrawBitmap(this->GetBitmap(), GetX()-(imageSize.GetWidth() / 2), GetY()-(imageSize.GetHeight() / 2),
                         imageSize.GetWidth(), imageSize.GetHeight());

    graphics->SetFont(wxFont(ProgramNameFontSize, wxFONTFAMILY_SWISS,
                             wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD), ProgramFontColor);

    double width, length;
    graphics->GetTextExtent(mProgramName, &width, &length);
    graphics->DrawText(mProgramName, GetX() -(width/2), GetY() -(length/ 2));

}

/**
* Load attributes for a Program
 *
 * @param node The xml node we are loading attributes from
*/
void Program::XmlLoad(wxXmlNode *node, std::shared_ptr<Program> program)
{
    Item::XmlLoad(node, program);

    mProgramName = node->GetAttribute("name");

}
/**
 * Handle updates for animation
 * @param elapsed The time since the last update
 */
void Program::Update(double elapsed)
{
//    if (mPlayingArea != nullptr)
//        mPlayingArea->RemoveItem(GetX(), GetY());
}