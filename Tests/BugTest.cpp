/**
 * @file BugTest.cpp
 * @author Nicole Kuang
 */

#include <pch.h>
#include <gtest/gtest.h>
#include <PlayingArea.h>
#include <GarbageBug.h>

// Test to see if HitTest hits bugs correctly
TEST(BugTest, HitTest)
{
	PlayingArea area;

	ASSERT_EQ(area.Click(353, 295), nullptr);

	auto bug1 = std::make_shared<GarbageBug>(&area);
	bug1->SetLocation(353, 295);
	area.Add(bug1);

	// Center of bug
	ASSERT_TRUE(bug1->HitTest(353, 295));

	// 49 pixels left
	ASSERT_TRUE(bug1->HitTest(304, 295));

	// 49 pixels down
	ASSERT_TRUE(bug1->HitTest(353, 344));

	// no bug area
	ASSERT_FALSE(bug1->HitTest(300, 200));

	// past range (50 pixels)
	ASSERT_FALSE(bug1->HitTest(303, 295));
}

TEST(BugTest, CheckCode)
{
	PlayingArea area;

	auto bug1 = std::make_shared<GarbageBug>(&area);
	bug1->SetLocation(100, 200);
	bug1->SetIsFatBug(true);

	bug1->SetPass(L"int.*mScore.*=.*[0-9]*.*;");
	bug1->SetCode(L"/**\n"
				  " * The game scoreboard/scoring area\n"
				  " */\n"
				  "class ScoreBoard\n"
				  "{\n"
				  "private:\n"
				  "    /// The current score\n"
				  "    int mScore;\n"
				  "\n"
				  "public:\n"
				  "    void Draw(std::shared_ptr<wxGraphicsContext> graphics);\n"
				  "};");

	area.Add(bug1);

	ASSERT_FALSE(bug1->CheckCode());

	bug1->SetCode(L"/**\n"
				  " * The game scoreboard/scoring area\n"
				  " */\n"
				  "class ScoreBoard\n"
				  "{\n"
				  "private:\n"
				  "    /// The current score\n"
				  "    int mScore = 0;\n"
				  "\n"
				  "public:\n"
				  "    void Draw(std::shared_ptr<wxGraphicsContext> graphics);\n"
				  "};");

	ASSERT_TRUE(bug1->CheckCode());
}