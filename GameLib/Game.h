/**
 * @file Game.h
 * @author Gaya Kanagaraj
 * @author Nicole Kuang
 *
 * Class that implements a simple Game with items we can manipulate
 */
#ifndef PROJECT1_GAME_H
#define PROJECT1_GAME_H

#include <random>
#include "PlayingArea.h"
#include "ScoreBoard.h"
#include "Item.h"

/**
 * Class draws the game and describes its functionalities.
 */
class Game {
private:
    /// PlayingArea object
    PlayingArea mPlayingArea;

	ScoreBoard mScoreBoard; ///< scoreboard object

    /// Game area in virtual pixels
    const static int Width = 1250;

    /// Game area height in virtual pixels
    const static int Height = 1000;

    /// Shrink true or false
    bool mShrinked = false;

    /// offset x
    double mXOffset = 0;

    /// offset y
    double mYOffset = 0;

    /// scale x
    double mScale = 0;

	/// x virtual coordinates
	double mXVirtual = 0;

	/// y virtual coordinates
	double mYVirtual = 0;

    ///Current level being played
    bool mLevel = false;

	///Enable items to be dragged around the screen
	bool mEnableDrag = false;

    /// Random number generator
    std::mt19937 mRandom;

public:
    Game();

    /** destructor */
    virtual ~Game() = default;

    /**
     * set the shrink
     */
    void SetShrinked(){ mShrinked = !mShrinked;}

    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);

	std::shared_ptr<Item> SingleClick(int x, int y);

	std::shared_ptr<Item> DoubleClick(int x, int y);

	void MoveToFront(std::shared_ptr<Item> item);

	void Update(double elapsed);
    void SetLevel(int level);

	/**
	 * Getter enable drag
	 * @return boolean for if items can be dragged or not
	 */
	bool getEnableDrag() {return mEnableDrag; }

	/**
	 * Route the visitor from Game to PlayingArea
	 * @param visitor a visitor for the collection
	 */
	void Accept(ItemVisitor* visitor) {mPlayingArea.Accept(visitor);}

	/**
	 * Getter for the scoreboard
	 * @return a pointer to the scoreboard
	 */
	ScoreBoard* GetScoreboard() {return &mScoreBoard;}

	void MoveItem(std::shared_ptr<Item> item);

	void Squash(std::shared_ptr<Item> bug);

	void FixCode(std::shared_ptr<Item> bug);

    /**
    * Get the random number generator
   * @return Pointer to the random number generator
   */
    std::mt19937 &GetRandom() {return mRandom;}
};

#include <wx/graphics.h>

#endif //PROJECT1_GAME_H
