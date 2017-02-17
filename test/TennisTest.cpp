#include "gmock/gmock.h"
#include "Tennis.hpp"

class TennisTest : public ::testing::Test
{
public:
	Tennis t1;
};

TEST_F(TennisTest, ScoresAreZeroAtStart)
{
	//Execute
	std::string score = t1.getScore();

	//Verify
	ASSERT_EQ(score, "Player1: 0 Player2: 0");
}

TEST_F(TennisTest, Player1WinsFirstBall)
{
	//Execute
	t1.winBall("Player 1");
	std::string score = t1.getScore();

	//Verify
	ASSERT_EQ(score, "Player1: 15 Player2: 0");
}

TEST_F(TennisTest, Player1WinsTwoFirstBalls)
{
	//Execute
	t1.winBall("Player 1");
	t1.winBall("Player 1");
	std::string score = t1.getScore();

	//Verify
	ASSERT_EQ(score, "Player1: 30 Player2: 0");
}

TEST_F(TennisTest, Player1WinsThreeFirstBalls)
{
	//Execute
	t1.winBall("Player 1");
	t1.winBall("Player 1");
	t1.winBall("Player 1");
	std::string score = t1.getScore();

	//Verify
	ASSERT_EQ(score, "Player1: 40 Player2: 0");
}

TEST_F(TennisTest, Player2WinsFirstBall)
{
	//Execute
	t1.winBall("Player 2");
	std::string score = t1.getScore();

	//Verify
	ASSERT_EQ(score, "Player1: 0 Player2: 15");
}

TEST_F(TennisTest, Player2WinsTwoFirstBalls)
{
	//Execute
	t1.winBall("Player 2");
	t1.winBall("Player 2");
	std::string score = t1.getScore();

	//Verify
	ASSERT_EQ(score, "Player1: 0 Player2: 30");
}

TEST_F(TennisTest, Player2WinsThreeFirstBalls)
{
	//Execute
	t1.winBall("Player 2");
	t1.winBall("Player 2");
	t1.winBall("Player 2");
	std::string score = t1.getScore();

	//Verify
	ASSERT_EQ(score, "Player1: 0 Player2: 40");
}
