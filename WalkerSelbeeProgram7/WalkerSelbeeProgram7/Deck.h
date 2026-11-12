// Programmer: Scott Walker
// Email: swalker62@student.cnm.edu
// File: Deck.h

#ifndef DECK_H
#define DECK_H

#include <array>
#include <random>
#include "Card.h"

using namespace std;

public class Deck
{
public:
	Deck(); // Default constructor
	void Shuffle(); // Shuffles the deck
	int RandomCard(); // Returns a random number 0-51
	void Deal(Card& c); // Deals a card
private:
	array <int, 52> cards; // Represents 52 cards
	int topCard; // Represents the index of the top card
	default_random_engine engine; // Randomizer engine
};

#endif