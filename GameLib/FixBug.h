/**
 * @file FixBug.h
 * @author Nicole Kuang
 *
 * Concrete visitor to fix fat bugs
 */

#ifndef PROJECT1_GAMELIB_FIXBUG_H
#define PROJECT1_GAMELIB_FIXBUG_H

#include "ItemVisitor.h"
#include "Bug.h"

/**
 * Concrete visitor to fix fat bugs
 */
class FixBug : public ItemVisitor {
private:
	/// The fat bug to be fixed
	Bug* mBug = nullptr;

	/// Flag for whether this bug is fat or not
	bool mIsFat = false;

	/// the fat bug's broken/fixed code
	std::wstring mCode;

public:
	/**
	 * Getter for bug's fat status
	 * @return true if fat, false otherwise
	 */
	bool GetIsFat() {return mIsFat;}

	/**
	 * Getter for fat bug code
	 * @return the fat bug's code
	 */
	std::wstring GetCode() {return mCode;}

	void CheckCode(std::wstring code);

	void VisitGarbage(GarbageBug* bug) override;
	void VisitNull(NullBug* bug) override;
	void VisitRedundancy(RedundancyBug* bug) override;
	void VisitFeature(Feature* feature) override;
	void VisitProgram(Program* program) override;
	void VisitKiller(KillerBug* bug) override;
};

#endif //PROJECT1_GAMELIB_FIXBUG_H
