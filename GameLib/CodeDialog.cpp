/**
 * @file CodeDialog.cpp
 * @author Alexandra Bannon
 * @author Nicole Kuang
 */

#include "pch.h"
#include "CodeDialog.h"

/**
 * Constructor
 * @param window gameview in which the diolog box pops up
 * @param code text of the fatbug Code
 */
CodeDialog::CodeDialog(wxWindow *window, wxString code) : wxDialog	(window, -1, L"Bug Squash IDE")
{
	auto sizer = new wxBoxSizer(wxVERTICAL);

	mText = new wxTextCtrl( this, wxID_ANY, code, wxDefaultPosition, wxSize(400, 300), wxTE_MULTILINE );
	sizer->Add( mText, 0, wxALIGN_CENTER|wxALL, 5 );

	auto button = new wxButton( this, wxID_OK, L"OK", wxDefaultPosition, wxDefaultSize, 0 );
	sizer->Add( button, 0, wxALIGN_CENTER|wxALL, 5 );


	this->SetSizer( sizer );
	this->Layout();
	sizer->Fit( this );

	this->Centre( wxBOTH );
}

/**
 * Destructor
 */
CodeDialog::~CodeDialog()
{

}

/**
 * Get the contents within the textctrl
 * @return the contents of the textctrl as a wstring
 */
std::wstring CodeDialog::GetEditedCode()
{
	return mText->GetValue().ToStdWstring();
}