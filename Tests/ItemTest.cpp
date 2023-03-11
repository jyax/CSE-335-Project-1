/**
 * @file ItemTest.cpp
 * @author Nicole Kuang
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Item.h>
#include <Game.h>

using namespace std;

/// Bug filename
const wstring GarbageBugImage = L"images/blue-maize-bug.png";

/**
 * Class for testing items, since Item is abstract
 */
class ItemMock : public Item {
public:
	ItemMock(Game *game) : Item(game, GarbageBugImage) {}
};

TEST(ItemTest, Construct)
{
	Game game;
	ItemMock item(&game);
}

TEST(ItemTest, GetSetLocation)
{
	Game game;
	ItemMock item(&game);

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

// Uncomment when bugs can be drawn in the game
/*TEST(ItemTest, HitTest)
{
	Game game;
	ItemMock item(&game);

	item.SetLocation(305, 243);

	ASSERT_TRUE(item.HitTest(305, 243));

 	ASSERT_FALSE(item.HitTest(400, 200));

 	ASSERT_FALSE(item.HitTest(100, 240));
}*/
