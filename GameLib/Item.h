/**
 * @file Item.h
 * @author Jacob Meier
 *
 * Base class for any item in our Game.
 */

#ifndef PROJECT1_GAMELIB_ITEM_H
#define PROJECT1_GAMELIB_ITEM_H

class Game;
/**
 * Base class for any item in our Game.
 */
class Item
{
private:
	///The game this item is contained in
	Game *mGame;

	/// The underlying item image
	std::unique_ptr<wxImage> mItemImage;

	/// The bitmap we can display for this item
	std::unique_ptr<wxBitmap> mItemBitmap;

	/// Item location in the aquarium
	double  mX = 0;     ///< X location for the center of the item
	double  mY = 0;     ///< Y location for the center of the item

public:

};

#endif //PROJECT1_GAMELIB_ITEM_H
