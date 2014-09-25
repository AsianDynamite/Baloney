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

class AI{
public:
	std::vector<int> showHand();
	std::vector<int> showAndDelete(AI&);
	bool winGame();
	void pushHand(int i);
	void deleteVec(int);
	void displayHand(); 
	std::string AI::valueName(int i);
private:
	std::vector<int> hand;
};

class player {
public: 
	void displayHand();
	void playGame();
	bool winGame();
	void pushHand(int i);
	void pushVec(int);
	std::vector<int> showVec();
	void deleteVec();
	std::vector<int> showHand();
	std::string valueName(int i);
	int checkHand(int i); 
private:
	std::vector<int> hand;
	std::vector<int> currentVec;
};

class pile {
public: 
	void createDeck();
	void deal(player&, AI&);
	void takeVec(std::vector<int>);
	std::vector<int> showTable();
private:
	std::vector<int> table;
	std::vector<int> deck;
};

class game{
public:
	game();
	Value changeCard(Value);
	void pushVec(int i);
	void baloney(player&, game&, AI&, pile&);
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

int main()
{
	game bubpip;
	pile fart;
	player Bob;
	AI Alison;
	fart.createDeck();
	fart.deal(Bob, Alison);
	bubpip.baloney(Bob, bubpip, Alison, fart);
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
	std:: cout << "Your cards: " << std::endl;
	for(int i=0; i<hand.size(); i++)
	{
		std::cout << valueName(hand.at(i)) << std::endl;
	}
	std::cout << std:: endl;
}

void AI::displayHand()
{
	std:: cout << "AI's cards: " << std::endl;
	for(int i=0; i<hand.size(); i++)
	{
		std::cout << valueName(hand.at(i)) << std::endl;
	}
	std::cout << std:: endl;




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
std::string AI::valueName(int i)
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

Value game::changeCard(Value currentCard)
{
	switch(currentCard) {
	case ace: return two;
	case two: return three;
	case three: return four;
	case four: return five;
	case five: return six;
	case six:  return seven;
	case seven: return eight;
	case eight: return nine;
	case nine: return ten;
	case ten: return jack;
	case jack: return queen;
	case queen: return king;
	case king: return ace;
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
}

void AI::deleteVec(int i)
{
	hand.erase(hand.begin() +i);
}
std::vector<int> game::showVec()
{
	return game::currentVec;
}

void game::pushVec(int i)
{
	game::currentVec.push_back(i);
}

std::vector<int> player::showVec()
{
	return currentVec;
}

void player::deleteVec()
{
	currentVec.clear();
}

bool player::winGame()
{
	if(hand.size() == 0)
	{
		std::cout << "You win the game!";
		return false;
	}
	return true;
}

bool AI::winGame()
{
	if(hand.size() == 0)
	{
		std::cout << "You lose the game!";
		return false;
	}
	return true;
}

void player::pushVec(int i)
{
	currentVec.push_back(i);
}

void pile::takeVec(std::vector<int> A)
{
	for(int i=0; i < A.size(); i++)
	{
		table.push_back(A.at(i));
	}
}

std::vector<int> AI::showAndDelete(AI& AI)
{
	std::vector<int> A = AI.hand;
	AI.hand.clear();
	return A;
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
	if(S==("KING"))
	{
		return king;
	}
	else if(S==("QUEEN"))
	{
		return queen;
	}
	else if(S==("JACK"))
	{
		return jack;
	}
	else if(S==("TEN"))
	{
		return ten;
	}
	else if(S==("NINE"))
	{
		return nine;
	}
	else if(S==("EIGHT"))
	{
		return eight;
	}
	else if(S==("SEVEN"))
	{
		return seven;
	}
	else if(S==("SIX"))
	{
		return six;
	}
	else if(S==("FIVE"))
	{
		return five;
	}
	else if(S==("FOUR"))
	{
		return four;
	}
	else if(S==("THREE"))
	{
		return three;
	}
	else if(S==("TWO"))
	{
		return two;
	}
	else if(S==("ACE"))
	{
		return ace;
	}
	return 666;
}

int player::checkHand(int i)
{
	
	for(int j = 0; j< hand.size(); j++)
		{
			if( i == hand.at(j))
				{
					currentVec.push_back(hand.at(j)); 
					hand.erase(hand.begin()+j); 
					return 57;
				}

		}
	return 755;
}

void game::baloney(player& player, game& bubpip, AI& AI, pile& pile)
{
	
	std::string playerCard;
	std::string playerChoice;
	int checkVec = 0;
	do
	{
	do
	{
		player.displayHand();
		AI.displayHand(); 
		std::cout << "You have to play a " << valueName(playCard) << "." << " Only input strings!!!!";
		std::cin >> playerCard;
		checkVec = player.checkHand(stringToVal(playerCard));
	}while (stringToVal(playerCard)<0 || stringToVal(playerCard)>12 || checkVec == 755);
	
	playCard=changeCard(playCard);

	if(player.showVec().at(0)==playCard)
	{
		if(rand()%4==3)
		{
			AI.pushHand(player.showVec().at(0));
			std::cout << std::endl <<"The AI called Baloney!" << std::endl;
		}
	}
	else if(rand()%7==6)
	{
		player.pushHand(player.showVec().at(0));
		std::cout << std::endl << "The AI called Baloney!" << std::endl;
	}

	playCard=changeCard(playCard);

	for(int i=0; i<AI.showHand().size(); i++)
	{
		if(AI.showHand().at(i) == bubpip.seeCard())
		{
			bubpip.pushVec(AI.showHand().at(i));
			AI.deleteVec(i);
			std::cout << "The AI played a " << playCard << std::endl;
		}
	}
	if(bubpip.showVec().size() == 0)
	{
		bubpip.pushVec(AI.showHand().at(0));
		AI.deleteVec(0);
		std::cout << "The AI played a " << playCard << std::endl;

	}
	do
	{
	std::cout << std::endl << "Would you like to call Baloney?(yes/no)" << std::endl;
	std:: cin >> playerChoice;
	}while(playerChoice!="yes" && playerChoice!="no");

	if(playerChoice == "yes")
	{
		if(AI.showHand().at(0)==playCard)
			for(int i=0; i < pile.showTable().size(); i++)
			{
				pile.takeVec(AI.showAndDelete(AI));
			}
		else
		{
			for(int i=0; i < pile.showTable().size(); i++)
			{
				pile.takeVec(AI.showAndDelete(AI));
			}
		}
	}
}while(AI.winGame() && player.winGame());
}