//
// Created by Terra Byte on 3/6/23.
//

#ifndef PROJECT1_SCOREBOARD_H
#define PROJECT1_SCOREBOARD_H


class ScoreBoard {
private:
    int mFixed = 0; ///< for fixed score
    int mMissed = 0; ///< for missed features
    int mOops = 0; /// for clicked feature

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
    void Clear();

    void ResetScoreBoard();
};


#endif //PROJECT1_SCOREBOARD_H
