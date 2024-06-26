/**
 * @file MainFrame.h
 * @author Jacob Yax
 *
 * Class for the main frame of the game
 */

#ifndef PROJECT1_MAINFRAME_H
#define PROJECT1_MAINFRAME_H

#include <wx/filehistory.h>
#include <wx/config.h>

class GameView;

/**
 * Class for the main frame of the game
 */
class MainFrame : public wxFrame{
private:
    void OnExit(wxCommandEvent &event);
    void OnAbout(wxCommandEvent &event);
	void OnClose(wxCloseEvent& event);

    GameView *mGameView = nullptr; ///< GameView class object

public:
    void Initialize();

};


#endif //PROJECT1_MAINFRAME_H
