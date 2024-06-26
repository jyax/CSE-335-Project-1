/**
 * @file NullBug.h
 * @author Alexandra Bannon
 * @author Nicole Kuang
 * @author Jacob Yax
 * @author Gaya Kanagaraj
 *
 * Class for the NullBug inherited from Bug
 *
 */

#ifndef PROJECT1_GAMELIB_NULLBUG_H
#define PROJECT1_GAMELIB_NULLBUG_H

#include "Bug.h"

/**
 * Class for the NullBug
 */
class NullBug : public Bug {
private:

public:
	/// Default constructor (disabled)
	NullBug() = delete;

	/// Copy constructor (disabled)
	NullBug(const NullBug &) = delete;

	NullBug(PlayingArea *area);

	/**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
	void Accept(ItemVisitor* visitor) override {visitor->VisitNull(this);}

    void XmlLoad(wxXmlNode* node, std::shared_ptr<Item> item) override;

    void Update(double elapsed) override;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;


};

#endif //PROJECT1_GAMELIB_NULLBUG_H
