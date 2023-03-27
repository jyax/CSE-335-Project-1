/**
 * @file ScoreBoard.h
 * @author Gaya Kanagaraj
 * Class defines the score board
 */

#ifndef PROJECT1_SCOREBOARD_H
#define PROJECT1_SCOREBOARD_H

/**
 * Class for the score boards
 */
class ScoreBoard {
private:
    int mFixed = 0; ///< for fixed bugs
    int mMissed = 0; ///< for missed bugs
    int mOops = 0; ///< for clicked features

public:
    /** default construct that constructs the scoreboard */
    ScoreBoard();

    ///  Copy constructor (disabled)
    ScoreBoard(const ScoreBoard &) = delete;

    int GetFixedScore();

    int GetOopsScore();

    void CalculateScore(bool fixed, bool oops, bool missed);

    int GetMissedScore();

    void Draw(std::shared_ptr<wxGraphicsContext> graphics);

    void ResetScoreBoard();
};


#endif //PROJECT1_SCOREBOARD_H
