/*
  File: Card.h
  Author:  Dorian P. Yeager
  Course:  COMP 220, Computer Programming II
  Date:    30 August 2013
  Description:  This file provides the definitions of the data types
                Suit, Value, and Card.
*/

#ifndef ___CARD_H
#define ___CARD_H

#include <string>
using std::string;

enum Suit {clubs, diamonds, hearts, spades};
enum Value {ace, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king};

class Card {
public:
	Card (Value faceValue=two, Suit suit = clubs):
		suit (suit), faceValue(faceValue) {}
	Suit getSuit() { return suit; }
	Value getValue() { return faceValue; }
	string suitName (Suit s);
private:
		Suit suit;
		Value faceValue;
};
#endif
