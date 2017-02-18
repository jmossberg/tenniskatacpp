#include "gmock/gmock.h"
#include "Tennis.hpp"

class TennisTest : public ::testing::Test
{
public:
	Tennis t1;
	Tennis t2;
};

TEST_F(TennisTest, ScoresAreZeroAtStart)
{
	//Execute
	std::string score = t1.score();

	//Verify
	ASSERT_EQ(score, "Player 1: 0 Player 2: 0");
}

TEST_F(TennisTest, AbsoluteScoreDiffIsOne)
{
	//Execute
	t1.winBall("Player 1");
	t2.winBall("Player 2");
	int t1diff = t1.absDiff();
	int t2diff = t2.absDiff();

	//Verify
	ASSERT_EQ(t1diff, 1);
	ASSERT_EQ(t2diff, 1);
}

TEST_F(TennisTest, GetLeaderPoints)
{
	//Execute
	t1.winBall("Player 1");
	t1.winBall("Player 1");
	t1.winBall("Player 1");
	t2.winBall("Player 2");
	t2.winBall("Player 2");
	auto t1leader = t1.leaderPoints();
	auto t2leader = t2.leaderPoints();

	//Verify
	ASSERT_EQ(t1leader, 3);
	ASSERT_EQ(t2leader, 2);
}

TEST_F(TennisTest, StateIsDeuce)
{
	//Execute
	t1.winBall("Player 1");
	t1.winBall("Player 1");
	t1.winBall("Player 1");
	t1.winBall("Player 2");
	t1.winBall("Player 2");
	t1.winBall("Player 2");
	auto state = t1.state();

	//Verify
	ASSERT_EQ(state, DEUCE);

}

TEST_F(TennisTest, StateIsAdvantage)
{
	//Execute
	t1.winBall("Player 1");
	t1.winBall("Player 1");
	t1.winBall("Player 1");
	t1.winBall("Player 2");
	t1.winBall("Player 2");
	t1.winBall("Player 2");
	t1.winBall("Player 2");
	auto state = t1.state();

	//Verify
	ASSERT_EQ(state, ADVANTAGE);

}

TEST_F(TennisTest, StateIsWinner)
{
	//Execute
	t1.winBall("Player 1");
	t1.winBall("Player 1");
	t1.winBall("Player 2");
	t1.winBall("Player 2");
	t1.winBall("Player 2");
	t1.winBall("Player 2");
	auto state = t1.state();

	//Verify
	ASSERT_EQ(state, WINNER);

}

TEST_F(TennisTest, GetLeader)
{
	//Execute
	t1.winBall("Player 1");
	auto leader = t1.leader();

	//Verify
	ASSERT_EQ(leader, "Player 1");
}

TEST_F(TennisTest, GetLooser)
{
	//Execute
	t1.winBall("Player 1");
	auto looser = t1.looser();

	//Verify
	ASSERT_EQ(looser, "Player 2");
}

TEST_F(TennisTest, GetLooserPoints)
{
	//Execute
	t1.winBall("Player 1");
	t1.winBall("Player 1");
	t1.winBall("Player 2");
	t2.winBall("Player 2");
	t2.winBall("Player 2");
	auto t1looser = t1.looserPoints();
	auto t2looser = t2.looserPoints();

	//Verify
	ASSERT_EQ(t1looser, 1);
	ASSERT_EQ(t2looser, 0);
}

TEST_F(TennisTest, ConvertPointsToScore)
{
	ASSERT_EQ(t1.pointsAsScore(0), 0);
	ASSERT_EQ(t1.pointsAsScore(1), 15);
	ASSERT_EQ(t1.pointsAsScore(2), 30);
	ASSERT_EQ(t1.pointsAsScore(3), 40);
	ASSERT_EQ(t1.pointsAsScore(4), 40);
	ASSERT_EQ(t1.pointsAsScore(5), 40);
}

TEST_F(TennisTest, Player2WinsThreeFirstBalls_2)
{
	//Execute
	t1.winBall("Player 2");
	t1.winBall("Player 2");
	t1.winBall("Player 2");
	std::string score = t1.score();

	//Verify
	ASSERT_EQ(score, "Player 1: 0 Player 2: 40");
}

TEST_F(TennisTest, Deuce_2)
{
	//Execute
	t1.winBall("Player 2");
	t1.winBall("Player 2");
	t1.winBall("Player 2");
	t1.winBall("Player 1");
	t1.winBall("Player 1");
	t1.winBall("Player 1");
	std::string score = t1.score();

	//Verify
	ASSERT_EQ(score, "Deuce");
}

TEST_F(TennisTest, Player1Advantage_2)
{
	//Execute
	t1.winBall("Player 2");
	t1.winBall("Player 2");
	t1.winBall("Player 2");
	t1.winBall("Player 1");
	t1.winBall("Player 1");
	t1.winBall("Player 1");
	t1.winBall("Player 1");
	std::string score = t1.score();

	//Verify
	ASSERT_EQ(score, "Player 1 advantage");
}

TEST_F(TennisTest, Player2Wins_2)
{
	//Execute
	t1.winBall("Player 2");
	t1.winBall("Player 2");
	t1.winBall("Player 2");
	t1.winBall("Player 2");
	t1.winBall("Player 2");
	t1.winBall("Player 2");
	t1.winBall("Player 1");
	t1.winBall("Player 1");
	t1.winBall("Player 1");
	t1.winBall("Player 1");
	std::string score = t1.score();

	//Verify
	ASSERT_EQ(score, "Player 2 wins");
}
