/**
 * @file Bug.h
 * @author Alexandra Bannon
 * @author Nicole Kuang
 * @author Jacob Yax
 *
 * Base class for the bugs in the game inherited from Item
 */

#ifndef PROJECT1_GAMELIB_BUG_H
#define PROJECT1_GAMELIB_BUG_H

#include "Item.h"

/**
 * Base class for the bugs in the game
 */
class Bug : public Item {
private:
	///Speed the bug is traveling
	double mSpeed;

	///Destination of the bug
	Item *mDestination;

	///Bool to tell if the bug is a FatBug or not
	bool mIsFatBug;

	///what frame of the image is the bug
	double mIteration = 1;

	///number of frames the bug has
	double mFrames;
	///Start time of the bug
	double mStart;

	//wxStopWatch mStopWatch;

	/// Check if this bug was squashed
	bool mIsHit = false;

protected:
	Bug(PlayingArea *area, const std::wstring &filename, double frames);
    Bug(PlayingArea *area);

	/// The underlying splatted image
	std::shared_ptr<wxImage> mSplatImage;

	/// The bitmap to display for the splatted bug
	wxGraphicsBitmap mSplatBitmap;

public:
	/// Default constructor (disabled)
	Bug() = delete;

	/// Copy constructor (disabled)
	Bug(const Bug &) = delete;

	bool HitTest(double x, double y) override;

	void Update(double elapsed) override;

	void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void XmlLoad(wxXmlNode *node) override;

	/**
	 * Get the hit status of the bug
	 * @return bug's hit status
	 */
	bool GetIsHit() {return mIsHit;}

	/**
	 * Set the hit status of the bug
	 * @param hit bug's hit status
	 */
	void SetIsHit(bool hit) {mIsHit = hit;}
};

#endif //PROJECT1_GAMELIB_BUG_H
