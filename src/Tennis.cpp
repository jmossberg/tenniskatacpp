#include "Tennis.hpp"

void Tennis::winBall(std::string player) {
	if("Player 1" == player) {
		increaseScore(p1);
	}
	if("Player 2" == player) {
		increaseScore(p2);
	}
}

std::string Tennis::getScore()
{
	return "Player1: " + std::to_string(p1) + " Player2: " + std::to_string(p2);
}

Tennis::Tennis(): p1{0}, p2{0}
{
}

void Tennis::increaseScore(int& score) {
	if(30 == score) {
		score += 10;
	} else {
		score += 15;
	}
}
