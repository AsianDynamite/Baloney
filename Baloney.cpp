// Baloney.cpp : Defines the entry point for the console application.
//

#include "Card.h"
#include "Card.cpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <random>



class player {
public: 
	void displayHand();
	void playGame();
	void winGame();
	void pushHand(int i);
	std::vector<int> showHand();
private:
	std::vector<int> hand;
};

class game{
public:
	game(Value playCard=two);
	void baloney();
	Value handOutCards();
	int seeCard();
	void changeCard();
	std::vector<int> showVec();
	void pushVec(int i);
private:
	Value playCard;
	std::vector<int> currentVec;
};

class AI{
public:
	std::vector<int> showHand();
	void baloney();
	void playGame(game&);
	void winGame();
	void pushHand(int i);
private:
	std::vector<int> hand;
};

class pile {
public: 
	void createDeck();
	void deal(player&, AI&);
	std::vector<int> showTable();
private:
	std::vector<int> table;
	std::vector<int> deck;
};

int main()
{
	game bubpip;
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

void pile::deal(player& player, AI& AI)
{
	for(int i=0; i<52; i++)
	{
		 if(i<20)
		 {
			 player.pushHand(deck.at(i));
		 }
		 else if(i>=20 && i<40)
		 {
			AI.pushHand(deck.at(i));
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

int game::seeCard()
{
	return playCard;
}

void game::changeCard()
{
	switch(playCard) {
	case ace: playCard = two;
	case two: playCard = three;
	case three: playCard = four;
	case four: playCard = five;
	case five: playCard = six;
	case six:  playCard = seven;
	case seven: playCard = eight;
	case eight: playCard = nine;
	case nine: playCard = ten;
	case ten: playCard = jack;
	case jack: playCard = queen;
	case queen: playCard = king;
	case king: playCard = ace;
	default: std::cout << "WTF are you doing";
	}
}

void player::pushHand(int i)
{
	player::hand.push_back(i);
}

void AI::pushHand(int i)
{
	AI::hand.push_back(i);
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

void AI::playGame(game& bubpip)
{
	for(int i=0; i<hand.size(); i++)
	{
		if(hand.at(i) == bubpip.seeCard)
		{
			bubpip.pushVec(hand.at(i));
			hand.erase(hand.begin() + i);
		}
	}
	if(bubpip.showVec().size() == 0)
	{
		bubpip.pushVec(hand.at(0));
		hand.erase(hand.begin());
	}
}

std::vector<int> game::showVec()
{
	return game::currentVec;
};

void game::pushVec(int i)
{
	game::currentVec.push_back(i);
}

void player::winGame()
{
	if(hand.size() == 0)
	{
		std::cout << "You win the game!";
	}
}

void AI::winGame()
{
	if(hand.size() == 0)
	{
		std::cout << "You lose the game!";
	}
}