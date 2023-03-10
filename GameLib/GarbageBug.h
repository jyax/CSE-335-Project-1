/**
 * @file GarbageBug.h
 * @author Alexandra Bannon
 *
 * Class for the GarbageBug inherited from Bug
 *
 */

#ifndef PROJECT1_GAMELIB_GARBAGEBUG_H
#define PROJECT1_GAMELIB_GARBAGEBUG_H
#include "Bug.h"

/**
 * Class for the GarbageBug
 */
class GarbageBug  : public Bug {
private:

public:
	/// Default constructor (disabled)
	GarbageBug() = delete;

	/// Copy constructor (disabled)
	GarbageBug(const GarbageBug &) = delete;

	GarbageBug(Game* game);


};

#endif //PROJECT1_GAMELIB_GARBAGEBUG_H
