/**
 * @file Feature.cpp
 * @author Jacob Yax
 * @author Nicole Kuang
 * @author Gaya Kanagraj
 */

#include "pch.h"
#include "Feature.h"

using  namespace std;
/// The feature sprite image
const std::wstring FeatureImageName = L"images/feature.png";

/// The splat image
const std::wstring FeatureSplatImageName = L"images/feature-splat.png";

/// Number of sprite images
const int FeatureNumSpriteImages = 7;


/**
 * Constructor
 * @param area The playing area we are in
 */
Feature::Feature(PlayingArea *area) : Bug(area, FeatureImageName, FeatureNumSpriteImages	)
{
	mSplatImage = std::make_shared<wxImage>(FeatureSplatImageName, wxBITMAP_TYPE_ANY);
}
/**
* Load attributes for a Feature
 *
 * @param node The xml node we are loading attributes from
 * @param item destination for the bug
*/
void Feature::XmlLoad(wxXmlNode *node, std::shared_ptr<Item> item)
{
    Bug::XmlLoad(node, item);
}
/**
 * Draw this bug
 * @param graphics graphics context to draw on
 */
void Feature::Draw(shared_ptr<wxGraphicsContext> graphics)
{
    Bug::Draw(graphics);
}
/**
 * Handle updates in time of the bugs
 *
 * This is called before we draw and allows us to
 * move the bugs
 * @param elapsed Time elapsed since the class call
 */
void Feature::Update(double elapsed) // Change image swatch images here!!!
{
    Bug::Update(elapsed);
}