/*
	Author:	Rick Magill, Mitchell Buzard, Daniel Potter
	Course:	COMP 220, Computer Programming II
	Date:	9/25/14
	Description:	This program allows the user to play a game of 
	baloney against an AI player. 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <random>
#include <string>

//This is the enumeration for the cards 
enum Value {ace, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king};

//This is a class for the AI player
class AI{
public:
	std::vector<int> showHand();
	std::vector<int> showAndDelete(AI&);
	bool winGame();
	void pushHand(int i);
	void deleteVec(int);
	std::string AI::valueName(int i);
private:
	std::vector<int> hand;
};

//This is a class for the user
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

//This is a class for the handling of the cards 
class pile {
public: 
	void createDeck();
	void deal(player&, AI&);
	void takeVec(std::vector<int>);
	std::vector<int> showTable();
	void throwTable(pile&);
private:
	std::vector<int> table;
	std::vector<int> deck;
};

//This is a class for playing the game
class game{
public:
	game();
	Value changeCard(Value);
	void pushVec(int i);

	//This is the game
	void baloney(player&, game&, AI&, pile&);
	int seeCard();
	int stringToVal(std::string);
	Value handOutCards();
	std::string valueName(int i);
	std::vector<int> showVec();
	void deleteVec();
 	~game();
private:
	Value playCard;
	std::vector<int> currentVec;
};

//This organized the classes 
int main()
{
	game bubpip;
	pile cards;
	player Bob;
	AI Alison;
	cards.createDeck();
	cards.deal(Bob, Alison);
	bubpip.baloney(Bob, bubpip, Alison, cards);
	return 0;
}

//This creates the deck
void pile::createDeck()
{
	std::srand(time(NULL));
	for(int i=0; i<52; i++)
	{
		//Fills the deck with card enums 
		pile::deck.push_back(Value(i%13));
	}
	//This shuffles the deck 
	std::random_shuffle(pile::deck.begin(), pile::deck.end());
}

//This deals out the cards to the player, AI, and table 
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

//This displays the player's hand
void player::displayHand()
{
	std:: cout << "Your cards: " << std::endl;
	for(int i=0; i<hand.size(); i++)
	{
		std::cout << valueName(hand.at(i)) << std::endl;
	}
	std::cout << std:: endl;
}

//This returns the current required card
int game::seeCard()
{
	return playCard;
}

//This converts the enum into a string for the player
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

//This converts the enum in a string for the AI
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

//This converts the enum into a string for the game
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

//This advances the current required card for the game
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

//This takes an integer and pushes it into the player's hand
void player::pushHand(int i)
{
	player::hand.push_back(i);
}

//This takes an integer and pushes it into the AI's hand
void AI::pushHand(int i)
{
	AI::hand.push_back(i);
}

//This returns the play's hand
std::vector<int> player::showHand()
{
	return player::hand;
};

//This returns the AI's hand
std::vector<int> AI::showHand()
{
	return AI::hand;
};

//This returns the cards that are on the table 
std::vector<int> pile::showTable()
{
	return pile::table;
}

//This removes a card from the AI's hand
void AI::deleteVec(int i)
{
	hand.erase(hand.begin() +i);
}

//This returns the vector for the AI
std::vector<int> game::showVec()
{
	return game::currentVec;
}

//This function pushes a card onto the table
void game::pushVec(int i)
{
	game::currentVec.push_back(i);
}

//This returns what the player is playing 
std::vector<int> player::showVec()
{
	return currentVec;
}

//This clears the cards that the player is playing 
void player::deleteVec()
{
	currentVec.clear();
}

//This tells the player when the have won
bool player::winGame()
{
	if(hand.size() == 0)
	{
		std::cout << "You win the game!";
		return false;
	}
	return true;
}

//This tells the player when they have lost 
bool AI::winGame()
{
	if(hand.size() == 0)
	{
		std::cout << "You lose the game!";
		return false;
	}
	return true;
}

//This pushes cards into the player's current played cards 
void player::pushVec(int i)
{
	currentVec.push_back(i);
}

//This pushes cards onto the table 
void pile::takeVec(std::vector<int> A)
{
	for(int i=0; i < A.size(); i++)
	{
		table.push_back(A.at(i));
	}
}

//This deletes the cards played by the AI
void game::deleteVec()
{
	currentVec.clear();
}

//This clears cards from the table
void pile::throwTable(pile& pile)
{
	pile.table.clear();
}

//This sets the intial card to be played
game::game()
{
	playCard = two;
}

//This is a destructor for the game
game::~game()
{	
	
}

//This changes the player's input into value enumeration
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

//Checks to see if the player has the card that they wish to play 
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

//This plays the game
void game::baloney(player& player, game& bubpip, AI& AI, pile& pile)
{
	
	std::string playerCard;
	std::string playerChoice;
	int checkVec = 0, blah = 0;

	//This do-while plays the game until someone wins
	do
	{

	//This do-while lets the player play 
	do
	{
		player.displayHand();
		std::cout << "You have to play a " << valueName(bubpip.playCard) << "." << " Only input strings!!!!";
		std::cin >> playerCard;
		checkVec = player.checkHand(stringToVal(playerCard));
		//This while checks if the card is good to be played
	}while (stringToVal(playerCard)<0 || stringToVal(playerCard)>12 || checkVec == 755);

	//This is the AI choosing to call baloney on the player
	if(player.showVec().at(0)==bubpip.playCard)
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

	//This changes the required card
	bubpip.playCard=changeCard(bubpip.playCard);

	//This is the AI playing
	for(int i=0; i<AI.showHand().size(); i++)
	{
		//This is if the AI has the card
		if(AI.showHand().at(i) == bubpip.seeCard())
		{
			bubpip.pushVec(AI.showHand().at(i));
			AI.deleteVec(i);
			std::cout << "The AI played a " << valueName(bubpip.playCard) << std::endl;
		}
	}
	//This is if the AI doesn't have the card
	if(bubpip.showVec().size() == 0)
	{
		bubpip.pushVec(AI.showHand().at(0));
		AI.deleteVec(0);
		std::cout << "The AI played a " << valueName(bubpip.playCard) << std::endl;
	}

	//This is the player calling baloney on the AI
	do
	{
	std::cout << std::endl << "Would you like to call Baloney?(yes/no)" << std::endl;
	std:: cin >> playerChoice;

	//Continue to ask until they say yes or no 
	}while(playerChoice!="yes" && playerChoice!="no");

	if(playerChoice == "yes")
	{
		//This checks if the player's guess was right
		if(bubpip.showVec().at(0)==bubpip.playCard)
		{
			for(int i=0; i < pile.showTable().size(); i++)
			{
				if(i ==0)
				{
					for(int j=0; j<bubpip.currentVec.size(); j++)
					{
						player.pushHand(bubpip.currentVec.at(j)); 
					}


					}
				player.pushHand(pile.showTable().at(i));
			}
		}

		//This is if the player guessed wrong
		else
		{
		
			for(int i=0; i < pile.showTable().size(); i++)
			{
				if(i ==0)
				{
					for(int j=0; j<bubpip.currentVec.size(); j++)
					{
						AI.pushHand(bubpip.currentVec.at(j)); 
					}


					}}
			for(int i=0; i < pile.showTable().size(); i++)
		{	
				AI.pushHand(pile.showTable().at(i));
			}
		//This emties the table after it has been distributed
		pile.throwTable(pile);
		}
	}

	//This increases the required card
	bubpip.playCard=changeCard(bubpip.playCard);

	//This dumps all of the vectors for the next turn
	pile.takeVec(player.showVec());
	player.deleteVec();
	pile.takeVec(bubpip.currentVec);
	bubpip.deleteVec();
}while(AI.winGame() && player.winGame());
}
	
