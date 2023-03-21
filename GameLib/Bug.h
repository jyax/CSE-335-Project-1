/**
 * @file Bug.h
 * @author Alexandra Bannon
 * @author Nicole Kuang
 * @author Jacob Yax
 * @author Gaya Kanagaraj
 *
 * Base class for the bugs in the game inherited from Item
 */

#ifndef PROJECT1_GAMELIB_BUG_H
#define PROJECT1_GAMELIB_BUG_H

#include <random>
#include "Item.h"
#include "PlayingArea.h"

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
	bool mIsFatBug = false;

	///what frame of the image is the bug
	double mIteration = 1;

	///number of frames the bug has
	double mFrames;
	///Start time of the bug
	double mStart;

    ///Start move time
    double mStartMove = 0.0;
	//wxStopWatch mStopWatch;

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

    /// Default constructor
    Bug();

    /// Copy constructor
    Bug(const Bug &);

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
	bool GetIsFatBug() { return mIsFatBug; }

	/**
	 * Set whether the bug is fat
	 * @param fat bug's fat status
	 */
	void SetIsFatBug(bool fat) { mIsFatBug = fat; }

	double GetAngle();

	~Bug();
};

#endif //PROJECT1_GAMELIB_BUG_H
