/**
 * @file KillerBug.h
 * @author Alexandra Bannon
 * @author Nicole Kuang
 *
 * Class for the KillerBug
 */

#ifndef PROJECT1_GAMELIB_KILLERBUG_H
#define PROJECT1_GAMELIB_KILLERBUG_H

#include "Bug.h"

/**
 * Class for the KillerBug
 *
 * This bug hunts features and requires the player
 * to drag them away
 */
class KillerBug : public Bug
{
private:
	///playing area the bug is in
	PlayingArea *mArea = nullptr;

	/// Destination for this bug
	std::shared_ptr<Item> mDestination;

	/// Has the killer bug's score already been accounted for?
	bool AlreadyCalled = false;

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
	void Accept(ItemVisitor *visitor) override { visitor->VisitKiller(this); }

	void XmlLoad(wxXmlNode *node, std::shared_ptr<Item> item) override;

	void Update(double elapsed) override;

	void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

	void CalculateScore(KillerBug *item);
};

#endif //PROJECT1_GAMELIB_KILLERBUG_H
