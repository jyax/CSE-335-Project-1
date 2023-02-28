/**
 * @file GameApp.cpp
 * @author Jacob Meier
 * @author Nicole Kuang
 */

#include "pch.h"
#include <MainFrame.h>
#include "GameApp.h"

/**
 * Initialize the game application
 * @return true if success, false otherwise
 */
bool GameApp::OnInit()
{
	if (!wxApp::OnInit())
		return false;
    // Add image type handlers
    wxInitAllImageHandlers();

    auto frame = new MainFrame();
    frame->Initialize();

    frame->SetFocus();
    frame->Raise();
    frame->Show(true);

	return true;
}
