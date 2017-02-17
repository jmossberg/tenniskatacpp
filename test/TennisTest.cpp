#include "gmock/gmock.h"
#include "Tennis.hpp"


TEST(TennisTest, ScoresAreZeroAtStart)
{
	//Setup
	Tennis t1;

	//Execute
	std::string score = t1.getScore();

	//Verify
	ASSERT_EQ(score, "Player1: 0 Player2: 0");
}
