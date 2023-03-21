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

#include <random>
#include "Item.h"

class PlayingArea;
/**
 * Base class for the bugs in the game
 */
class Bug : public Item {
private:

    /// playing AREA
    PlayingArea *mPlayingArea;
	///Speed the bug is traveling
	double mSpeed =0.0;

	///Destination of the bug
	Item *mDestination;

	///Bool to tell if the bug is a FatBug or not
	bool mIsFatBug;

	///what frame of the image is the bug
	double mIteration = 1;

	///number of frames the bug has
	double mFrames = 0.0;
	///Start time of the bug
	double mStart =0.0;

    /// mStartMove of the bug
    double mStartMove = 0.0;

	//wxStopWatch mStopWatch;

    //wxStopWatch mStopWatch;
    /// Random number generator
    double mRandom;
    /// random angle value
    double mRandomAngle = 0;

    /// sprite duration
    double mShowSprite = 3.0/ mSpeed;

    /// for the current sprite value
    double mCurrentSprite = 0.0;


	/// Check if this bug was squashed
	bool mIsHit = false;

    /// Program for this bug
    std::shared_ptr<Program> mProgram;

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

    void XmlLoad(wxXmlNode *node,std::shared_ptr<Program> program) override;

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

	/**
	 * Is the bug a fat bug?
	 * @return true if yes, false otherwise
	 */
	bool GetIsFatBug() {return mIsFatBug;}

    double GetAngle();
};

#endif //PROJECT1_GAMELIB_BUG_H
