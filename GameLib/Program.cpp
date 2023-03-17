/**
 * @file Program.cpp
 * @author Jacob Yax
 * @author Nicole Kuang
 */

#include "pch.h"
#include <wx/graphics.h>
#include "Program.h"

/// Program image filename
const std::wstring ProgramImage = L"images/laptop.png";

/// Program name font size
const int ProgramNameFontSize = 22;

/// Program font color
const wxColour ProgramFontColor = wxColour(*wxWHITE);



/**
 * Constructor
 * @param game The game we are in
 */
Program::Program(PlayingArea *area) : Item(area, ProgramImage)
{

}

/**
 * Draw Program onto playing area
 * @param graphics Graphics Context to draw on
 */
void Program::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{

    if(mProgrammeBitmap.IsNull())
    {
        mProgrammeBitmap = graphics->CreateBitmapFromImage(*mProgrammeImage);
    }

    // Step 2: Get the dimensions of the image
    wxSize imageSize = mProgrammeImage->GetSize();

    // Step 4: Draw the image at the calculated position
    graphics->DrawBitmap(mProgrammeBitmap, GetX()-(imageSize.GetWidth() / 2), GetY()-(imageSize.GetHeight() / 2),
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
void Program::XmlLoad(wxXmlNode *node)
{
    Item::XmlLoad(node);
    mProgrammeImage = std::make_shared<wxImage>();
    mProgrammeImage->LoadFile(wxString(ProgramImage), wxBITMAP_TYPE_PNG);
    mProgramName = node->GetAttribute("name");
}