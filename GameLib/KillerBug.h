/**
 * @file KillerBug.h
 * @author Alexandra Bannon
 *
 *
 */

#ifndef PROJECT1_GAMELIB_KILLERBUG_H
#define PROJECT1_GAMELIB_KILLERBUG_H

#include "Bug.h"

/**
 * Class for the KillerBug
 */
class KillerBug  : public Bug {
private:

public:
	/// Default constructor (disabled)
	KillerBug() = delete;

	/// Copy constructor (disabled)
	KillerBug(const KillerBug &) = delete;

	KillerBug(PlayingArea *area);

	/**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
	void Accept(ItemVisitor* visitor) override {visitor->VisitKiller(this);}

	void XmlLoad(wxXmlNode* node, std::shared_ptr<Program> program) override;
};

#endif //PROJECT1_GAMELIB_KILLERBUG_H
