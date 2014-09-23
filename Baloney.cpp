// Baloney.cpp : Defines the entry point for the console application.
//

#include "Card.h"
#include "Card.cpp"
#include <iostream>
#include <vector>

class pile {
public: 
	void handout(int players);
	void shuffle(Value deck[]);
private:
	std::vector<Value> pile;
	Value deck[];
};

class player {
public: 
	void displayHand();
	void playGame();
	void winGame();
private:
	std::vector<int> hand;
};

class game{
public:
	void baloney();
	Value handOutCards();
private:
	Value playCard;
};

class AI{
public:
	void baloney();
	void playGame();
	void winGame();
private:
	std::vector<int> hand;
};
int main()
{
	return 0;
}

