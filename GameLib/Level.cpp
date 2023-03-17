/**
 * @file Level.cpp
 * @author Jacob Meier
 * @author Nicole Kuang
 * @author Gaya Kanagaraj
 */

#include "pch.h"
#include "Level.h"
#include "Program.h"
#include "NullBug.h"
#include "GarbageBug.h"
#include "Feature.h"
#include "RedundancyBug.h"
#include "Game.h"

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
 * @param game the game this is a part of
 */
Level::Level(PlayingArea* playingArea) : mPlayingArea(playingArea)
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
 * @param filename
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
    //XmlBeginText(parent);

    // Loop through child tags - outer loop for program
    auto child = parent->GetChildren();
    XmlBeginText(parent);
    for(; child; child=child->GetNext())
    {
        XmlProgram(child);
        auto itemValue = child->GetChildren();
        // inner loop for the bug and feature, code
        for(; itemValue; itemValue=itemValue->GetNext())
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
}
/**
 * to draw begine text message
 * @param node
 */
void Level::XmlBeginText(wxXmlNode *node)
{
    mType = node->GetAttribute("level");
}
/**
 * To read and draw Features
 * @param node
 */
void Level::XmlFeature(wxXmlNode *node)
{
       mNumofFeatures++;
        shared_ptr<Item> item;
        item = make_shared<Feature>(mPlayingArea);
        if(item != nullptr) {
            mPlayingArea->Add(item);
            item->XmlLoad(node);
        }
}
/**
 * To read and draw bugs
 * @param node
 */
void Level::XmlBug(wxXmlNode *node)
{
    wxString type = node->GetAttribute("type");
    if (type.Cmp("nullbug") == 0 || type.Cmp("null") == 0)
    {
        mNumOfBugs++;
        shared_ptr<Item> item;
        item = make_shared<NullBug>(mPlayingArea);
        if(item != nullptr)
        {
            mPlayingArea->Add(item);
            item->XmlLoad(node);
        }
    }
    else if (type.Cmp("garbage") == 0)
    {
        mNumOfBugs++;
        shared_ptr<Item> item;
        item = make_shared<GarbageBug>(mPlayingArea);
        if(item != nullptr)
        {
            mPlayingArea->Add(item);
            item->XmlLoad(node);
            }
    }
    else if (type.Cmp("redundancy") == 0)
    {
        mNumOfBugs++;
//        shared_ptr<Item> item;
//        item = make_shared<RedundancyBug>(mPlayingArea);
//        if(item != nullptr)
//        {
//            mPlayingArea->Add(item);
//            item->XmlLoad(node);
//            }
    }


}

/**
 * Update the text in time
 *@param elaped  time to update
 */
void Level::Update(double elapsed)
{
    mTextDuration += elapsed;
    if (mIsStart)
    {
        if (mTextDuration > TextOnScreenDuration)
        {
            mIsStart = false;
            mTextDuration = 0;
            mState = State::PLAYING;
        }
    }

}
/**
 * To read and draw Programme
 * @param node
 */
void Level::XmlProgram(wxXmlNode *node)
{
    mNumOfProgramme ++;
    shared_ptr<Item> item;
    item = make_shared<Program>(mPlayingArea);
    if(item != nullptr)
    {
        mPlayingArea->Add(item);
        item->XmlLoad(node);
    }

}
/**
 * Loads in the xml file based on what level number it is
 */
//void Level::Load(int mNum)
//{
//	switch(mNum)
//	{
//		case 0:
//		{
//			wxXmlDocument xmlDoc;
//			if(!xmlDoc.Load("data/level0.xml"))
//			{
//				wxMessageBox(L"Unable to load Level file");
//				return;
//			}
//
//			// Get the XML document root node
//			auto root = xmlDoc.GetRoot();
//
//			//
//			// Traverse the children of the root
//			// node of the XML document in memory!!!!
//			//
//			auto child = root->GetChildren();
//			for( ; child; child=child->GetChildren())
//			{
//				//Load XML
//				if (auto child2 = child->GetNext())
//				{
//					for( ; child2; child2 = child2->GetNext())
//					{
//						//Load XML
//
//					}
//				}
//			}
//			break;
//		}
//
//		case 1:
//		{
//			wxXmlDocument xmlDoc;
//			if(!xmlDoc.Load("data/level1.xml"))
//			{
//				wxMessageBox(L"Unable to load Level file");
//				return;
//			}
//
//			// Get the XML document root node
//			auto root = xmlDoc.GetRoot();
//
//			//
//			// Traverse the children of the root
//			// node of the XML document in memory!!!!
//			//
//			auto child = root->GetChildren();
//			for( ; child; child=child->GetChildren())
//			{
//				//Load XML
//				if (auto child2 = child->GetNext())
//				{
//					for( ; child2; child2 = child2->GetNext())
//					{
//						//Load XML
//
//					}
//				}
//
//			}
//			break;
//		}
//
//
//		case 2:
//		{
//			wxXmlDocument xmlDoc;
//			if(!xmlDoc.Load("data/level2.xml"))
//			{
//				wxMessageBox(L"Unable to load Level file");
//				return;
//			}
//
//			// Get the XML document root node
//			auto root = xmlDoc.GetRoot();
//
//			//
//			// Traverse the children of the root
//			// node of the XML document in memory!!!!
//			//
//			auto child = root->GetChildren();
//			for( ; child; child=child->GetChildren())
//			{
//				//Load XML
//				if (auto child2 = child->GetNext())
//				{
//					for( ; child2; child2 = child2->GetNext())
//					{
//						//Load XML
//					}
//				}
//
//			}
//			break;
//		}
//	}
//
//    mStopWatch.Start();
//}

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

//    while(mStopWatch.Time() != 2)
//    {
//        graphics.DrawText(mType, LevelNameX - (width/2), LevelNameY - (length/2));
//    }
//    mStopWatch.Pause();
}

