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

    /// for level start boolean
    bool mLevelStart = false;


public:
    /**
     * default constructor for Playing Area
     */
    PlayingArea(){}

    void DrawPlayingArea(std::shared_ptr<wxGraphicsContext> graphics, const int width, const int height);

	void Add(std::shared_ptr<Item> item);

	std::vector<std::shared_ptr<Item>> GetItemList() { return mItems; }
	/**
	 * Set level poiner
	 */
	void SetGame(Game *game) { mGame = game; }

    void SetLevelFile();

    void SetLevel(int level);

	void MoveToFront(std::shared_ptr<Item> item);

	std::shared_ptr<Item> SingleClick(double virX, double virY);

	std::shared_ptr<Item> DoubleClick(double virX, double virY);

	void Accept(ItemVisitor* visitor);

    void LevelStart(bool value);

    bool GetLevelStart(){ return mLevelStart;}

    void SetTextDuration(double duration);

    void Clear();

    void Update(double elapsed);

	void Squash(std::shared_ptr<Item> bug);

	void MoveItem(std::shared_ptr<Item> item);

	void FixCode(std::shared_ptr<Item> bug);

};


#endif //PROJECT1_PLAYINGAREA_H
