/**
 * @file RedundancyBug.h
 * @author Alexandra Bannon
 * @author Nicole Kuang
 * @author Jacob Yax
 * @author Gaya Kanagaraj
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
	bool mHasMultiplied = false;
    bool mSquashed = false;
    bool mChangeDirection;
    double mCurrentWingPeriod = 0;
    double mCurrentRotation = 0;
    double mDirection = 1;

    /// Redundancy Fly Base Image and Bitmap
    std::unique_ptr<wxImage> mRedundancyFlyBaseImage;
    wxGraphicsBitmap mRedundancyFlyBaseBitmap;

    ///Redundancy Fly Left Wing Image and Bitmap
    std::unique_ptr<wxImage> mRedundancyFlyLeftWingImage;
    wxGraphicsBitmap mRedundancyFlyLeftWingBitmap;

    ///Redundancy Fly Right Wing Image and Bitmap
    std::unique_ptr<wxImage> mRedundancyFlyRightWingImage;
    wxGraphicsBitmap mRedundancyFlyRightWingBitmap;

    /// Redundacy Fly Top Image and Bitmap
    std::unique_ptr<wxImage> mRedundancyFlyTopImage;
    wxGraphicsBitmap mRedundancyFlyTopBitmap;

public:
	/// Default constructor (disabled)
	RedundancyBug() = delete;

	/// Copy constructor
	RedundancyBug(const RedundancyBug &);
    /// Constructor
    RedundancyBug(PlayingArea *area);

	/**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
	void Accept(ItemVisitor* visitor) override {visitor->VisitRedundancy(this);}

    void XmlLoad(wxXmlNode* node, std::shared_ptr<Program> program) override;

    void Update(double elapsed) override;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    bool GetMultiplied() {return mHasMultiplied;};
    void SetMultiplied(bool mult) {mHasMultiplied = mult;}

    void Multiply();
    void Reverse();

};

#endif //PROJECT1_GAMELIB_REDUNDANCYBUG_H
