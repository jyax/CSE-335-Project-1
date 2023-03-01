/**
 * @file RedundancyBug.h
 * @author Alexandra Bannon
 *
 * Class for the RedundancyBug inherited from Bug
 *
 */

#ifndef PROJECT1_GAMELIB_REDUNDANCYBUG_H
#define PROJECT1_GAMELIB_REDUNDANCYBUG_H
#include "Bug.h"

/**
 * Class for the RedundancyBug
 */
class RedundancyBug  : public Bug {
private:
	/// Has the bug spawned multiples?
	bool mHasMultiplied;

public:
	/// Default constructor (disabled)
	RedundancyBug() = delete;

	/// Copy constructor (disabled)
	RedundancyBug(const RedundancyBug &) = delete;

};

#endif //PROJECT1_GAMELIB_REDUNDANCYBUG_H
