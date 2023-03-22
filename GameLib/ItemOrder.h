/**
 * @file ItemOrder.h
 * @author Nicole Kuang
 *
 * Concrete visitor to correct the mItems display order
 */

#ifndef PROJECT1_GAMELIB_ITEMORDER_H
#define PROJECT1_GAMELIB_ITEMORDER_H

#include "ItemVisitor.h"
#include "Item.h"

/**
 * Concrete visitor to correct the mItems display order
 */
class ItemOrder : public ItemVisitor {
private:
	/// Temporary list for all programs in a level
	std::vector<std::shared_ptr<Item>> mPrograms;

	/// Temporary list for all bugs in a level
	std::vector<std::shared_ptr<Item>> mBugs;

public:
	void VisitGarbage(GarbageBug* bug) override;
	void VisitNull(NullBug* bug) override;
	void VisitRedundancy(RedundancyBug* bug) override;
	void VisitFeature(Feature* feature) override;
	void VisitProgram(Program* program) override;
	void VisitKiller(KillerBug* bug) override;
};

#endif //PROJECT1_GAMELIB_ITEMORDER_H
