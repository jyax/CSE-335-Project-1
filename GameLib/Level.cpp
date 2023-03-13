/**
 * @file Level.cpp
 * @author Jacob Meier
 * @author Nicole Kuang
 */

#include "pch.h"
#include "Level.h"

//Working with the idea of a switch case, currently trying
//to figure out where the commandevent function would be binded from

//Update - currently bound in GameView class for Level0 only
//works on event as anticipated, trying to figure out what this class would
//do with that information, or if that's the appropriate place for the function
//For clarity: added Line 21, and Lines 24-26 to GameView

Level::Level()
{
}
/**
 * Loads in the xml file based on what level number it is
 */
void Level::Load(int mNum)
{
	switch(mNum)
	{
		case 0:
		{
			wxXmlDocument xmlDoc;
			if(!xmlDoc.Load("data/level0.xml"))
			{
				wxMessageBox(L"Unable to load Level file");
				return;
			}

			// Get the XML document root node
			auto root = xmlDoc.GetRoot();

			//
			// Traverse the children of the root
			// node of the XML document in memory!!!!
			//
			auto child = root->GetChildren();
			for( ; child; child=child->GetChildren())
			{
				//Load XML
				if (auto child2 = child->GetNext())
				{
					for( ; child2; child2 = child2->GetNext())
					{
						//Load XML

					}
				}
			}
			break;
		}

		case 1:
		{
			wxXmlDocument xmlDoc;
			if(!xmlDoc.Load("data/level1.xml"))
			{
				wxMessageBox(L"Unable to load Level file");
				return;
			}

			// Get the XML document root node
			auto root = xmlDoc.GetRoot();

			//
			// Traverse the children of the root
			// node of the XML document in memory!!!!
			//
			auto child = root->GetChildren();
			for( ; child; child=child->GetChildren())
			{
				//Load XML
				if (auto child2 = child->GetNext())
				{
					for( ; child2; child2 = child2->GetNext())
					{
						//Load XML

					}
				}

			}
			break;
		}


		case 2:
		{
			wxXmlDocument xmlDoc;
			if(!xmlDoc.Load("data/level2.xml"))
			{
				wxMessageBox(L"Unable to load Level file");
				return;
			}

			// Get the XML document root node
			auto root = xmlDoc.GetRoot();

			//
			// Traverse the children of the root
			// node of the XML document in memory!!!!
			//
			auto child = root->GetChildren();
			for( ; child; child=child->GetChildren())
			{
				//Load XML
				if (auto child2 = child->GetNext())
				{
					for( ; child2; child2 = child2->GetNext())
					{
						//Load XML
					}
				}

			}
			break;
		}
	}


}

/**
 * Destructor
 */
Level::~Level()
{
}

