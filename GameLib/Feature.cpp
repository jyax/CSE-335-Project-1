/**
 * @file Feature.cpp
 *
 * @author Jacob Yax
 */

#include "pch.h"
#include "Feature.h"

/// The feature sprite image
const std::wstring FeatureImageName = L"images/feature.png";

/// The splat image
const std::wstring FeatureSplatImageName = L"images/feature-splat.png";

/// Number of sprite images
const int FeatureNumSpriteImages = 7;


/**
 * Constructor
 * @param game The game we are in
 */
Feature::Feature(Game* game) : Bug(game, FeatureImageName)
{
}