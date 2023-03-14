/**
 * @file Level.h
 * @author Jacob Meier
 * @author Nicole Kuang
 *
 * Main class for level0, level1, and level2
 */

#ifndef PROJECT1_GAMELIB_LEVEL_H
#define PROJECT1_GAMELIB_LEVEL_H

#include "Game.h"

/**
 * Main class for level0, level1, and level2
 */
class Level {
private:
	// If LevelThree object inherits these member vars, what to do then?

	// Have a game as a member variable?
	/// The game this level is part of
	Game *mGame = nullptr;

	/// The normal levels of the game
	enum class LevelNum {Zero, One, Two};

	/// The game level: Zero, One, Two
	LevelNum mNum = LevelNum::Zero;

    /// Measures elapsed time
    wxStopWatch mStopWatch;
    /// Logged Stop Watch time
    long mTime = 0;

    std::wstring mLevelName = L"Level";

public:
	/// Default constructor (disabled)
	Level();

	/// Copy constructor (disabled)
	Level(const Level &) = delete;

	/// Assignment operator (disabled)
	void operator=(const Level &) = delete;

	virtual ~Level();

	void Load(int mNum);

    void DrawLevelName(wxGraphicsContext &graphics);
};

#endif //PROJECT1_GAMELIB_LEVEL_H
