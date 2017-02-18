#include "Tennis.hpp"

void Tennis::winBall(std::string player) {
	if("Player 1" == player) {
		increaseScore(score1);
		p1 += 1;
	}
	if("Player 2" == player) {
		increaseScore(score2);
		p2 += 1;
	}
}

std::string Tennis::getScore()
{
	return "Player1: " + std::to_string(score1) + " Player2: " + std::to_string(score2);
}

Tennis::Tennis(): score1{0}, score2{0}, p1{0}, p2{0}
{
}

void Tennis::increaseScore(int& score) {
	if(40 == score) {

	} else if(30 == score) {
		score += 10;
	} else {
		score += 15;
	}
}

int Tennis::absDiff()
{
	int diff = p1 - p2;
	if (diff < 0) {
		diff = -diff;
	}
	return diff;
}

int Tennis::leaderPoints() {
	int leader_points = p1;

	if (p2 > leader_points) {
		leader_points = p2;
	}

	return leader_points;
}

State_T Tennis::state()
{
	State_T state = NORMAL;

	if(absDiff() == 0 && leaderPoints() >= 3) {
		state = DEUCE;
	}

	if(absDiff() == 1 && leaderPoints() >= 4) {
		state = ADVANTAGE;
	}

	if(absDiff() == 2 && leaderPoints() >= 4) {
		state = WINNER;
	}

	return state;
}

std::string Tennis::leader()
{
	std::string leader{""};

	if (p1 > p2) {
		leader = "Player 1";
	}

	if (p1 < p2) {
		leader = "Player 2";
	}

	return leader;
}

std::string Tennis::looser()
{
	std::string looser{""};

	if (p1 < p2) {
		looser = "Player 1";
	}

	if (p1 > p2) {
		looser = "Player 2";
	}

	return looser;
}

int Tennis::looserPoints() {
	int looser_points = p1;

	if (p2 < looser_points) {
		looser_points = p2;
	}

	return looser_points;
}

int Tennis::pointsAsScore(int points)
{
	if(0 == points) { return 0; }
	if(1 == points) { return 15; }
	if(2 == points) { return 30; }
	return 40;
}

std::string Tennis::score()
{
	std::string score{""};

	if(NORMAL == state()) {
		score = "Player 1: " + std::to_string(pointsAsScore(p1)) + " Player 2: " + std::to_string(pointsAsScore(p2));
	}

	if(DEUCE == state()) {
		score = "Deuce";
	}

	if(ADVANTAGE == state()) {
		score = leader() + " advantage";
	}

	if(WINNER == state()) {
		score = leader() + " wins";
	}

	return score;
}
