/**
 * @file PlayingArea.h
 * @author Gaya Kanagaraj
 * @author Nicole Kuang
 *
 * Playing area for the game
 */

#ifndef PROJECT1_PLAYINGAREA_H
#define PROJECT1_PLAYINGAREA_H

#include "Level.h"

class Game;

/**
 * Playing area for the game
 */
class PlayingArea {
private:
	/// The game this playing area is in
    Game* mGame;

	/// The list of pointers to items in the game (bugs, programs)
	std::vector<std::shared_ptr<Item>> mItems;

    /// The Level class for level 0
    std::shared_ptr<Level> mLevelZero = std::make_shared<Level>(this);

    /// The Level class for level 1
    std::shared_ptr<Level> mLevelOne = std::make_shared<Level>(this);

    /// The Level class for level 2
    std::shared_ptr<Level> mLevelTwo = std::make_shared<Level>(this);

    /// The Level class for level 3
    std::shared_ptr<Level> mLevelThree = std::make_shared<Level>(this);

    /// The current level
    std::shared_ptr<Level> mCurrentLevel = std::make_shared<Level>(this);

    ///Current level being played
    int mLevelNum;

    /// level complete boolean
    bool mLevelComplete = false;

    /// for level start boolean
    bool mLevelStart = false;

    /// for the deleted items vector
    std::vector<Item*> mDeleteItems;

    /// for keep track of level complete duration
    double mCompleteDuration = 0.0;


public:
    /**
     * default constructor for Playing Area
     */
    PlayingArea(){}

    void DrawPlayingArea(std::shared_ptr<wxGraphicsContext> graphics, const int width, const int height);

	void Add(std::shared_ptr<Item> item);

	/**
	 * Set game pointer
	 * @param game the game the playing area is in
	 */
	void SetGame(Game *game) { mGame = game; }

	/**
	 * Getter for the game
	 * @return a pointer to the game the playing area is set in
	 */
	Game* GetGame() {return mGame;}

    void SetLevel(int level);

	void MoveToFront(std::shared_ptr<Item> item);

	std::shared_ptr<Item> Click(double virX, double virY);

	void Accept(ItemVisitor* visitor);

    void LevelStart(bool value);

	/**
	 * Getter for whether the level has started or not
	 * @return true if a level has started, false otherwise
	 */
    bool GetLevelStart() {return mLevelStart;}

    void SetTextDuration(double duration);

    void Clear();

    void Update(double elapsed);

	void MoveItem(std::shared_ptr<Item> item);


    void RemoveItem(Item* bug);

    void DeleteItem();

    void CheckItem(Item *item);
    /**
     * returns current level number
     * @return int value
     */
    int GetLevelNumber(){return mLevelNum;}

    bool LevelComplete();

    void NextLevel();
};


#endif //PROJECT1_PLAYINGAREA_H
