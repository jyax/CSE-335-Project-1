/**
 * @file Feature.h
 * @author Jacob Yax
 * @author Nicole Kuang
 * @author Gaya Kanagaraj
 *
 * Feature class to represent the Feature "Bug" that is not supposed to be clicked on.
 */

#ifndef PROJECT1_FEATURE_H
#define PROJECT1_FEATURE_H

#include "Bug.h"
/**
 * Feature class to represent the Feature "Bug" that is not supposed to be clicked on.
 */
class Feature : public Bug{
private:


public:
    /// Default Constructor (disabled)
    Feature() = delete;

    /// Copy Constructor (disabled)
    Feature(const Feature &) = delete;

	Feature(PlayingArea *area);

	/**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
	void Accept(ItemVisitor* visitor) override {visitor->VisitFeature(this);}
    void XmlLoad(wxXmlNode *node, std::shared_ptr<Program> program) override;

    void Update(double elapsed) override;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
};


#endif //PROJECT1_FEATURE_H
