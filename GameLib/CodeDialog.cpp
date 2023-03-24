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
CodeDialog::CodeDialog(GameView *window, wxString code) : wxDialog(window, -1, L"Bug Squash IDE")
{
	auto sizer = new wxBoxSizer(wxVERTICAL);

	wxTextCtrl text;
	text.Create(this, -1, code);
	auto button = new wxButton(this, wxID_OK, L"OK");

	//sizer->Add(text);
	sizer->Add(button);
}
