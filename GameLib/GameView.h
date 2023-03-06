/**
 * @file GameView.h
 * @author Gaya Kanagaraj
 *
 * Class that implements the child window our program draws in.
 *
 * The window is a child of the main frame, which holds this
 * window, the menu bar, and the status bar.
 */
#ifndef PROJECT1_GAMEVIEW_H
#define PROJECT1_GAMEVIEW_H


#include "Game.h"

/**
 * Class that implements the child window our program draws in
 */
class GameView : public wxWindow{
private:
    Game mGame; ///<  the Game

public:
    void Initialize(wxFrame *mainFrame);

    void OnPaint(wxPaintEvent &event);
	void OnLevel0(wxCommandEvent &event);

    void
    AddLevelMenuOption(wxFrame *mainFrame, wxMenu *menu, int id, const std::wstring &text, const std::wstring &help);

    void AddShrinkOption(wxCommandEvent &event);

    void AddMenus(wxFrame *mainFrame, wxMenuBar *menuBar, wxMenu *fileMenu, wxMenu *viewMenu);

    void
    OnAddShrinkOption(wxFrame *mainFrame, wxMenu *menu, int id, const std::wstring &text, const std::wstring &help);
};


#endif //PROJECT1_GAMEVIEW_H
