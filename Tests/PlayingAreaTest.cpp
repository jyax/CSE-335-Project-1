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
//#include <RedundancyBug.h>

class TestVisitor : public ItemVisitor {
public:
	virtual void VisitFeature(Feature* feature) override {mNumFeatures++;}

	int mNumFeatures = 0;
};

TEST(PlayingAreaTest, Visitor)
{
	PlayingArea area;

	auto bug1 = std::make_shared<Feature>(&area);
	auto bug2 = std::make_shared<GarbageBug>(&area);
	auto bug3 = std::make_shared<NullBug>(&area);

	TestVisitor visitor;
	area.Accept(&visitor);
	//ASSERT_EQ(1, visitor.mNumFeatures);
}