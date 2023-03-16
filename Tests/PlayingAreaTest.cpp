/**
 * @file PlayingAreaTest.cpp
 * @author Nicole Kuang
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <PlayingArea.h>
#include <Feature.h>
#include <GarbageBug.h>
#include <NullBug.h>
#include <Program.h>
//#include <RedundancyBug.h>

class TestVisitor : public ItemVisitor {
public:
	virtual void VisitFeature(Feature* feature) override {mNumFeatures++;}
	virtual void VisitGarbage(GarbageBug* bug) override {mNumGarbages++;}
	virtual void VisitNull(NullBug* bug) override {mNumNulls++;}

	int mNumFeatures = 0;
	int mNumGarbages = 0;
	int mNumNulls = 0;
};

// Test to see if visitor goes to each bug
TEST(PlayingAreaTest, Visitor)
{
	PlayingArea area;

	auto bug1 = std::make_shared<Feature>(&area);
	auto bug2 = std::make_shared<GarbageBug>(&area);
	auto bug3 = std::make_shared<NullBug>(&area);
	auto prog = std::make_shared<Program>(&area);

	area.Add(bug1);
	area.Add(bug2);
	area.Add(bug3);
	area.Add(prog);

	TestVisitor visitor;
	area.Accept(&visitor);
	ASSERT_EQ(1, visitor.mNumFeatures);
	ASSERT_EQ(1, visitor.mNumGarbages);
	ASSERT_EQ(1, visitor.mNumNulls);

	// Empty playing area
	PlayingArea area2;

	TestVisitor visitor2;
	area2.Accept(&visitor2);
	ASSERT_EQ(0, visitor2.mNumFeatures);
	ASSERT_EQ(0, visitor2.mNumGarbages);
	ASSERT_EQ(0, visitor2.mNumNulls);
}

// Test to see if we are able to click in the playing area
TEST(PlayingAreaTest, SingleClickTest)
{
	PlayingArea area;

	ASSERT_EQ(area.SingleClick(100, 100), nullptr);

	auto bug = std::make_shared<GarbageBug>(&area);
	area.Add(bug);
	bug->SetLocation(100, 100);

	ASSERT_TRUE(area.SingleClick(100, 100) == bug);
}