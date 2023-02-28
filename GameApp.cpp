/**
 * @file GameApp.cpp
 * @author Jacob
 */

#include "pch.h"
#include <MainFrame.h>
#include "GameApp.h"


bool GameApp::OnInit()
{
	if (!wxApp::OnInit())
		return false;

	// Add image type handlers
	wxInitAllImageHandlers();

	auto frame = new MainFrame();

	//To be uncommented when MainFrame is added to
//	frame->Initialize();
//	frame->Show(true);


	return true;
}
