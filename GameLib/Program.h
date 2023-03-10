/**
 * @file Program.h
 *
 * @author Jacob Yax
 */

#ifndef PROJECT1_PROGRAM_H
#define PROJECT1_PROGRAM_H

#include "Item.h"
/**
 * Program class that represents the laptop in the center of the game
 */
class Program : public Item {
private:

public:
    /// Default Constructor (disabled)
    Program() = delete;

    /// Copy Constructor (disabled)
    Program(const Program &) = delete;

	Program(Game* game);
};


#endif //PROJECT1_PROGRAM_H
