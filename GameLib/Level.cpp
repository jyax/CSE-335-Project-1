/**
 * @file Level.cpp
 * @author Jacob Meier
 * @author Nicole Kuang
 * @author Gaya Kanagaraj
 * class that loads xmlfile and passes the tags to the appropriate item
 */

#include "pch.h"
#include "Level.h"
#include "Program.h"
#include "Feature.h"
#include "NullBug.h"
#include "RedundancyBug.h"
#include "GarbageBug.h"

using namespace std;

//Working with the idea of a switch case, currently trying
//to figure out where the commandevent function would be binded from

//Update - currently bound in GameView class for Level0 only
//works on event as anticipated, trying to figure out what this class would
//do with that information, or if that's the appropriate place for the function
//For clarity: added Line 21, and Lines 24-26 to GameView

/**
 * Constructor
 * @param game the game this is a part of
 */
Level::Level(Game* game) : mGame(game)
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
    mGame = original.mGame;
    mItemList = original.mItemList;
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
        cout<<"Unable to Load Level"<<endl;
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
    mNumofFeatures ++;
    wxString type = node->GetAttribute("type");
    if (type.Cmp("feature") == 0)
    {
        //        mNumOfProgramme ++;
//        shared_ptr<Item> item;
//        item = make_shared<Feature>(mGame);
//        if(item != nullptr)
//        {
//            mItemList.push_back(item);
//            item->XmlLoad(node);
//        }

    }
}

/**
 * To read and draw bugs
 * @param node
 */
void Level::XmlBug(wxXmlNode *node)
{
    mNumOfBugs ++;
    wxString type = node->GetAttribute("type");
    if (type.Cmp("nullbug") == 0 || type.Cmp("null") == 0)
    {
//        mNumOfProgramme ++;
//        shared_ptr<Item> item;
//        item = make_shared<NullBug>(mGame);
//        if(item != nullptr)
//        {
//            mItemList.push_back(item);
//            item->XmlLoad(node);
//        }
    }
    else if (type.Cmp("garbage") == 0)
    {
//        mNumOfProgramme ++;
//        shared_ptr<Item> item;
//        item = make_shared<GarbageBug>(mGame);
//        if(item != nullptr)
//        {
//            mItemList.push_back(item);
//            item->XmlLoad(node);
//            }
    }
    else if (type.Cmp("redundancy") == 0)
    {
//        mNumOfProgramme ++;
//        shared_ptr<Item> item;
//        item = make_shared<RedundancyBug>(mGame);
//        if(item != nullptr)
//        {
//            mItemList.push_back(item);
//            item->XmlLoad(node);
//            }
    }


}
/**
 * To read and draw Programme
 * @param node
 */
void Level::XmlProgram(wxXmlNode *node)
{
    mNumOfProgramme ++;
//    shared_ptr<Item> item;
//    item = make_shared<Program>(mGame);
//    if(item != nullptr)
//    {
//        mItemList.push_back(item);
////        item->XmlLoad(node);
//    }

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
//
//}

/**
 * Destructor
 */
Level::~Level()
{
}

