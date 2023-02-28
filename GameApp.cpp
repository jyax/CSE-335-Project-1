/**
 * @file GameApp.cpp
 * @author Jacob
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

	return true;
}
