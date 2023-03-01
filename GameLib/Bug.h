/**
 * @file Bug.h
 * @author Alexandra Bannon
 *
 * Base class for the bugs in the game inherited from Item
 */

#ifndef PROJECT1_GAMELIB_BUG_H
#define PROJECT1_GAMELIB_BUG_H

#include "Item.h"

class Bug : public Item {
private:
	///Speed the bug is traveling
	double mSpeed;

	///Destination of the bug
	Item *mDestination;

	///Bool to tell if the bug is a FatBug or not
	bool mIsFatBug;

public:
	/// Default constructor (disabled)
	Bug() = delete;

	/// Copy constructor (disabled)
	Bug(const Bug &) = delete;

};

#endif //PROJECT1_GAMELIB_BUG_H
