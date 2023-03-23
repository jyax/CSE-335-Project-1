/**
 * @file DeleteBug.h
 * @author Nicole Kuang
 *
 * Concrete visitor to increment score when bug reaches program
 */

#ifndef PROJECT1_GAMELIB_DELETEBUG_H
#define PROJECT1_GAMELIB_DELETEBUG_H

#include "ItemVisitor.h"

/**
 * Concrete visitor to increment score when bug reaches program
 */
class DeleteBug : public ItemVisitor {
private:

public:
	void VisitGarbage(GarbageBug* bug) override;
	void VisitNull(NullBug* bug) override;
	void VisitRedundancy(RedundancyBug* bug) override;
	void VisitFeature(Feature* feature) override;
	void VisitProgram(Program* program) override;
	void VisitKiller(KillerBug* bug) override;
};

#endif //PROJECT1_GAMELIB_DELETEBUG_H
