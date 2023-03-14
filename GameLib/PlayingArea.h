/**
 * @file PlayingArea.h
 * @author Gaya Kanagaraj
 *
 * Playing area for the game
 */
#ifndef PROJECT1_PLAYINGAREA_H
#define PROJECT1_PLAYINGAREA_H

#include "ScoreBoard.h"
#include "Level.h"
class Game;
/**
 * Playing area for the game
 */
class PlayingArea {
private:
    ScoreBoard mScoreBoard; ///< scorebaord object

    Game* mGame;

    /// The Level class for level 0
    std::shared_ptr<Level> mLevelZero = std::make_shared<Level>(mGame);

    /// The Level class for level 1
    std::shared_ptr<Level> mLevelOne = std::make_shared<Level>(mGame);

    /// The Level class for level 2
    std::shared_ptr<Level> mLevelTwo = std::make_shared<Level>(mGame);

    /// The Level class for level 3
    std::shared_ptr<Level> mLevelThree = std::make_shared<Level>(mGame);

    /// The current level
    std::shared_ptr<Level> mCurrentLevel = std::make_shared<Level>(mGame);

    ///Current level being played
    int mLevelNum;


public:
    /**
     * default constructor for Playing Area
     */
    PlayingArea(){}

    void DrawPlayingArea(std::shared_ptr<wxGraphicsContext> graphics, const int width, const int height);

    void DrawScoreBoard(std::shared_ptr<wxGraphicsContext> graphics);

    /**
     * Set level poiner
     */
    void SetGame(Game *game){mGame = game;}

    /**
     * It gets ItemList from Level and returns
     * @return ItemList
     */
    std::vector<std::shared_ptr<Item>> GetItemList()
    {
        return mCurrentLevel->GetItemList();
    }

    void SetLevelFile();

    void SetLevel(int level);



};


#endif //PROJECT1_PLAYINGAREA_H
