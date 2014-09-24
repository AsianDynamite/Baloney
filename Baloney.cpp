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
	void deal(player, AI);
	void createDeck();
	std::vector<int> showTable();
private:
	std::vector<int> table;
	std::vector<int> deck;
};

class player {
public: 
	void displayHand();
	void playGame();
	void winGame();
	std::vector<int> showHand();
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
	std::vector<int> showHand();
	void baloney();
	void playGame();
	void winGame();
private:
	std::vector<int> hand;
};
int main()
{
	pile fart;
	player Bob;
	AI Alison;
	fart.createDeck();
	fart.deal(Bob, Alison);
	Bob.displayHand();
	return 0;
}

void pile::createDeck()
{
	std::srand(time(NULL));
	for(int i=0; i<52; i++)
	{
		pile::deck.push_back(Value(i%13));
	}

	std::random_shuffle(pile::deck.begin(), pile::deck.end());
}

void pile::deal(player player, AI AI)
{
	for(int i=0; i<52; i++)
	{
		 if(i<20)
		 {
			player.player::showHand().push_back(deck.at(i));
		 }
		 else if(i>=20 && i<40)
		 {
			AI.AI::showHand().push_back(deck.at(i));
		 }
		 else
		 {
			table.push_back(deck.at(i));
		 }
	}
	
}

void player::displayHand()
{
	for(int i=0; i<hand.size(); i++)
	{
		std::cout << hand.at(i) << "  ";
	}
}

std::vector<int> player::showHand()
{
	return player::hand;
};

std::vector<int> AI::showHand()
{
	return AI::hand;
};

std::vector<int> pile::showTable()
{
	return pile::table;
};