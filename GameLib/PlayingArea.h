/**
 * @file PlayingArea.h
 * @author Gaya Kanagaraj
 *
 * Playing area for the game
 */
#ifndef PROJECT1_PLAYINGAREA_H
#define PROJECT1_PLAYINGAREA_H

#include "ScoreBoard.h"

/**
 * Playing area for the game
 */
class PlayingArea {
private:
    ScoreBoard mScoreBoard; ///< scorebaord object

public:
    /**
     * default constructor for Playing Area
     */
    PlayingArea(){}

    void DrawPlayingArea(std::shared_ptr<wxGraphicsContext> graphics, const int width, const int height);


    void DrawScoreBoard(std::shared_ptr<wxGraphicsContext> graphics);
};


#endif //PROJECT1_PLAYINGAREA_H
