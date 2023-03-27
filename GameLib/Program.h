/**
 * @file Program.h
 * @author Jacob Yax
 * @author Nicole Kuang
 * @author Gaya Kanagaraj
 *
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
	/// The program's name, to be displayed
    std::wstring mProgramName;

    /// Playing are this program belongs to
    PlayingArea *mPlayingArea = nullptr;


public:
    /// Default Constructor (disabled)
    Program() = delete;

    /// Copy Constructor (disabled)
    Program(const Program &) = delete;

	Program(PlayingArea *area);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

	/**
	 * Accept a visitor
	 * @param visitor the visitor to accept
	 */
	void Accept(ItemVisitor* visitor) override {visitor->VisitProgram(this);}

    void XmlLoad(wxXmlNode *node,std::shared_ptr<Item> program) override;

    /**
    * Compute the distance from this to another item
    * @param item Item we are computing the distantce to
    * @return Distance in pixels
    */
    double DistanceTo(std::shared_ptr<Item> item) override{return Item::DistanceTo(item);}

    void Update(double elapsed) override;
};


#endif //PROJECT1_PROGRAM_H
