/**
 * @file Program.h
 *
 * @author Jacob Yax
 * Class defining the Program item
 */

#ifndef PROJECT1_PROGRAM_H
#define PROJECT1_PROGRAM_H

#include "Item.h"
/**
 * Program class that represents the laptop in the center of the game
 */
class Program : public Item {
private:
    std::wstring mProgramName = L"Test";

public:
    /// Default Constructor (disabled)
    Program() = delete;

    /// Copy Constructor (disabled)
    Program(const Program &) = delete;

	Program(Game* game);
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
};


#endif //PROJECT1_PROGRAM_H
