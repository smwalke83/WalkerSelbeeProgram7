// Programmer: Scott Walker
// Email: swalker62@student.cnm.edu
// File: Game.cpp

#include "Game.h"
#include <sstream>
#include <iomanip>

// Sets the player's bet
bool Game::SetBet(int b)
{
    // If the bet is valid (above zero, less than the player's balance), sets the bet to that value and subtracts it from the player's balance
    if (b > 0 && b <= data.balance)
    {
        data.bet = b;
        data.balance -= data.bet;
        return true;
    }
    // An invalid bet will return false
    else
    {
        return false;
    }
}

// Deals the initial hands
void Game::InitialDeal()
{
    // Deals one card to each player per loop, loops twice
    for (int i = 0; i < 2; i++)
    {
        // Creates two card objects which are populated by the Deal method, then adds one to the player hand and one to the dealer hand
        Card card1, card2;
        deck.Deal(card1);
        playerHand.AddCard(card1);
        deck.Deal(card2);
        dealerHand.AddCard(card2);
    }
}

// Deals the player a card
void Game::PlayerHits()
{
    // Creates a card object, populates it with the deal method, then adds it to the player hand
    Card card;
    deck.Deal(card);
    playerHand.AddCard(card);
}

// Returns a string representing a player win
string Game::PlayerWins()
{
    // Creating a string stream to build the message
    stringstream message;
    message << fixed << setprecision(2);
    // Setting the payout to the value of the bet
    double payout = data.bet;
    // Start of the message
    message << "Player wins! Bet: $" << data.bet;
    // If the player hit blackjack, that is added to the message and the payout is multiplied by 1.5
    if (playerHand.BlackJack())
    {
        message << "\r\nBlackJack! Payout is 1.5x bet!";
        payout *= 1.5;
    }
    // Adding the initial bet back to the payout - this was subtracted when the bet was made. Then adding the payout to the player's balance
    payout += data.bet;
    data.balance += payout;
    // Updating the message with the winnings
    message << "\r\nYou won $" << payout - data.bet << "! Current balance: $" << data.balance;
    // Incrementing wins and games played
    data.wins++;
    data.gamesPlayed++;
    // Returning the message as a string
    return message.str();
}

// Returns true if the dealer must hit, as well as dealing a card to the dealer. Returns false if the dealer must stay.
bool Game::DealerContinues()
{
    if (dealerHand.MustHit())
    {
        // Creates a card object, populates it with the deal method, the adds it to the dealer's hand
        Card card;
        deck.Deal(card);
        dealerHand.AddCard(card);
        return true;
    }
    else
    {
        return false;
    }
}

// Returns a string representing a dealer win
string Game::DealerWins()
{
    // String stream to build the message
    stringstream message;
    message << fixed << setprecision(2);
    // Showing how much the player lost and their current balance
    message << "Player loses! Bet: $" << data.bet << "\r\nCurrent Balance: $" << data.balance;
    // Incrementing losses and games played
    data.losses++;
    data.gamesPlayed++;
    // Returning the message as a string
    return message.str();
}

// Returns a string representing a tie
string Game::Tie()
{
    // String stream to build the message
    stringstream message;
    message << fixed << setprecision(2);
    // Showing the initial bet (returned to the balance) and the current balance
    data.balance += data.bet;
    message << "It's a tie! Your bet of $" << data.bet << " is returned to your balance\r\nCurrent Balance: $" << data.balance;
    // Incrementing ties and games played
    data.ties++;
    data.gamesPlayed++;
    // Returning the message as a string
    return message.str();
}

// Evaluates the hands to determine the result and calls the relevant method
string Game::ShowResults()
{
    string result;

    // If the player busts, the dealer wins
    if (playerHand.Busted())
    {
        result = DealerWins();
    }
    // If the player doesn't bust but the dealer does, the player wins
    else if (dealerHand.Busted())
    {
        result = PlayerWins();
    }
    // If nobody busts and the scores are equal, it's a tie
    else if (playerHand.BestScore() == dealerHand.BestScore())
    {
        result = Tie();
    }
    // If nobody busts and the player has a higher score, the player wins
    else if (playerHand.BestScore() > dealerHand.BestScore())
    {
        result = PlayerWins();
    }
    // If nobody busts and the dealer has a higher score, the dealer wins
    else
    {
        result = DealerWins();
    }

    log.WriteLog(result);
    return result;
}

// Creates a game summary and sends it to the logger. The instructions don't explicitly state what the summary should contain, so I just collected some basic data
void Game::EndGame()
{
    // String stream to build the message
    stringstream summary;
    summary << fixed << setprecision(2);
    // Adding a line showing each statistic - games played, wins, losses, ties, and starting/ending balance
    summary << "Games Played: " << data.gamesPlayed;
    summary << "\r\nGames Won: " << data.wins;
    summary << "\r\nGames Tied: " << data.ties;
    summary << "\r\nGames Lost: " << data.losses;
    summary << "\r\nStarting Balance: $" << STARTINGBALANCE;
    summary << "\r\nEnding Balance: $" << data.balance;

    // Closing the log and sending the summary as a string
    log.CloseLog(summary.str());
}