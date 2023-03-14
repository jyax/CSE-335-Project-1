/**
 * @file Item.h
 * @author Jacob Meier
 * @author Nicole Kuang
 *
 * Abstract base class for any item in our Game.
 */

#ifndef PROJECT1_GAMELIB_ITEM_H
#define PROJECT1_GAMELIB_ITEM_H

#include <wx/graphics.h>

class Game;
class PlayingArea;

/**
 * Abstract base class for any item in our Game.
 */
class Item
{
private:
	///The game this item is contained in
	PlayingArea *mArea;

	/// The underlying item image
	std::shared_ptr<wxImage> mItemImage;

	/// The bitmap we can display for this item
	wxGraphicsBitmap mItemBitmap;

	/// Item location in the game
	double  mX = 0;     ///< X location for the center of the item
	double  mY = 0;     ///< Y location for the center of the item

protected:
	Item(PlayingArea *area, const std::wstring &filename);

public:
	/// Default constructor (disabled)
	Item() = delete;

	/// Copy constructor (disabled)
	Item(const Item &) = delete;

	/// Assignment operator (disabled)
	void operator=(const Item &) = delete;

	virtual ~Item();

	/**
     * The X location of the item
     * @return X location in pixels
     */
	double GetX() const { return mX; }

	/**
	 * The Y location of the item
	 * @return Y location in pixels
	 */
	double GetY() const { return mY; }

	/**
	 * Set the item location
	 * @param x X location in pixels
	 * @param y Y location in pixels
	 */
	void SetLocation(double x, double y) { mX = x; mY = y; }

	virtual bool HitTest(double x, double y);

	virtual bool DoubleClickTest(double x, double y);

	virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics);

	/**
     * Handle updates for animation
     * @param elapsed The time since the last update
     */
	virtual void Update(double elapsed) {}

    void XmlLoad(wxXmlNode *node);
};

#endif //PROJECT1_GAMELIB_ITEM_H
