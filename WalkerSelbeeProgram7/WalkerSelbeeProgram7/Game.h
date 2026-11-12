// Programmer: Scott Walker
// Email: swalker62@student.cnm.edu
// File: Game.h

#ifndef GAME_H
#define GAME_H

#include "Deck.h"
#include "Hand.h"
#include "Logger.h"

// Constant representing the player's starting balance
const double STARTINGBALANCE = 1000.0;

// Struct to track player's balance, bet, and game statistics
struct PlayerData
{
	double balance{ STARTINGBALANCE };
	int bet{ 0 }; // I made this an integer because that matches the SetBet function signature
	int gamesPlayed{ 0 };
	int wins{ 0 };
	int losses{ 0 };
	int ties{ 0 };
};

public class Game
{
public:
	Game() { log.StartLog(data.balance); }; // Default constructor, starts the logger
	bool SetBet(int b); // Sets the player's bet
	void InitialDeal(); // Deals the initial hands
	string ShowPlayerHand() { return playerHand.Show(false, false); }; // Returns a string representing the player's hand
	string ShowDealerHand(bool hide) { return dealerHand.Show(true, hide); }; // Returns a string representing the dealer's hand - hide boolean determines if first card will be shown
	bool IsBlackJack() { return playerHand.BlackJack(); }; // Returns true if the player's hand is blackjack
	bool PlayerBusted() { return playerHand.Busted(); }; // Returns true if the player's best score is above 21
	bool PlayerContinues() { return playerHand.Under(22); }; // Returns true if the player's best score is 21 or below
	void PlayerHits(); // Deals the player a new card
	string PlayerWins(); // Returns a string showing the results of the player winning
	bool DealerContinues(); // Deals the dealer a new card
	string DealerWins(); // Returns a string showing the results of the dealer winning
	string Tie(); // Returns a string showing the results of a tie
	string ShowResults(); // Evaluates the hands and shows the result
	void ClearHands() { playerHand.ClearHand(); dealerHand.ClearHand(); }; // Resets the player and dealer hands
	bool IsLogOpened() { return log.IsLogOpen(); } // Getter to determine if the log is open
	void EndGame(); // Ends the game and sends a summary to the logger
private:
	Deck deck; // Object representing the card deck
	Hand playerHand; // Object representing the player's hand
	Hand dealerHand; // Object representing the dealer's hand
	Logger log; // Object to log application data
	PlayerData data; // Struct containing player data
};

#endif