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
CodeDialog::CodeDialog(wxWindow *window, wxString code) : wxTextEntryDialog	(window, "", L"Bug Squash IDE", code,  wxTE_MULTILINE)
{
	auto sizer = new wxBoxSizer(wxVERTICAL);
	//wxSizer* sizer =  CreateTextSizer(code, wxVERTICAL);

	wxTextCtrl text;
	text.Create(this, -1, code);
	auto button = new wxButton(this, wxID_OK, L"OK");

	//sizer->Add(text);
	sizer->Add(button);
}
