#include <string>

class Tennis
{
public:
	void winBall(std::string player);
	std::string getScore();
	Tennis();
private:
	int p1;
	int p2;
	void increaseScore(int& score);
};
