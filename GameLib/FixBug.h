/**
 * @file FixBug.h
 * @author Nicole Kuang
 *
 * Concrete visitor to fix fat bugs
 */

#ifndef PROJECT1_GAMELIB_FIXBUG_H
#define PROJECT1_GAMELIB_FIXBUG_H

#include "ItemVisitor.h"

/**
 * Concrete visitor to fix fat bugs
 */
class FixBug : public ItemVisitor {
private:

public:
	void VisitGarbage(GarbageBug* bug) override;
	void VisitNull(NullBug* bug) override;
	void VisitRedundancy(RedundancyBug* bug) override;
	void VisitFeature(Feature* feature) override;
	void VisitProgram(Program* program) override;
};

#endif //PROJECT1_GAMELIB_FIXBUG_H
