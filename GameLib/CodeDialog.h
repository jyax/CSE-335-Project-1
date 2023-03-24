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
#include "GameView.h"

class CodeDialog : public wxDialog {
private:

public:
	CodeDialog(GameView *window, wxString code);

	/// Default constructor
	CodeDialog();

	/// Copy constructor
	CodeDialog(const CodeDialog &);

	/// delete
	~CodeDialog();
};

#endif //PROJECT1_GAMELIB_CODEDIALOG_H
