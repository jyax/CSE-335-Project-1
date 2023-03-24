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
	PlayingArea *mPlayingArea = nullptr;

    int mNumOfProgramme = 0; ///< number of programmes in the level
    int mNumOfBugs = 0; ///< number of bugs in the level
    int mNumofFeatures = 0; ///< number of features in the level

    wxString mType;  ///< for the levelstart text

    /// Duration that the text appears
    double mTextDuration = 0;

    ///Checker variable for start text.
    bool mIsStart = true;

	/// The level states
    enum State{
        STARTING,
        PLAYING,
        FINISHED
    };

	/// The current state of the level
    State mState = State::STARTING;

    /// program this bug belongs to
    std::shared_ptr<Program> mProgram;

	/// Temporary list for programs when loading
	std::vector<std::shared_ptr<Item>> mTempPrograms;

	/// Temporary list for bugs when loading
	std::vector<std::shared_ptr<Item>> mTempBugs;

public:
    void XmlBug(wxXmlNode *node);
    void XmlFeature(wxXmlNode *node);

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

    void DrawLevelName(std::shared_ptr<wxGraphicsContext> &graphics);

    void ReadLevel(const std::wstring filename);

	/**
	 * Getter for number of programs
	 * @return number of programs
	 */
    int GetNumOfProgram() {return mNumOfProgramme;}

	/**
	 * Getter for number of bugs
	 * @return number of bugs
	 */
    int GetNumOfBug() {return mNumOfBugs;}

	/**
	 * Getter for number of features
	 * @return number of features
	 */
    int GetNumOfFeature() {return mNumofFeatures;}

	/**
	 * Getter for level start text
	 * @return the level start text
	 */
    wxString GetMType() {return mType;}

    void SetTextDuration(double duration);

    void Update(double elapsed);

    void XmlProgram(wxXmlNode *node);

    void DrawLevelFinish(std::shared_ptr<wxGraphicsContext> &graphics);
};

#endif //PROJECT1_GAMELIB_LEVEL_H
