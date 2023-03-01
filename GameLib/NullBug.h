/**
 * @file NullBug.h
 * @author Alexandra Bannon
 *
 * Class for the NullBug inherited from Bug
 *
 */

#ifndef PROJECT1_GAMELIB_NULLBUG_H
#define PROJECT1_GAMELIB_NULLBUG_H

#include "Bug.h"

class NullBug : public Bug {
private:

public:
	/// Default constructor (disabled)
	NullBug() = delete;

	/// Copy constructor (disabled)
	NullBug(const NullBug &) = delete;

};

#endif //PROJECT1_GAMELIB_NULLBUG_H
