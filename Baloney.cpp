// Baloney.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <random>
#include <string>

enum Suit {clubs, diamonds, hearts, spades};
enum Value {ace, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king};

class player {
public: 
	void displayHand();
	void playGame();
	void winGame();
	void pushHand(int i);
	std::vector<int> showHand();
	std::string valueName(int i);
	int checkHand(int i, game&); 
private:
	std::vector<int> hand;
};

class game{
public:
	game();
	void changeCard();
	void pushVec(int i);
	void baloney(player&, game&);
	int seeCard();
	int stringToVal(std::string);
	Value handOutCards();
	std::string valueName(int i);
	std::vector<int> showVec();
	~game();
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
	bubpip.baloney(Bob, bubpip);
	/*fart.createDeck();
	fart.deal(Bob, Alison);
	Bob.displayHand();*/
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
		std::cout << valueName(hand.at(i)) << "  ";
	}
}

int game::seeCard()
{
	return playCard;
}

std::string player::valueName(int i)
{
	switch(i) {
	case ace: return "Ace";
	case two: return "Two";
	case three: return "Three";
	case four: return "Four";
	case five: return "Five";
	case six:  return "Six";
	case seven: return "Seven";
	case eight: return "Eight";
	case nine: return "Nine";
	case ten: return "Ten";
	case jack: return "Jack";
	case queen: return "Queen";
	case king: return "King";
	default: throw std::out_of_range("Face value out of range");
	}
}

std::string game::valueName(int i)
{
	switch(i) {
	case ace: return "Ace";
	case two: return "Two";
	case three: return "Three";
	case four: return "Four";
	case five: return "Five";
	case six:  return "Six";
	case seven: return "Seven";
	case eight: return "Eight";
	case nine: return "Nine";
	case ten: return "Ten";
	case jack: return "Jack";
	case queen: return "Queen";
	case king: return "King";
	default: throw std::out_of_range("Face value out of range");
	}
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
		if(hand.at(i) == bubpip.seeCard())
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

game::game()
{
	playCard = two;
}
game::~game()
{	
	
}





int game::stringToVal(std::string S)
{
	for(int i=0; i < S.size(); i++)
	{
		S[i] = toupper(S[i]);
	}
	if(S.compare("KING"))
	{
		return king;
	}
	else if(S.compare("QUEEN"))
	{
		return queen;
	}
	else if(S.compare("JACK"))
	{
		return jack;
	}
	else if(S.compare("TEN"))
	{
		return ten;
	}
	else if(S.compare("NINE"))
	{
		return nine;
	}
	else if(S.compare("EIGHT"))
	{
		return eight;
	}
	else if(S.compare("SEVEN"))
	{
		return seven;
	}
	else if(S.compare("SIX"))
	{
		return six;
	}
	else if(S.compare("FIVE"))
	{
		return five;
	}
	else if(S.compare("FOUR"))
	{
		return four;
	}
	else if(S.compare("THREE"))
	{
		return three;
	}
	else if(S.compare("TWO"))
	{
		return two;
	}
	else if(S.compare("ACE"))
	{
		return ace;
	}
	return 666;
}

int player::checkHand(int i, game& bubpip)
{
	
	for(int j = 0; j< hand.size(); j++)
		{
			if( i == hand.at(j))
				{
					bubpip.pushVec(hand.at(j)); 
					hand.erase(hand.begin()+j); 
					return 57;
				}

		}

	return 75; 
}

void game::baloney(player& player, game& bubpip)
{
	
	std::string playerCard;
	do
	{
		std::cout << "You have to play a " << valueName(playCard) << "." << " Only input strings!!!!";
		player.displayHand();
		std::cin >> playerCard;
	}while ((stringToVal(playerCard) <= 0) || (stringToVal(playerCard) >= 12) && player.checkHand(stringToVal(playerCard), bubpip) != 57);
	
}