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
    std::wstring mProgramName;

    /// Playing are this program belongs to
    PlayingArea *mPlayingArea;

    /// The item programme
    std::shared_ptr<wxImage> mProgrammeImage;
    /// The item bitmap
    wxGraphicsBitmap mProgrammeBitmap;


public:
    /// Default Constructor (disabled)
    Program() = delete;

    /// Copy Constructor (disabled)
    Program(const Program &) = delete;

	Program(PlayingArea *area);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

	void Accept(ItemVisitor* visitor) override {visitor->VisitProgram(this);}

    void XmlLoad(wxXmlNode *node,std::shared_ptr<Item> program) override;

	/**
    * checks if item is program
    * @return True is item is a program otherwise false
    */
	bool IsProgram() override {return TRUE;};

    //bool ReachedProgram() override {  return false; }
    /**
    * Compute the distance from this to another item
    * @param item Item we are computing the distantce to
    * @return Distance in pixels
    */
    double DistanceTo(std::shared_ptr<Item> item) override{ return Item::DistanceTo(item);}
    void Update(double elapsed) override;

};


#endif //PROJECT1_PROGRAM_H
