#include <string>

typedef enum {NORMAL, DEUCE, ADVANTAGE, WINNER} State_T;

class Tennis
{
public:
	void winBall(std::string player);
	std::string getScore();
	std::string score();
	int absDiff();
	int leaderPoints();
	int looserPoints();
	int pointsAsScore(int points);
	State_T state();
	std::string leader();
	std::string looser();
	Tennis();
private:
	int score1;
	int score2;
	int p1;
	int p2;
	void increaseScore(int& score);
};
