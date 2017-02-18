#include <string>

typedef enum {NORMAL, DEUCE, ADVANTAGE, WINNER} State_T;

class Tennis
{
public:
	Tennis();
	void winBall(std::string player);
	int absDiff();
	int leaderPoints();
	int pointsAsScore(int points);
	std::string leader();
	State_T state();
	std::string score();
private:
	int p1;
	int p2;
};
