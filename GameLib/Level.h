/**
 * @file Level.h
 * @author Jacob Meier
 * @author Nicole Kuang
 * @Gaya Kanagaraj
 *
 * class that loads xmlfile and passes the tags to the appropriate item
 */

#ifndef PROJECT1_GAMELIB_LEVEL_H
#define PROJECT1_GAMELIB_LEVEL_H

#include "Item.h"
class Game;
/**
 * Main class for level0, level1, and level2
 */
class Level {
private:
	// If LevelThree object inherits these member vars, what to do then?

	// Have a game as a member variable?
	/// The game this level is part of
	Game *mGame ;


    int mNumOfProgramme = 0; ///< number of programmes in the level
    int mNumOfBugs = 0; ///< number of bugs in the level
    int mNumofFeatures = 0; ///< number of features in the level


    wxString mType;  ///< for the levelstart text

    /// The normal levels of the game
	enum class LevelNum {Zero, One, Two};

    ///Items in the playing area
    std::vector<std::shared_ptr<Item>> mItemList;


    /// The game level: Zero, One, Two
	LevelNum mNum = LevelNum::Zero;

public:
    /// Default constructor (disabled)
    Level() = delete;

    /// Copy constructor
    Level(const Level &);

    ///Constructor for level
    Level(Game* game);

	/// Assignment operator (disabled)
	void operator=(const Level &) = delete;

    void ReadLevel(const std::wstring filename);

    /**
    * function that returns the item list
    */
    std::vector<std::shared_ptr<Item>> GetItemList() {
        return mItemList;
    }

    /** get levelType for leveltext */
    wxString GetLevelType(){ return mType;}

	virtual ~Level();

    int GetNumOfBug(){return mNumOfBugs;}
    int GetNumOfFeature(){return mNumofFeatures;}
    int GetNumOfProgram(){return mNumOfProgramme;}
    wxString GetmType(){return mType;}

    void XmlProgram(wxXmlNode *node);
    void XmlBug(wxXmlNode *node);
    void XmlFeature(wxXmlNode *node);
    void XmlBeginText(wxXmlNode *node);


	//void Load(int mNum);
};

#endif //PROJECT1_GAMELIB_LEVEL_H
