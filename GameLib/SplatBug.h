/**
 * @file SplatBug.h
 * @author Nicole Kuang
 *
 * Concrete visitor to squash bugs
 */

#ifndef PROJECT1_GAMELIB_SPLATBUG_H
#define PROJECT1_GAMELIB_SPLATBUG_H

#include "ItemVisitor.h"
#include "Item.h"

/**
 * Concrete visitor to squash bugs
 */
class SplatBug : public ItemVisitor {
private:
	/// The game item clicked on
	//std::shared_ptr<Item> mItem;

	/// The game item to be squashed
	//Item* mSquashed = nullptr;

	bool mIsFeature = false;

	bool mIsProgram = false;

	bool mIsFat = false;

public:
	//SplatBug(std::shared_ptr<Item> item);

	void Squash();

	bool IsFeature() {return mIsFeature;}

	bool IsProgram() {return mIsProgram;}

	bool IsFat() {return mIsFat;}

	void VisitGarbage(GarbageBug* bug) override;
	void VisitNull(NullBug* bug) override;
	void VisitRedundancy(RedundancyBug* bug) override;
	void VisitFeature(Feature* feature) override;
	void VisitProgram(Program* program) override;
};

#endif //PROJECT1_GAMELIB_SPLATBUG_H
