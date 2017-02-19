#include "gmock/gmock.h"
#include "Tennis.hpp"

class TennisTest : public ::testing::Test
{
public:
	Tennis t1{"Player 1", "Player 2"};
	Tennis t2{"Player 1", "Player 2"};
};

TEST_F(TennisTest, ScoresAreZeroAtStart)
{
	//Execute
	std::string score = t1.score();

	//Verify
	ASSERT_EQ(score, "Player 1: love Player 2: love");
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

TEST_F(TennisTest, PointsToCorrespondingCall)
{
	ASSERT_EQ(t1.call(0), "love");
	ASSERT_EQ(t1.call(1), "15");
	ASSERT_EQ(t1.call(2), "30");
	ASSERT_EQ(t1.call(3), "40");
	ASSERT_EQ(t1.call(4), "40");
	ASSERT_EQ(t1.call(5), "40");
}

TEST_F(TennisTest, Player2WinsThreeFirstBalls)
{
	//Execute
	t1.winBall("Player 2");
	t1.winBall("Player 2");
	t1.winBall("Player 2");
	std::string score = t1.score();

	//Verify
	ASSERT_EQ(score, "Player 1: love Player 2: 40");
}

TEST_F(TennisTest, Deuce)
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

TEST_F(TennisTest, Player1Advantage)
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

TEST_F(TennisTest, Player2Wins)
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

TEST_F(TennisTest, Player2WinsAfterDeuce)
{
	//Execute
	t1.winBall("Player 2");
	ASSERT_EQ(t1.score(), "Player 1: love Player 2: 15");
	t1.winBall("Player 1");
	ASSERT_EQ(t1.score(), "Player 1: 15 Player 2: 15");
	t1.winBall("Player 2");
	ASSERT_EQ(t1.score(), "Player 1: 15 Player 2: 30");
	t1.winBall("Player 1");
	ASSERT_EQ(t1.score(), "Player 1: 30 Player 2: 30");
	t1.winBall("Player 2");
	ASSERT_EQ(t1.score(), "Player 1: 30 Player 2: 40");
	t1.winBall("Player 1");
	ASSERT_EQ(t1.score(), "Deuce");
	t1.winBall("Player 2");
	ASSERT_EQ(t1.score(), "Player 2 advantage");
	t1.winBall("Player 1");
	ASSERT_EQ(t1.score(), "Deuce");
	t1.winBall("Player 2");
	ASSERT_EQ(t1.score(), "Player 2 advantage");
	t1.winBall("Player 2");
	ASSERT_EQ(t1.score(), "Player 2 wins");
}
