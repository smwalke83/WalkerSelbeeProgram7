// Programmer: Scott Walker
// Email: swalker62@student.cnm.edu
// File: Card.cpp

#include "Card.h"

#include <stdexcept>

Card::Card(int n)
{
	if (n < 0 || n > 51)
	{
		throw std::invalid_argument("Card number must be between 0 and 51."); // Thrown if the constructor is called with an invalid number
	}
	int iSuit = n / 13; // Results in a value of 0-3, used to assign suit
	iValue = n % 13 + 1; // Results in a value of 1-13, representing card values

	// Sets the suit based on the value of iSuit - 0 for spades, 1 for hearts, 2 for clubs, 3 for diamonds
	switch (iSuit)
	{
	case 0:
		suit = "Spades";
		break;
	case 1:
		suit = "Hearts";
		break;
	case 2:
		suit = "Clubs";
		break;
	case 3:
		suit = "Diamonds";
		break;
	}

	// Sets the ranks of the cards based on iValue - 2-10, Jack, Queen, King, Ace
	switch (iValue)
	{
	case 1:
		value = "Ace";
		break;
	case 2:
		value = "Two";
		break;
	case 3:
		value = "Three";
		break;
	case 4:
		value = "Four";
		break;
	case 5:
		value = "Five";
		break;
	case 6:
		value = "Six";
		break;
	case 7:
		value = "Seven";
		break;
	case 8:
		value = "Eight";
		break;
	case 9:
		value = "Nine";
		break;
	case 10:
		value = "Ten";
		break;
	case 11:
		value = "Jack";
		break;
	case 12:
		value = "Queen";
		break;
	case 13:
		value = "King";
		break;
	}

	// If the card's rank value is over ten, sets the iValue back to 10, as that is how many points it is worth
	if (iValue > 10)
	{
		iValue = 10;
	}
}