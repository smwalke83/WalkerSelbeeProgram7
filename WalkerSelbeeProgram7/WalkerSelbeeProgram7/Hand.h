// Programmer: Scott Walker
// Email: swalker62@student.cnm.edu
// File: Hand.h

#ifndef HAND_H
#define HAND_H

#include <string>
#include <array>
#include "Card.h"

using namespace std;

// Constant representing the maximum number of cards in a hand
const int MAX_CARDS{ 12 };

public class Hand
{
public:
	Hand() : numCards{ 0 } {}; // Default constructor, initializes numCards to zero
	void AddCard(Card c); // Adds a card to the hand
	string Show(bool isDealer, bool hideFirstCard); // Displays a string representing the hand
	bool BlackJack(); // Checks if the hand is "BlackJack" (21 with two cards)
	bool Under(int n); // Checks if the hand value is under the value of n
	int BestScore(); // Calculates the best score for the hand
	bool MustHit(); // Determines if it is a "Must Hit" hand for the dealer
	bool Busted(); // Determines if the hand is a bust
	void ClearHand() { showHand = ""; numCards = 0; }; // Resets the hand
private:
	int numCards; // Represents the number of cards in hand
	string showHand; // String representing the hand
	array <Card, MAX_CARDS> cards; // Array of cards, of size MAX_CARDS
};

#endif