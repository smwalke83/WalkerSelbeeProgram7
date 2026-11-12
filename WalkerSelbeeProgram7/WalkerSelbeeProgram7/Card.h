// Programmer: Scott Walker
// Email: swalker62@student.cnm.edu
// File: Card.h

#ifndef CARD_H
#define CARD_H

#include <string>

using namespace std;

public class Card
{
public:
	Card() = default; // Default constructor
	Card(int n); // Overloaded constructor
	void SetIValue(int val) { iValue = val; } // Sets the point value of a card
	string GetValue() const { return value; } // Returns the rank of a card
	int GetIValue() const { return iValue; } // Returns the point value of a card
	string GetSuit() const { return suit; } // Returns the suit of a card
private:
	int iValue{ 0 }; // Represents the point value of a card
	string value; // Represents the value printed on the card (2-10, Jack, Queen, King, Ace
	string suit; // Represents the suit of the card - Spades, Hearts, Clubs, Diamonds
};

#endif
