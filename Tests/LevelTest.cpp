/**
 * @file LevelTest.cpp
 * @author Gaya Kanagaraj
 * @author Nicole Kuang
 */

#include "pch.h"
#include <wx/xml/xml.h>
#include <gtest/gtest.h>
#include <Level.h>
#include <PlayingArea.h>

class LevelTest : public testing::Test {
protected:
    virtual void SetUp() {
        // Set up any resources needed for the tests
        mArea = new PlayingArea();
        mLevel = new Level(mArea);
    }
    PlayingArea* mArea;
    Level* mLevel;
};

// Tests the ReadLevel method
TEST_F(LevelTest, ReadLevelTest)
{
	// Test on an empty level
	ASSERT_EQ(mLevel->GetNumOfBug(), 0);
	ASSERT_EQ(mLevel->GetNumOfFeature(), 0);
	ASSERT_EQ(mLevel->GetNumOfProgram(), 0);

    // Test loading a valid level
    mLevel->ReadLevel(L"data/level2.xml");
    // Assert that the level has been loaded correctly
    ASSERT_EQ(mLevel->GetNumOfProgram(), 3);
    ASSERT_EQ(mLevel->GetNumOfBug(), 17);
    ASSERT_EQ(mLevel->GetNumOfFeature(), 7);

}

// Test for Level::XmlBeginText function
TEST_F(LevelTest, XmlBeginTextTest)
{
    // create a wxXmlNode object for testing
    wxXmlNode* node = new wxXmlNode(wxXML_ELEMENT_NODE, "level");
    node->AddAttribute("level", "Level Text");
    mLevel->XmlBeginText(node);
    EXPECT_EQ(mLevel->GetMType(), "Level Text");
    EXPECT_NE(mLevel->GetMType(), "Level Text1");

}