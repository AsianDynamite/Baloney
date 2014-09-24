// Baloney.cpp : Defines the entry point for the console application.
//

#include "Card.h"
#include "Card.cpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <random>

class pile {
public: 
	void handout(int players);
	void shuffle(Value deck);
	void createDeck();
private:
	std::vector<int> buttsauce;
	std::vector<int> deck;
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
	pile fart;
	fart.createDeck();
	return 0;
}

void pile::createDeck()
{
	std::srand(time(NULL));
	for(int i=0; i<52; i++)
	{
		pile::deck.push_back(Value(i%13));
	}

	/*for(int i=0; i<pile::deck.size(); i++)
	{
		std::cout << pile::deck.at(i) << std::endl;
	}*/
	
	int i = std::rand();
	std::random_shuffle(pile::deck.begin(), pile::deck.end(), i);
	for(int i=0; i<pile::deck.size(); i++)
	{
		std::cout << pile::deck.at(i) << std::endl;
	}
}