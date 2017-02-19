#include <string>

typedef enum {NORMAL, DEUCE, ADVANTAGE, WINNER} State_T;

class Tennis
{
public:
	Tennis(std::string newplayer1, std::string newplayer2);
	void winBall(std::string player);
	int absDiff();
	int leaderPoints();
	std::string call(int points);
	std::string leader();
	State_T state();
	std::string score();
private:
	std::string player1;
	std::string player2;
	int p1;
	int p2;
};
