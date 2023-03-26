/**
 * @file CodeDialog.h
 * @author Alexandra Bannon
 * @author Nicole Kuang
 *
 * Dialog box for the fat bag when double-clicked
 */

#ifndef PROJECT1_GAMELIB_CODEDIALOG_H
#define PROJECT1_GAMELIB_CODEDIALOG_H


#include <wx/dcbuffer.h>
#include <wx/graphics.h>
#include <wx/dialog.h>
#include "GameView.h"

/**
 * Dialog box for the fat bug when double-clicked
 */
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
