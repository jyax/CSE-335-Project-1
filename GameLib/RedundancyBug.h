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

	/// Has the redundancy fly's wings changed direction?
    bool mChangeDirection;

    double mCurrentWingPeriod = 0;  ///< the time the wings have spent flapping in seconds
    double mCurrentAngle = 0;  ///< The current angle of the wings in radians
    double mDirection = 1;  ///< The direction of the wings: 1 for forwards, -1 for backwards

    /// Redundancy Fly Base Image
    std::unique_ptr<wxImage> mRedundancyFlyBaseImage;

	/// Redundancy Fly Base Bitmap
    wxGraphicsBitmap mRedundancyFlyBaseBitmap;

    /// Redundancy Fly Left Wing Image
    std::unique_ptr<wxImage> mRedundancyFlyLeftWingImage;

	/// Redundancy Fly Left Wing Bitmap
    wxGraphicsBitmap mRedundancyFlyLeftWingBitmap;

    /// Redundancy Fly Right Wing Image
    std::unique_ptr<wxImage> mRedundancyFlyRightWingImage;

	/// Redundancy Fly Right Wing Bitmap
    wxGraphicsBitmap mRedundancyFlyRightWingBitmap;

    /// Redundancy Fly Top Image
    std::unique_ptr<wxImage> mRedundancyFlyTopImage;

	/// Redundancy Fly Top Bitmap
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

    void XmlLoad(wxXmlNode* node, std::shared_ptr<Item> item) override;

    void Update(double elapsed) override;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

	/**
	 * Get whether the bug has multiplied or not
	 * @return true if yes, false otherwise
	 */
    bool GetMultiplied() {return mHasMultiplied;}

	/**
	 * Set whether the bug has multiplied or not
	 * @param mult whether or not the but has multiplied
	 */
    void SetMultiplied(bool mult) {mHasMultiplied = mult;}

    void Multiply();
    void Reverse();
};

#endif //PROJECT1_GAMELIB_REDUNDANCYBUG_H
