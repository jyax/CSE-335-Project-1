/**
 * @file ScoreBoard.cpp
 * @author Gaya Kanagaraj
 */
#include "gtest/gtest.h"
#include "ScoreBoard.h"

// Define the unit test case for the ScoreBoard class
class ScoreBoardTest : public ::testing::Test {
protected:
    ScoreBoard sb;

    // Define a helper function to calculate scores
    void CalculateScores(bool fixed, bool oops, bool missed) {
        sb.CalculateScore(fixed, oops, missed);
    }

    // defines a helper for reset scoreboard
    void ResetScoreBoards(){
        sb.ResetScoreBoard();
    }
};

// Test the default constructor
TEST_F(ScoreBoardTest, DefaultConstructor) {
    // Assert that the initial values of the scoreboard are all 0
    EXPECT_EQ(sb.GetFixedScore(), 0);
    EXPECT_EQ(sb.GetMissedScore(), 0);
    EXPECT_EQ(sb.GetOopsScore(), 0);
}

// Test the CalculateScore method
TEST_F(ScoreBoardTest, CalculateScore) {
    // Calculate some scores
    CalculateScores(true, false, false); // new level
    CalculateScores(true, false, false); // not a new level
    CalculateScores(false, true, false);
    CalculateScores(false, false, true);
    CalculateScores(true, false, true);

    // Assert that the correct scores were calculated
    ASSERT_EQ(sb.GetFixedScore(), 3);
    ASSERT_EQ(sb.GetMissedScore(), 2);
    ASSERT_EQ(sb.GetOopsScore(), 1);
}

//Test the ResetScoreBoard function
TEST_F(ScoreBoardTest, ResetScoreBoard)
{
    ResetScoreBoards();
    // Assert that the correct scores were calculated
    ASSERT_EQ(sb.GetFixedScore(), 0);
    ASSERT_EQ(sb.GetMissedScore(), 0);
    ASSERT_EQ(sb.GetOopsScore(), 0);

    ASSERT_NE(sb.GetFixedScore(), 3);
    ASSERT_NE(sb.GetMissedScore(), 2);
    ASSERT_NE(sb.GetOopsScore(), 1);
}


