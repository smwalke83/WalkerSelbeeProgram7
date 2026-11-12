// Programmer: Scott Walker
// Email: swalker62@student.cnm.edu
// File: Deck.cpp

#include "Deck.h"
#include <chrono>
#include <utility>

using namespace std;

// Default constructor
Deck::Deck()
{
	// Seeding the engine using the current time
	unsigned int seed = static_cast<unsigned int>(chrono::system_clock::now().time_since_epoch().count());
	engine.seed(seed);
	// Creating the cards array - each index has a value from 0-51
	for (int i = 0; i < 52; i++)
	{
		cards[i] = i;
	}
	// Initializing topCard to zero
	topCard = 0;
	// Shuffling the deck
	Shuffle();
}

void Deck::Shuffle()
{
	// Loops 52 times
	for (int i = 0; i < 52; i++)
	{
		// Obtaining two random indexes to swap
		int indexOne = RandomCard();
		int indexTwo = RandomCard();
		// If the indexes are the same, gets a new random number until they don't match
		while (indexOne == indexTwo)
		{
			indexTwo = RandomCard();
		}
		// Swaps the cards at the two indexes
		swap(cards[indexOne], cards[indexTwo]);
	}
}

int Deck::RandomCard()
{
	// Creating a distribution for the randomizer to choose from
	uniform_int_distribution<int> dist(0, 51);
	// Returning a random value from 0-51
	return dist(engine);
}

void Deck::Deal(Card& c)
{
	// If the topCard value is over 34, the next hand could consume the remainder of the deck and it must be shuffled. Then the topCard value is reset to zero.
	if (topCard > 34)
	{
		topCard = 0;
		Shuffle();
	}
	// Creates a card from the value at the index indicated by topCard. This value is assigned to the Card object reference that was passed in
	c = Card(cards[topCard]);
	// Incrementing the topCard value
	topCard++;
}