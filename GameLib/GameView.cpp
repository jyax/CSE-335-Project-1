/**
 * @file GameView.cpp
 * @author Gaya Kanagaraj
 * @author Nicole Kuang
 */

#include "pch.h"
#include <wx/dcbuffer.h>
#include <wx/graphics.h>
#include "GameView.h"
#include "ids.h"

using namespace std;
/**
 * Constructor
 * @param mainFrame Pointer to wxFrame object, the main frame for the application
 */
void GameView::Initialize(wxFrame* mainFrame) {
    Create(mainFrame, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxFULL_REPAINT_ON_RESIZE);
    SetBackgroundStyle(wxBG_STYLE_PAINT);

    Bind(wxEVT_PAINT, &GameView::OnPaint, this);

	// Bind the mouse events
	Bind(wxEVT_LEFT_DOWN, &GameView::OnLeftDown, this);
	Bind(wxEVT_LEFT_UP, &GameView::OnLeftUp, this);
	Bind(wxEVT_MOTION, &GameView::OnMouseMove, this);
	Bind(wxEVT_LEFT_DCLICK, &GameView::OnLeftDouble, this);
}

/**
 * Plays Level 0 of the game
 * @param event mouse click event
 */
void GameView::OnLevel0 (wxCommandEvent &event)
{

}

/**
 * Paint event, draws the window.
 * @param event Paint event object
 */
void GameView::OnPaint(wxPaintEvent& event)
{

    // Create a double-buffered display context
    wxAutoBufferedPaintDC dc(this);

    // Clear the image to black
    wxBrush background(*wxBLACK);
    dc.SetBackground(background);
    dc.Clear();

    // Create a graphics context
    auto gc =
            std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create(dc));

    // Tell the game class to draw
    wxRect rect = GetRect();
    mGame.OnDraw(gc, rect.GetWidth(), rect.GetHeight());

}
/**
 * Add menus specific to the view
 * @param mainFrame The main frame that owns the menu bar
 * @param menuBar The menu bar to add menus to
 * @param fileMenu The file menu, so we can add to it if we wish
 * @param viewMenu The view menu, so we can add to it if we wish
 */
void GameView::AddMenus(wxFrame* mainFrame, wxMenuBar *menuBar, wxMenu* fileMenu, wxMenu* viewMenu)
{
    auto levelMenu = new wxMenu();

    // create a submenu for the shrink option
    auto shrinkSubMenu = new wxMenu();
    OnAddShrinkOption(mainFrame, shrinkSubMenu, wxITEM_CHECK, L"Shrink", L"Shrink the game area");

    // add the shrink submenu to the view menu
    viewMenu->Append(IDM_VIEW_SHRINK, L"Shrink", L"Shrink the game area");

    AddLevelMenuOption(mainFrame,levelMenu,IDM_LEVELZERO,L"Level 0",L"Play Level 0");
    AddLevelMenuOption(mainFrame,levelMenu,IDM_LEVELONE,L"Level 1",L"Play Level 1");
    AddLevelMenuOption(mainFrame,levelMenu,IDM_LEVELTWO,L"Level 2",L"Play Level 2");
    AddLevelMenuOption(mainFrame,levelMenu,IDM_LEVELTHREE,L"Level 3",L"Play Level 3");
    // append the menus to the menubar
    menuBar->Append(levelMenu, L"&Level");
}
/**
 * Append an option to a menu and bind it to the function GameView::OnAddLevelMenuOption
 *
 * @param mainFrame The MainFrame object that owns the menu
 * @param menu The Menu we are adding the option to
 * @param id The Menu option ID
 * @param text Text for the menu option
 * @param help Help for the menu option
 */
void GameView::AddLevelMenuOption(wxFrame *mainFrame, wxMenu *menu, int id,
                                  const std::wstring& text, const std::wstring& help)
{
    menu->Append(id, text, help);
    // all the level binds go here
    mainFrame->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnLevel0, this, id);
}
/**
* virtual pixels sets to true
*@param event
*/
void GameView::AddShrinkOption(wxCommandEvent& event)
{
    mGame.SetShrinked();
    Refresh();
}
/**
 * bind it to the function GaemView::AddShrikOption
 *
 * @param mainFrame The MainFrame object that owns the menu
 * @param menu The Menu we are adding the option to
 * @param id The Menu option ID
 * @param text Text for the menu option
 * @param help Help for the menu option
 */
void GameView::OnAddShrinkOption(wxFrame *mainFrame, wxMenu *menu, int id,
                                 const std::wstring& text, const std::wstring& help)
{
    mainFrame->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::AddShrinkOption,
                    this, IDM_VIEW_SHRINK);

}

/**
 * Handle the left mouse button down event
 * @param event left button down event
 */
void GameView::OnLeftDown(wxMouseEvent &event) // NOT FINISHED!!!
{
	auto item = mGame.SingleClick(event.GetX(), event.GetY());
	if (item != nullptr)
	{
		mGame.MoveToFront(item);

		// Function to destroy the bug (regular bugs only)

		Refresh();
	}
}

/**
* Handle the left mouse button up event
* @param event left button up event
*/
void GameView::OnLeftUp(wxMouseEvent &event)
{

}

/**
* Handle the mouse move event
* @param event mouse move event
*/
void GameView::OnMouseMove(wxMouseEvent &event)
{

}

/**
 * Handle the double click event
 * @param event left double click event
 */
void GameView::OnLeftDouble(wxMouseEvent &event) // NOT FINISHED!!!
{
	auto item = mGame.DoubleClick(event.GetX(), event.GetY());
	if (item != nullptr)
	{
		mGame.MoveToFront(item);

		// Function to open a dialog box with code and destroy the bug (fat bugs only)

		Refresh();
	}
}
