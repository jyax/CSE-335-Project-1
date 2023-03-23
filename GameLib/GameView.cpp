/**
 * @file GameView.cpp
 * @author Gaya Kanagaraj
 * @author Nicole Kuang
 * @author Jacob Meier
 */

#include "pch.h"
#include <wx/dcbuffer.h>
#include <wx/graphics.h>
#include "GameView.h"
#include "Level.h"
#include "ids.h"
#include "SplatBug.h"
#include "FixBug.h"
#include "PlayingArea.h"

using namespace std;

/// Frame duration in milliseconds
const double FrameDuration = 30.0;
/**
 * Constructor
 * @param mainFrame Pointer to wxFrame object, the main frame for the application
 */
void GameView::Initialize(wxFrame* mainFrame) {

	mTimer.SetOwner(this);
	mTimer.Start(FrameDuration);

    Create(mainFrame, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxFULL_REPAINT_ON_RESIZE);
    SetBackgroundStyle(wxBG_STYLE_PAINT);

    Bind(wxEVT_PAINT, &GameView::OnPaint, this);
	Bind(wxEVT_TIMER, &GameView::OnTimer, this);

	// Bind the mouse events
	Bind(wxEVT_LEFT_DOWN, &GameView::OnLeftDown, this);
	Bind(wxEVT_LEFT_UP, &GameView::OnLeftUp, this);
	Bind(wxEVT_MOTION, &GameView::OnMouseMove, this);
	Bind(wxEVT_LEFT_DCLICK, &GameView::OnLeftDouble, this);
    Bind(wxEVT_TIMER, &GameView::OnTimer, this);

    mTimer.SetOwner(this);

    mTimer.Start(FrameDuration);



    mStopWatch.Start();
}

/**
 * Plays Level 0 of the game
 * @param event mouse click event
 */
void GameView::OnLevel0 (wxCommandEvent &event)
{
    mGame.SetLevel(0);

}

/**
 * Plays Level 1 of the game
 * @param event mouse click event
 */
void GameView::OnLevel1 (wxCommandEvent &event)
{
    mGame.SetLevel(1);
}

/**
 * Plays Level 2 of the game
 * @param event mouse click event
 */
void GameView::OnLevel2 (wxCommandEvent &event)
{
    mGame.SetLevel(2);
}
/**
 * Plays Level 3 of the game
 * @param event mouse click event
 */
void GameView::OnLevel3 (wxCommandEvent &event)
{
    mGame.SetLevel(3);
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

    auto newTime = mStopWatch.Time();
    auto elapsed = (double)(newTime - mTime) * 0.001;
    mTime = newTime;

    mGame.Update(elapsed);


    // Create a graphics context
    auto gc =
            std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create(dc));

    // Tell the game class to draw
    wxRect rect = GetRect();
    mGame.OnDraw(gc, rect.GetWidth(), rect.GetHeight());



}
/**
 * Refreshes the screen
 * @param event
 */
void GameView::OnTimer(wxTimerEvent& event)
{
	//Currently commented out so you can exit the program
	Refresh();
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
    switch (id) {
        case IDM_LEVELZERO:
            mainFrame->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnLevel0, this, id);
            break;
        case IDM_LEVELONE:
            mainFrame->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnLevel1, this, id);
            break;
        case IDM_LEVELTWO:
            mainFrame->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnLevel2, this, id);
            break;
        case IDM_LEVELTHREE:
            mainFrame->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnLevel3, this, id);
            break;
    }
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
 * bind it to the function GameView::AddShrikOption
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
	mGrabbedItem = mGame.Click(event.GetX(), event.GetY());

	if (mGrabbedItem != nullptr)
	{
		if(!mGame.getEnableDrag())  //normal fucntion
		{
			mGame.MoveToFront(mGrabbedItem);

			// Function to destroy the bug (regular bugs only)
			SplatBug visitor;
			mGrabbedItem->Accept(&visitor);
			Refresh();
		}
		else   //for level 3 enable dragging items
		{
			mGame.MoveItem(mGrabbedItem);
		}

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

	// check if there is a current item
	if(mGrabbedItem != nullptr && mGrabbedItem->GetIsHit() != true)
	{
		// If an item is being moved, we only continue to
		// move it while the left button is down.
		if(event.LeftIsDown())
		{
			mGame.SetLocation(mGrabbedItem, event.GetX(), event.GetY());
		}
		else
		{
			// When the left button is released, we release the
			// item.
			mGrabbedItem = nullptr;
		}

		// Force the screen to redraw
		Refresh();
	}
}

/**
 * Handle the double click event
 * @param event left double click event
 */
void GameView::OnLeftDouble(wxMouseEvent &event) // NOT FINISHED!!!
{
	mGrabbedItem = mGame.Click(event.GetX(), event.GetY());
	if (mGrabbedItem != nullptr)
	{
		mGame.MoveToFront(mGrabbedItem);

		// Function to open a dialog box with code and destroy the bug (fat bugs only)
		FixBug visitor;
		mGrabbedItem->Accept(&visitor);

		if (visitor.GetIsFat())
		{
			Stop();
			mStopWatch.Pause();

			//wxDialog dlg(this, -1, L"Bug Squash IDE");
			//auto sizer = new wxBoxSizer(wxVERTICAL);
			//wxTextCtrl text;
			//text.Create(&dlg, -1, visitor.GetCode());
			//auto button = new wxButton(&dlg, wxID_OK, L"OK");
			//sizer->Add(text);
			//sizer->Add(button);
			//SetSizer(sizer);
			// Open up dialog box containing fat bug code
			wxMessageDialog dlg(this, L"Testing", L"Bug Squash IDE");

			//dlg.AddMainButtonId(wxID_OK);
			if (dlg.ShowModal() == wxID_OK)
			{
				visitor.CheckCode(); // Checks the edited code
				mTimer.Start();
				mStopWatch.Resume();
			}
		}
		Refresh();
	}
}
