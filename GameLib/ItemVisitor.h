/**
 * @file ItemVisitor.h
 * @author Nicole Kuang
 * @author Gaya Kanagaraj
 *
 * Game item visitor base class
 */

#ifndef PROJECT1_GAMELIB_ITEMVISITOR_H
#define PROJECT1_GAMELIB_ITEMVISITOR_H

class GarbageBug;
class NullBug;
class RedundancyBug;
class Feature;
class Program;
class KillerBug;
class Bug;

/**
 * Game item visitor base class
 */
class ItemVisitor{
private:
    /// bug counter
    int mNumOfBugs = 0;

    /// Spalttered bugs
    int mSplatterBugs = 0;

public:
	/** Destructor */
	virtual ~ItemVisitor() {}


	/**
	 * Visit a GarbageBug object
	 * @param bug garbage bug to visit
	 */
	virtual void VisitGarbage(GarbageBug *bug){mNumOfBugs++;}

	/**
	 * Visit a NullBug object
	 * @param bug null bug to visit
	 */
	virtual void VisitNull(NullBug *bug) {mNumOfBugs++;}

	/**
	 * Visit a RedundancyBug object
	 * @param bug redundancy bug to visit
	 */
	virtual void VisitRedundancy(RedundancyBug *bug) {mNumOfBugs++;}

	/**
	 * Visit a Feature object
	 * @param feature feature 'bug' to visit
	 */
	virtual void VisitFeature(Feature *feature) {mNumOfBugs++;}

	/**
	 * Visit a Program object
	 * @param program program to visit
	 */
	virtual void VisitProgram(Program *program) {}

	/**
	 * Visit a KillerBug object
	 * @param bug Killer bug to visit
	 */
	virtual void VisitKiller(KillerBug *bug) {mNumOfBugs++;}

    /**
     * Get the number of bugs in the playing area
     * @return Number of bugs
     */
    int GetNumOfBugs() const { return mNumOfBugs; }

	/** Constructor */
	ItemVisitor() {}
};

#endif //PROJECT1_GAMELIB_ITEMVISITOR_H
