/**
 * @file MainFrame.cpp
 *
 * @author Jacob Yax
 */

#include "pch.h"
#include "MainFrame.h"
//#include "GameView.h"
#include "ids.h"
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
     auto gameView = new GameView();
     gameView->Initialize(this);

     //Add to the sizer
    sizer->Add(gameView, 1, wxEXPAND | wxALL );

    // Set sizer for game
    SetSizer( sizer );
    Layout();

    auto menuBar = new wxMenuBar();
    auto fileMenu = new wxMenu();
    auto helpMenu = new wxMenu();
    auto levelMenu = new wxMenu();

    fileMenu->Append(wxID_EXIT, "&Exit\tAlt-X", "Quit this program");
    helpMenu->Append(wxID_ABOUT, "&About\tF!", "Show about dialog");
    levelMenu->Append(IDM_LEVELZERO, L"&Level 0", L"Go to Level 0");
    levelMenu->Append(IDM_LEVELONE, L"&Level 1", L"Go to Level 1");
    levelMenu->Append(IDM_LEVELTWO, L"&Level 2", L"Go to Level 2");
    levelMenu->Append(IDM_LEVELTHREE, L"&Level 3", L"Go to Level 3");

    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnAbout, this, wxID_ABOUT);

    menuBar->Append(fileMenu, L"&File");
    menuBar->Append(levelMenu, L"Levels");
    menuBar->Append(helpMenu, L"&Help");

    SetMenuBar( menuBar );

    // Do we need a status bar?
    //CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY);
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
