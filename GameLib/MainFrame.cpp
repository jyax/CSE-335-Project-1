/**
 * @file MainFrame.cpp
 *
 * @author Jacob Yax
 * @author Gaya Kanagaraj
 */

#include "pch.h"
#include "MainFrame.h"
#include "GameView.h"

/**
 * Initialize the mainframe window
 */
void MainFrame::Initialize()
{
    Create(nullptr, wxID_ANY, L"Project 1: Bug Squash",
           wxDefaultPosition, wxSize( 930, 800 ));

    // Sizer for child windows
     auto sizer = new wxBoxSizer( wxVERTICAL );

     //Create view class object here
     mGameView = new GameView();
     mGameView ->Initialize(this);

     //Add to the sizer
    sizer->Add(mGameView , 1, wxEXPAND | wxALL );

    // Set sizer for game
    SetSizer( sizer );
    Layout();

    CreateStatusBar();
    auto menuBar = new wxMenuBar();
    auto fileMenu = new wxMenu();
    auto helpMenu = new wxMenu();
    auto viewMenu = new wxMenu();


    fileMenu->Append(wxID_EXIT, "&Exit\tAlt-X", "Quit this program");
    helpMenu->Append(wxID_ABOUT, "&About\tF!", "Show about dialog");


    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnAbout, this, wxID_ABOUT);
	Bind(wxEVT_CLOSE_WINDOW, &MainFrame::OnClose, this);

    menuBar->Append(fileMenu, L"&File");
    menuBar->Append(viewMenu, L"&View");
    mGameView->AddMenus(this, menuBar,fileMenu,viewMenu);
    menuBar->Append(helpMenu, L"&Help");

    SetMenuBar( menuBar );

}

/**
 * Exit menu option handler
 * @param event
 */
 void MainFrame::OnExit(wxCommandEvent &event)
 {
     Close(true);
 }

 /**
  * About menu option handler
  * @param event
  */
  void MainFrame::OnAbout(wxCommandEvent &event)
 {
      wxMessageBox(L"Project 1: Bug Squash created by Team Tick\nMembers: Ally Bannon, Gaya Kanagaraj,\nNicole Kuang, Jacob Meier, Jacob Yax",
                   L"About Project 1",
                   wxOK,
                   this);
 }

/**
* Handle a close event. Stop the animation and destroy this window.
* @param event The Close event
*/
void MainFrame::OnClose(wxCloseEvent& event)
{
	mGameView->Stop();
	Destroy();
}
