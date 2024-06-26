/**
 * @file Level.cpp
 * @author Jacob Meier
 * @author Nicole Kuang
 * @author Gaya Kanagaraj
 * @author Jacob Yax
 */

#include "pch.h"
#include "Level.h"
#include "Program.h"
#include "NullBug.h"
#include "GarbageBug.h"
#include "Feature.h"
#include "RedundancyBug.h"
#include "Game.h"
#include "KillerBug.h"

using namespace std;

///  The time the text appears on screen
const double TextOnScreenDuration = 2.0;

/// Font size for the level name
const int LevelNameFontSize = 100;

/// Level name Font Color
const wxColour LevelNameFontColor = wxColour(27, 200, 255);

/// Level name X coord
const static int LevelNameX = 625;

/// Level name Y coord
const static int LevelNameY = 500;

/**
 * Constructor
 * @param area the playing area this level is part of
 */
Level::Level(PlayingArea* area) : mPlayingArea(area)
{
}

/**
 * Copy constructor
 * @param original level to be copied
 */
Level::Level(const Level &original)
{
    mNumOfProgramme = original.mNumOfProgramme;
    mNumOfBugs = original.mNumOfBugs;
    mPlayingArea = original.mPlayingArea;
    mIsStart = original.mIsStart;
    mType = original.mType;
    mNumofFeatures = original.mNumofFeatures;
    mTextDuration = original.mTextDuration;
}

/**
 * Read the level in the filename and passes the values
 * to the necessary functions
 * @param filename filename containing the level information
 */
void Level::ReadLevel(const std::wstring filename)
{
    wxXmlDocument xmlDoc;
    xmlDoc.Load(filename);

    if(!xmlDoc.Load(filename))
    {
        wxMessageBox(L"Unable to Load Level");
        return;
    }
    // get root of the xml doc - level value
    auto parent = xmlDoc.GetRoot();

    // Loop through child tags - outer loop for program
    auto child = parent->GetChildren();
    XmlBeginText(parent);
    for(; child; child=child->GetNext())
    {
		auto test = child->GetName().ToStdWstring();
		if(test == L"program")
		{
			XmlProgram(child);
		}

		if(test == L"feature")
		{
			XmlFeature(child);
		}

		auto itemValue = child->GetChildren();
		// inner loop for the bug and feature, code
		for(; itemValue; itemValue = itemValue->GetNext())
		{
			auto name = itemValue->GetName();
			if(name == L"bug")
			{
				XmlBug(itemValue);
			}
            else if(name == L"feature")
            {
                XmlFeature(itemValue);
            }
        }
    }

	// Copy temp list contents over to mItems, then empty those lists
	for (const auto & mTempProgram : mTempPrograms)
		mPlayingArea->Add(mTempProgram);

	mTempPrograms.clear();

	for (const auto & mTempBug : mTempBugs)
		mPlayingArea->Add(mTempBug);

	mTempBugs.clear();
}
/**
 * to draw begine text message
 * @param node node containing level info
 */
void Level::XmlBeginText(wxXmlNode *node)
{
    mType = node->GetAttribute("level");
}
/**
 * To read and draw Features
 * @param node node containing level info
 */
void Level::XmlFeature(wxXmlNode *node)
{
	mNumofFeatures++;
	mFeature = make_shared<Feature>(mPlayingArea);
	if(mFeature != nullptr)
	{
		mTempBugs.push_back(mFeature);
		mFeature->XmlLoad(node, mProgram);
	}
}
/**
 * To read and draw bugs
 * @param node node containing level info
 */
void Level::XmlBug(wxXmlNode *node)
{
    wxString type = node->GetAttribute("type");
    if (type.Cmp("nullbug") == 0 || type.Cmp("null") == 0)
    {
        mNumOfBugs++;
        auto item = make_shared<NullBug>(mPlayingArea);
        if(item != nullptr)
        {
			mTempBugs.push_back(item);
            item->XmlLoad(node, mProgram);
        }
    }
    else if (type.Cmp("garbage") == 0)
    {
        mNumOfBugs++;
         auto item = make_shared<GarbageBug>(mPlayingArea);
        if(item != nullptr)
        {
			mTempBugs.push_back(item);
            item->XmlLoad(node, mProgram);
            }
    }
    else if (type.Cmp("redundancy") == 0)
	{
		mNumOfBugs++;
		auto item = make_shared<RedundancyBug>(mPlayingArea);
		if(item != nullptr)
		{
			mTempBugs.push_back(item);
			item->XmlLoad(node, mProgram);
		}
	}
	else if(type.Cmp("assassin") == 0)
	{
		mNumOfBugs++;
		auto item = make_shared<KillerBug>(mPlayingArea);
		if(item != nullptr)
		{
			mTempBugs.push_back(item);
			item->XmlLoad(node, mFeature);
		}
	}

}

/**
 * Sets the time the text is visible onscreen
 * @param duration the duration that the text is present
 */
void Level::SetTextDuration(double duration)
{
	mTextDuration = duration;
	if( mTextDuration == 0.0){
		mIsStart = true;
	}
}

/**
 * Update the text in time
 *@param elapsed  time elapsed since last update
 */
void Level::Update(double elapsed)
{
    mTextDuration += elapsed;
    if (mIsStart && mState == State::STARTING)
    {
        if (mTextDuration > TextOnScreenDuration)
        {
            mIsStart = false;
            mTextDuration = 0;
            mState = State::PLAYING;
        }
    }
    else
    {
        if(mTextDuration > TextOnScreenDuration && mState == State::PLAYING)
        {
            mTextDuration = 0;
            mState = State::FINISHED;
        }
    }

}
/**
 * To read and draw Programme
 * @param node node containing level info
 */
void Level::XmlProgram(wxXmlNode *node)
{
    mNumOfProgramme ++;
    mProgram = make_shared<Program>(mPlayingArea);
    if(mProgram != nullptr)
    {
		mTempPrograms.push_back(mProgram);
        mProgram->XmlLoad(node, mProgram);
    }

}

/**
 * Destructor
 */
Level::~Level()
{
}

/**
 * Draws the level name onscreen before level start
 * @param graphics the graphics context to draw on
 */
void Level::DrawLevelName(std::shared_ptr<wxGraphicsContext> &graphics)
{
    if (mIsStart)
    {
        graphics->SetFont(wxFont(wxSize(0, LevelNameFontSize), wxFONTFAMILY_SWISS,
                                wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD), LevelNameFontColor);

        double width, length;
        graphics->GetTextExtent(wxString::Format(mType), &width, &length);
        graphics->DrawText(wxString::Format(mType), LevelNameX - (width/2), LevelNameY - (length/2));
    }
}

/**
 * Draws the level name onscreen when the level completes
 * @param graphics the graphics context to draw on
 */
void Level::DrawLevelFinish(std::shared_ptr<wxGraphicsContext> &graphics)
{
    if (!mIsStart)
    {
        graphics->SetFont(wxFont(wxSize(0, LevelNameFontSize), wxFONTFAMILY_SWISS,
                                 wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD), LevelNameFontColor);

        double width, length;
        graphics->GetTextExtent(wxString::Format("Level Completed"), &width, &length);
        graphics->DrawText(wxString::Format("Level Completed"), LevelNameX - (width/2), LevelNameY - (length/2));
    }
}
