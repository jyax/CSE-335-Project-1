/**
 * @file Level.h
 * @author Jacob Meier
 * @author Nicole Kuang
 * @author Gaya Kanagaraj
 * @author Jacob Yax
 *
 * Main class for level0, level1, and level2
 */

#ifndef PROJECT1_GAMELIB_LEVEL_H
#define PROJECT1_GAMELIB_LEVEL_H

#include "Item.h"
class PlayingArea;
/**
 * Main class for level0, level1, and level2
 */
class Level {
private:


	/// The game this level is part of
	PlayingArea *mPlayingArea;

	/// The normal levels of the game
	enum class LevelNum {Zero, One, Two};

	/// The game level: Zero, One, Two
	LevelNum mNum = LevelNum::Zero;

    /// Measures elapsed time
    wxStopWatch mStopWatch;
    /// Logged Stop Watch time
    long mTime = 0;

    int mNumOfProgramme = 0; ///< number of programmes in the level
    int mNumOfBugs = 0; ///< number of bugs in the level
    int mNumofFeatures = 0; ///< number of features in the level

    wxString mType;  ///< for the levelstart text

public:

    void XmlProgram(wxXmlNode *node);
    void XmlBug(wxXmlNode *node);
    void XmlFeature(wxXmlNode *node);
    void XmlCode(wxXmlNode *node);
    void XmlBeginText(wxXmlNode *node);

	/// Default constructor
	Level() = delete;

    ///Constructor for level
    Level(PlayingArea* playingArea);

    /// Copy constructor
    Level(const Level &);

	/// Assignment operator (disabled)
	void operator=(const Level &) = delete;

	virtual ~Level();

	void Load(int mNum);

    void DrawLevelName(wxGraphicsContext &graphics);

    void ReadLevel(const std::wstring filename);

    /** get levelType for leveltext */
    wxString GetLevelType(){ return mType;}

	/**
	 * Getter for number of programs
	 * @return number of programs
	 */
    int GetNumOfProgram(){return mNumOfProgramme;}

	/**
	 * Getter for number of bugs
	 * @return number of bugs
	 */
    int GetNumOfBug(){return mNumOfBugs;}

	/**
	 * Getter for number of features
	 * @return number of features
	 */
    int GetNumOfFeature(){return mNumofFeatures;}

	/**
	 * Getter for level start text
	 * @return the level start text
	 */
    wxString GetMType(){return mType;}


};

#endif //PROJECT1_GAMELIB_LEVEL_H
