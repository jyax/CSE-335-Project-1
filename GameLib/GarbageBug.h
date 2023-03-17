/**
 * @file GarbageBug.h
 * @author Alexandra Bannon
 * @author Nicole Kuang
 * @author Jacob Yax
 *
 * Class for the GarbageBug inherited from Bug
 *
 */

#ifndef PROJECT1_GAMELIB_GARBAGEBUG_H
#define PROJECT1_GAMELIB_GARBAGEBUG_H
#include "Bug.h"

/**
 * Class for the GarbageBug
 */
class GarbageBug  : public Bug {
private:

public:
	/// Default constructor (disabled)
	GarbageBug() = delete;

	/// Copy constructor (disabled)
	GarbageBug(const GarbageBug &) = delete;

	GarbageBug(PlayingArea *area);

	/**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
	void Accept(ItemVisitor* visitor) override {visitor->VisitGarbage(this);}
    void XmlLoad(wxXmlNode* node) override;
};

#endif //PROJECT1_GAMELIB_GARBAGEBUG_H
