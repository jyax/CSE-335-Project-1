/**
 * @file ItemVisitor.h
 * @author Nicole Kuang
 *
 * Game item visitor base class
 */

#ifndef PROJECT1_GAMELIB_ITEMVISITOR_H
#define PROJECT1_GAMELIB_ITEMVISITOR_H

class GarbageBug;
class NullBug;
class RedundancyBug;
class Feature;

/**
 * Game item visitor base class
 */
class ItemVisitor
{
private:

public:
	/** Destructor */
	virtual ~ItemVisitor() {}

	/**
	 * Visit a GarbageBug object
	 * @param bug garbage bug to visit
	 */
	virtual void VisitGarbage(GarbageBug *bug) {}

	/**
	 * Visit a NullBug object
	 * @param bug null bug to visit
	 */
	virtual void VisitNull(NullBug *bug) {}

	/**
	 * Visit a RedundancyBug object
	 * @param bug redundancy bug to visit
	 */
	virtual void VisitRedundancy(RedundancyBug *bug) {}

	/**
	 * Visit a Feature object
	 * @param feature feature 'bug' to visit
	 */
	virtual void VisitFeature(Feature *feature) {}

protected:
	/** Constructor */
	ItemVisitor() {}
};

#endif //PROJECT1_GAMELIB_ITEMVISITOR_H
