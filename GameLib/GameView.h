/**
 * @file GameView.h
 * @author Gaya Kanagaraj
 *
 *  Class that implements the child window our program draws in.
 *
 * The window is a child of the main frame, which holds this
 * window, the menu bar, and the status bar.
 */
#ifndef PROJECT1_GAMEVIEW_H
#define PROJECT1_GAMEVIEW_H


#include "Game.h"

class GameView : public wxWindow{
private:
    Game mGame; ///<  the Game

public:
    void Initialize(wxFrame *mainFrame);

    void OnPaint(wxPaintEvent &event);
	void OnLevel0(wxCommandEvent &event);
};


#endif //PROJECT1_GAMEVIEW_H
