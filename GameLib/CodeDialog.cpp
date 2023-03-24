/**
 * @file CodeDialog.cpp
 * @author Alexandra Bannon
 */

#include "pch.h"
#include "CodeDialog.h"

/**
 * Constructor
 * @param window gameview in which the diolog box pops up
 * @param code text of the fatbug Code
 */
CodeDialog::CodeDialog(GameView *window, wxString code)
{
	//wxDialog dlg(this, -1, L"Bug Squash IDE");
	//auto sizer = new wxBoxSizer(wxVERTICAL);
	//wxTextCtrl text;
	//text.Create(&dlg, -1, visitor.GetCode());
	//auto button = new wxButton(&dlg, wxID_OK, L"OK");

	//sizer->Add(text);
	//sizer->Add(button);
	//SetSizer(sizer);
	// Open up dialog box containing fat bug code
	//wxMessageDialog dlg(this, mGrabbedItem->GetCode(), L"Bug Squash IDE");

	//dlg.AddMainButtonId(wxID_OK);
}
