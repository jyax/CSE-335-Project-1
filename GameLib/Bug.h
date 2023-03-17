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

protected:
	Bug(PlayingArea *area, const std::wstring &filename, double frames);

public:
	/// Default constructor (disabled)
	Bug() = delete;

	/// Copy constructor (disabled)
	Bug(const Bug &) = delete;

	bool HitTest(double x, double y) override;

	void Update(double elapsed) override;

	void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void XmlLoad(wxXmlNode *node) override;

};

#endif //PROJECT1_GAMELIB_BUG_H
