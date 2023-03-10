/**
 * @file Feature.h
 *
 * @author Jacob Yax
 *
 */

#ifndef PROJECT1_FEATURE_H
#define PROJECT1_FEATURE_H

#include "Bug.h"
/**
 * Feature class to represent the Feature "Bug" that is not supposed to be clicked on.
 */
class Feature : public Bug{
private:

public:
    /// Default Constructor (disabled)
    Feature() = delete;

    /// Copy Constructor (disabled)
    Feature(const Feature &) = delete;

	Feature(Game* game);
};


#endif //PROJECT1_FEATURE_H
