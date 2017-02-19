#include "gmock/gmock.h"
#include "Tennis.hpp"

TEST(TennisTest, ScoresAreZeroAtStart)
{
    //Setup
    Tennis t1;

	//Execute
	std::string score = t1.score();

	//Verify
    //Zero points are called "love" in a Tennis game
	ASSERT_EQ(score, "Player 1: love Player 2: love");
}

