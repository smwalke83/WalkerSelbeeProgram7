// Programmer: Scott Walker
// Email: swalker62@student.cnm.edu
// File: Hand.cpp

#include "Hand.h"
#include <sstream>
#include <stdexcept>

// Adds a card to the hand
void Hand::AddCard(Card c)
{
	// If the hand isn't full, the card is added and number of cards is incremented
	if (numCards < MAX_CARDS)
	{
		cards[numCards] = c;
		numCards++;
	}
	// Otherwise, throws an exception
	else
	{
		throw overflow_error("Hand cannot contain more than 12 cards.");
	}
}

// Returns a string representing the hand
string Hand::Show(bool isDealer, bool hideFirstCard)
{
	// String stream to build the message
	stringstream message;
	// Starts by showing if it's a player hand or dealer hand
	if (isDealer)
	{
		message << "Dealer's Hand: ";
	}
	else
	{
		message << "Player's Hand: ";
	}
	// If the first card is hidden, starts the card display loop at the second card. Displays the hidden card as "???"
	int loopStart = 0;
	if (hideFirstCard)
	{
		message << "\r\n???";
		loopStart = 1;
	}
	// Loops through the hand, displaying each card rank and suit
	for (int i = loopStart; i < numCards; i++)
	{
		message << "\r\n" << cards[i].GetValue() << " of " << cards[i].GetSuit();
	}
	// Adds the hand total to the bottom if the whole hand is displayed
	if (!hideFirstCard)
	{
		message << "\r\nHand Score: " << BestScore();
	}
	// Calculates the best score of the cards shown
	else
	{
		// Bool to track if the hand has one or more aces, and an int to track hand points
		bool hasAce = false;
		int points = 0;
		// Loops through the hand starting at the second card, adding the value of each card (aces only add one point, representing the minimum score). If there is an ace, the boolean is flipped to true
		for (int i = 1; i < numCards; i++)
		{
			if (cards[i].GetValue() == "Ace")
			{
				hasAce = true;
			}
			points += cards[i].GetIValue();
		}
		// If the hand contains an ace, checks to see if changing an ace's value to 11 is a valid hand. If so, that is done. By the nature of blackjack, adding ten more points (if there was another ace) will always bust, so this covers a hand with multiple aces.
		if (hasAce && points + 10 <= 21)
		{
			points += 10;
		}
		message << "\r\nShowing: " << points;
	}

	// Sets the message value to the showHand property and returns it
	showHand = message.str();
	return showHand;
}

// Checks for blackjack: if the best hand score is 21 and there are only 2 cards
bool Hand::BlackJack()
{
	return (BestScore() == 21 && numCards == 2);
}

// Checks if a hand's best score is under a certain value
bool Hand::Under(int n)
{
	return BestScore() < n;
}

// Calculates the hand's best possible score
int Hand::BestScore()
{
	// Bool to track if the hand has one or more aces, and an int to track hand points
	bool hasAce = false;
	int points = 0;
	// Loops through the hand, adding the value of each card (aces only add one point, representing the minimum score). If there is an ace, the boolean is flipped to true
	for (int i = 0; i < numCards; i++)
	{
		if (cards[i].GetValue() == "Ace")
		{
			hasAce = true;
		}
		points += cards[i].GetIValue();
	}
	// If the hand contains an ace, checks to see if changing an ace's value to 11 is a valid hand. If so, that is done. By the nature of blackjack, adding ten more points (if there was another ace) will always bust, so this covers a hand with multiple aces.
	if (hasAce && points + 10 <= 21)
	{
		points += 10;
	}
	// Returns the calculated value
	return points;
}

// Returns true if the best hand is under seventeen - meaning the dealer must hit
bool Hand::MustHit()
{
	return Under(17);
}

// Returns true if the best hand is over 21 - meaning the hand busted
bool Hand::Busted()
{
	return BestScore() > 21;
}
