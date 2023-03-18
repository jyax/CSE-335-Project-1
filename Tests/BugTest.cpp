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

	ASSERT_EQ(area.SingleClick(353, 295), nullptr);

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