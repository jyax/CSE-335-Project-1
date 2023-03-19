/**
 * @file Feature.cpp
 * @author Jacob Yax
 * @author Nicole Kuang
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
 * @param area The playing area we are in
 */
Feature::Feature(PlayingArea *area) : Bug(area, FeatureImageName, FeatureNumSpriteImages	)
{
	mSplatImage = std::make_shared<wxImage>(FeatureSplatImageName, wxBITMAP_TYPE_ANY);
}