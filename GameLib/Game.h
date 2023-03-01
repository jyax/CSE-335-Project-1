/**
 * @file Game.h
 *
 * @author Gaya Kanagaraj
 *
 *  Class that implements a simple Game with items we can manipulate
 */
#ifndef PROJECT1_GAME_H
#define PROJECT1_GAME_H

#include <wx/graphics.h>
#include "PlayingArea.h"
/**
 * Class draws the game and describes its functionalities.
 */
class Game {
private:
    /// PlayingArea object
    PlayingArea mPlayingArea;
    /// Game area in virtual pixels
    const static int Width = 1250;

    /// Game area height in virtual pixels
    const static int Height = 1000;

    /// Shrink true or false
    bool mShrinked = true;

    /// offset x
    double mXOffset = 0;

    /// offset y
    double mYOffset = 0;

    /// scale x
    double mScale = 0;

public:
    Game();

    /** destructor */
    virtual ~Game() = default;

    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);

};


#endif //PROJECT1_GAME_H
