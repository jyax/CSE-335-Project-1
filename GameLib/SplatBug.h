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

public:
	void VisitGarbage(GarbageBug* bug) override;
	void VisitNull(NullBug* bug) override;
	void VisitRedundancy(RedundancyBug* bug) override;
	void VisitFeature(Feature* feature) override;
	void VisitProgram(Program* program) override;
	void VisitKiller(KillerBug* bug) override;
};

#endif //PROJECT1_GAMELIB_SPLATBUG_H
