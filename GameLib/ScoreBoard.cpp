/**
 * @file ScoreBoard.cpp
 * @author Gaya Kanagaraj
 *
 * Class defines the score board
 */

#include "pch.h"
#include <wx/graphics.h>
#include "ScoreBoard.h"


/// Score font size to use
const int ScoreSize = 85;

/// Lable for score font size to use
const int LabelSize = 40;

/// The font color to use
const wxColour FontColor = wxColour(0, 200, 200);

/// Left score X location. The right score is
/// the width minus this value.
const int LeftScoreX = 150;

/// Score Y location
const int ScoreY = 20;

/// Score label Y location
const int ScoreLabelY = 100;

/** default construct that constructs the scoreboard */
ScoreBoard::ScoreBoard(){}

/**
* Add score to the scoreboard
 *  score score to add
 *  true if it is new level else faise
*/
void ScoreBoard::CalculateScore(bool fixed, bool oops, bool missed)
{
    if(oops)
    {
        mOops += 1;
    }
    if (missed)
    {
        mMissed += 1;
    }
    if(fixed)
    {
        mFixed += 1;
    }
}
/**
* Getcurrent score returns the current score
* @return int current score
*/
int ScoreBoard::GetOopsScore()
{
    return mOops;
}
/**
* GetTotalScore returns the total score
* @return int fixed score
*/
int ScoreBoard::GetFixedScore()
{
    return mFixed;
}
/**
* GetTotalScore returns the total score
* @return int missed score
*/
int ScoreBoard::GetMissedScore()
{
    return mMissed;
}
/**
 * draw scorebaord using the score label and score font size and color sonstants
 * @param graphics
 */
void ScoreBoard::Draw(std::shared_ptr<wxGraphicsContext> graphics) {
    // Set the font size and color for the scores
    graphics->PushState();
    wxFont font(wxSize(0,ScoreSize),wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    // Set the font size and color for the scores
    graphics->SetFont(font, FontColor);

    double wid, len;

    graphics->GetTextExtent(wxString::Format(wxT("%d"), mFixed), &wid, &len);
    graphics->DrawText(wxString::Format(wxT("%d"), mFixed), LeftScoreX - (wid/2), ScoreY);

    graphics->GetTextExtent(wxString::Format(wxT("%d"), mMissed), &wid, &len);
    graphics->DrawText(wxString::Format(wxT("%d"), mMissed), LeftScoreX + 450 - (wid/2), ScoreY);

    graphics->GetTextExtent(wxString::Format(wxT("%d"), mOops), &wid, &len);
    graphics->DrawText(wxString::Format(wxT("%d"), mOops), 1200-LeftScoreX-(wid/2), ScoreY);

    wxFont font1(wxSize(0,LabelSize),wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    graphics->SetFont(font1, FontColor);


    graphics->GetTextExtent(wxString::Format(L"Fixed"), &wid, &len);
    graphics->DrawText(wxString::Format(L"Fixed"), LeftScoreX - (wid/2), ScoreLabelY);

    graphics->GetTextExtent(wxString::Format(L"Missed"), &wid, &len);
    graphics->DrawText(wxString::Format(L"Missed"), LeftScoreX + 450 - (wid/2), ScoreLabelY);

    graphics->GetTextExtent(wxString::Format(L"Oops"), &wid, &len);
    graphics->DrawText(wxString::Format(L"Oops"), 1200 - LeftScoreX - (wid/2), ScoreLabelY);

    graphics->PopState();
}
/**
* Resets the score board
*/
void ScoreBoard::ResetScoreBoard()
{
    mFixed = 0;
    mMissed = 0;
    mOops = 0;
}
