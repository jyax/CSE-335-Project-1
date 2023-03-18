/**
 * @file ItemTest.cpp
 * @author Nicole Kuang
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Item.h>
#include <PlayingArea.h>

using namespace std;

/// Bug filename
const wstring GarbageBugImage = L"images/blue-maize-bug.png";

/**
 * Class for testing items, since Item is abstract
 */
class ItemMock : public Item {
public:
	ItemMock(PlayingArea *area) : Item(area, GarbageBugImage) {}

	/**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
	virtual void Accept(ItemVisitor* visitor) override {}
};

TEST(ItemTest, Construct)
{
	PlayingArea area;
	ItemMock item(&area);
}

TEST(ItemTest, GetSetLocation)
{
	PlayingArea area;
	ItemMock item(&area);

	// Test initial values
	ASSERT_NEAR(0, item.GetX(), 0.0001);
	ASSERT_NEAR(0, item.GetY(), 0.0001);

	// Test SetLocation, GetX, and GetY
	item.SetLocation(10.5, 17.2);
	ASSERT_NEAR(10.5, item.GetX(), 0.0001);
	ASSERT_NEAR(17.2, item.GetY(), 0.0001);

	// Test a second with different values
	item.SetLocation(-72, -107);
	ASSERT_NEAR(-72, item.GetX(), 0.0001);
	ASSERT_NEAR(-107, item.GetY(), 0.0001);
}
