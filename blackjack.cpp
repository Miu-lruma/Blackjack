//Lily Krueger
//Data Structures lab 2
//2/6/17
//blackjack.cpp
//Main file for the blackjack game, uses the cardDeck class to create a game of blackjack for a user to play against a computer dealer

#include "cardDeck.h"
#include <iostream>
#include <cstdlib>

int main() {
	//Creates an instance of the cardDeck class
	cardDeck deck;
	//Initially shuffles the deck
	deck.shuffle();
	int playerHand = 0, dealerHand = 0, currcard = 0, playerStands = 0, dealerStands = 0, win = 0, playerWin = 0, dealerWin = 0;
	char choice;

	cout << "Welcome to blackjack!" << endl << "Would you like to play a game? (y/n)" << endl;
	cin >> choice;

	while (true) {

		//Requires that the user inputs a valid character
		while (choice != 'y' && choice != 'n') {
			cout << "Invalid input!" << endl << "Would you like to play? (y/n)" << endl;
			cin >> choice;
		}

		//Stops the game if the user chooses "no"
		if (choice == 'n') {
			return 0;
		}

		//Reshuffles the deck and notifies the user if there are less than 15 cards remaining after a round
		if (deck.getNumdealt() > 37) {
			cout << "15 cards remaining, shuffling deck." << endl << endl;
			deck.shuffle();
			deck.setNumdealt(0);
		}

		//Resets variables used in each round before another round begins
		win = 0;
		playerHand = 0;
		dealerHand = 0;
		playerStands = 0;
		dealerStands = 0;

		//While loop that contains a round
		while (win == 0) {

			//Win checks, which changes the value of win to exit the loop, as well as increment the win counters for the user and the dealer.
			if (playerHand > 21) {
				cout << "You bust! The dealer wins!" << endl << endl;;
				win = 1;
				dealerWin++;
			}

			if (dealerHand > 21) {
				cout << "The dealer busts! You win!" << endl << endl;;
				win = 2;
				playerWin++;
			}

			//If both players have stood, the program checks to see who won
			if (dealerStands == 1 && playerStands == 1) {
				if (playerHand > dealerHand) {
					cout << "You win, " << playerHand << " to " << dealerHand << "." << endl << endl;
					win = 2;
					playerWin++;
				} else if (playerHand < dealerHand) {
					cout << "The dealer wins, " << dealerHand << " to " << playerHand << "." << endl << endl;
					win = 1;
					dealerWin++;
				} else {
					cout << "It's a tie!" << endl << endl;
					win =  3;
				}
			}

			//Displays each player's hand
			cout << "Your Hand:       Dealer's Hand:" << endl << playerHand << "\t         " << dealerHand << endl << endl;

			//If neither player has won, the program moves on to the portion of the loop where each player can add cards to their hand
			if (win == 0) {

				//If the player has already chosen to stand, their turn is skipped until the dealer busts or stands
				if (playerStands == 0) {
					cout << "Would you like to (h)it or (s)tand?" << endl;
					cin >> choice;
				}

				//Again, checks for invalid input
				while (choice != 'h' && choice != 's') {
					cout << "Invalid input!" << endl << "Would you like to (h)it or (s)tand?" << endl;
					cin >> choice;
				}

				if (playerStands == 0) {
					system("clear");
				} else {
				}

				if (choice == 's') {
					playerStands = 1;
				}

				//If the player chooses to hit, a card is selected from the deck, and the apropriate message is displayed.
				if (choice == 'h') {
					currcard = deck.deal() % 13;
					switch(currcard) {
						//Jack and queen are represented by 0 and 1 so that 2-10 can relate to the values 2-10
						case 0: cout << "You drew a jack!";
								playerHand += 10;
								break;
						case 1: cout << "You drew a queen!";
								playerHand += 10;
								break;
						case 11: cout << "You drew an ace!";
								 playerHand += 11;
								 break;
						case 12: cout << "You drew a king!";
								 playerHand += 10;
								 break;
						default: cout << "You drew a " << currcard;
								 playerHand += currcard;
								 break;
					}

					cout << endl << endl;
				}

				//Logic to determine the dealer's move - the dealer will take a card if it has 16 or fewer in its hand, or if the player has a higher hand value than the dealer and hasnt busted
				if ((dealerHand > 16) || (dealerHand > playerHand && playerStands == 1) || playerHand > 21) {
					if (playerHand <= 21) {
						cout << "The dealer stands." << endl << endl;
					}
					dealerStands = 1;
					//Again, draws a card from the deck and displays the appropriate message.
				} else {
					currcard = deck.deal() % 13;
					switch(currcard) {
						case 0: cout << "The dealer drew a jack!";
								dealerHand += 10;
								break;
						case 1: cout << "The dealer drew a queen!";
								dealerHand += 10;
								break;
						case 11: cout << "The dealer drew an ace!";
								 dealerHand += 11;
								 break;
						case 12: cout << "The dealer drew a king!";
								 dealerHand += 10;
								 break;
						default: cout << "The dealer drew a " << currcard;
								 dealerHand += currcard;
								 break;
					}
					cout << endl << endl;
				}
			}
		}

		//Informs the player of how many games have been won by the player and the dealer before asking them if they want to play again,
		cout << "You have won " << playerWin << " games, and the dealer has won " << dealerWin << " games." << endl << endl;
		cout << "Would you like to play again? (y/n)" << endl;
		cin >> choice;
	}
}
