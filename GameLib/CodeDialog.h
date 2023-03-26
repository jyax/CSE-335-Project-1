/**
 * @file CodeDialog.h
 * @author Alexandra Bannon
 *
 *
 */

#ifndef PROJECT1_GAMELIB_CODEDIALOG_H
#define PROJECT1_GAMELIB_CODEDIALOG_H


#include <wx/dcbuffer.h>
#include <wx/graphics.h>
#include <wx/dialog.h>
#include "GameView.h"

class CodeDialog : public wxDialog {
private:
	/// The text control used to contain fat bug code
	wxTextCtrl* mText = nullptr;

public:
	CodeDialog(wxWindow *window, wxString code);

	/// Default constructor
	CodeDialog();

	/// Copy constructor
	CodeDialog(const CodeDialog &);

	/// delete
	~CodeDialog();

	std::wstring GetEditedCode();
};

#endif //PROJECT1_GAMELIB_CODEDIALOG_H
