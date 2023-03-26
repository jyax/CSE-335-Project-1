/**
 * @file Bug.h
 * @author Alexandra Bannon
 * @author Nicole Kuang
 * @author Jacob Yax
 * @author Gaya Kanagaraj
 *
 * Base class for the bugs in the game inherited from Item
 */

#ifndef PROJECT1_GAMELIB_BUG_H
#define PROJECT1_GAMELIB_BUG_H

#include <random>
#include "Item.h"
#include "PlayingArea.h"
#include "ItemVisitor.h"

/**
 * Base class for the bugs in the game
 */
class Bug : public Item {
private:
	///Speed the bug is traveling
	double mSpeed;

	///playing area the bug is in 
    PlayingArea *mArea = nullptr;

	///Bool to tell if the bug is a FatBug or not
	bool mIsFatBug = false;

	/// A regular expression to match fixed code
	std::wstring mPass;

	/// A fat bug's broken code
	std::wstring mCode;

	///what frame of the image is the bug
	int mIteration = 0;

	///number of frames the bug has
	int mFrames;

	///Start time of the bug
	double mStart;

    ///Start move time
    double mStartMove = 0.0;

	/// Check if this bug was squashed
	bool mIsHit = false;

    /// Destination for this bug
    std::shared_ptr<Item> mDestination;

	/// The underlying splatted image
	std::shared_ptr<wxImage> mSplatImage;

	/// The bitmap to display for the splatted bug
	wxGraphicsBitmap mSplatBitmap;

protected:
	Bug(PlayingArea *area, const std::wstring &filename, double frames);
    /// The range from the center of the bug to see if hit or not
    const int BugHitRange = 50;

public:

    /// Default constructor
    Bug() = delete;

    /// Copy constructor
    Bug(const Bug &);

	bool HitTest(double x, double y) override;

	void Update(double elapsed) override;

	void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void XmlLoad(wxXmlNode *node,std::shared_ptr<Item> item) override;

	/**
	 * Get the hit status of the bug
	 * @return bug's hit status
	 */
	bool GetIsHit() override {return mIsHit;}

	/**
	 * Set the hit status of the bug
	 * @param hit bug's hit status
	 */
	void SetIsHit(bool hit) {mIsHit = hit;}

	/**
	 * Is the bug a fat bug?
	 * @return true if yes, false otherwise
	 */
	bool GetIsFatBug(){ return mIsFatBug; }

	/**
	 * Set whether the bug is fat
	 * @param fat bug's fat status
	 */
	void SetIsFatBug(bool fat) { mIsFatBug = fat; }

	/**
	 * Set the regex that matches the fixed code
	 * @param pass the matching regular expression
	 */
	void SetPass(std::wstring pass) {mPass = pass;}

	/**
	 * Get the broken/fixed code for the fat bug
	 * @return the fat bug's code
	 */
	std::wstring GetCode() override {return mCode;}

	/**
	 * Set the broken/fixed code for the fat bug
	 * @param code the fat bug's code
	 */
	void SetCode(std::wstring code) {mCode = code;}

	double GetAngle();

	~Bug();

    /**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
    void Accept(ItemVisitor* visitor) override{}


    bool CheckCode();
    /**
    * Compute the distance from this to another item
    * @param item Item we are computing the distantce to
    * @return Distance in pixels
    */
    double DistanceTo(std::shared_ptr<Item> item) override{ return Item::DistanceTo(item);}

	/**
	 * Set the bug's splat image
	 * @param image the bug's splat image
	 */
	void SetSplatImage(std::shared_ptr<wxImage> image) {mSplatImage = image;}

	/**
	 * Get the bug's splat image
	 * @return the bug's splat image
	 */
	std::shared_ptr<wxImage> GetSplatImage() {return mSplatImage;}

	/**
	 * Get the bug's splat bitmap
	 * @return the bug's splat bitmap
	 */
	wxGraphicsBitmap GetSplatBitmap() {return mSplatBitmap;}

	/**
	 * Set the bug's splat bitmap
	 * @param bitmap the bug's splat bitmap
	 */
	void SetSplatBitmap(wxGraphicsBitmap bitmap) {mSplatBitmap = bitmap;}

};

#endif //PROJECT1_GAMELIB_BUG_H
