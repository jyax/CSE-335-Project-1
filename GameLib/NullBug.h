/**
 * @file NullBug.h
 * @author Alexandra Bannon
 * @author Nicole Kuang
 *
 * Class for the NullBug inherited from Bug
 *
 */

#ifndef PROJECT1_GAMELIB_NULLBUG_H
#define PROJECT1_GAMELIB_NULLBUG_H

#include "Bug.h"

/**
 * Class for the NullBug
 */
class NullBug : public Bug {
private:

public:
	/// Default constructor (disabled)
	NullBug() = delete;

	/// Copy constructor (disabled)
	NullBug(const NullBug &) = delete;

	NullBug(PlayingArea *area);

};

#endif //PROJECT1_GAMELIB_NULLBUG_H
