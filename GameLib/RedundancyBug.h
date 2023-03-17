/**
 * @file RedundancyBug.h
 * @author Alexandra Bannon
 * @author Nicole Kuang
 * @author Jacob Yax
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
	bool mHasMultiplied;

public:
	/// Default constructor (disabled)
	RedundancyBug() = delete;

	/// Copy constructor (disabled)
	RedundancyBug(const RedundancyBug &) = delete;

	/**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
	void Accept(ItemVisitor* visitor) override {visitor->VisitRedundancy(this);}

    bool HitTest(double x, double y) override;

    void XmlLoad(wxXmlNode* node) override;

};

#endif //PROJECT1_GAMELIB_REDUNDANCYBUG_H
