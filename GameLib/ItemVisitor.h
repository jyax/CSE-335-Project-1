/**
 * @file ItemVisitor.h
 * @author Nicole Kuang
 *
 * Game item visitor base class
 */

#ifndef PROJECT1_GAMELIB_ITEMVISITOR_H
#define PROJECT1_GAMELIB_ITEMVISITOR_H

/**
 * Game item visitor base class
 */
class ItemVisitor
{
private:

public:
	/** Destructor */
	virtual ~ItemVisitor() {}

protected:
	/** Constructor */
	ItemVisitor() {}
};

#endif //PROJECT1_GAMELIB_ITEMVISITOR_H
