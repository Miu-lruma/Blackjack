//Lily Krueger
//Data Structures lab 2
//2/6/17
//cardDeck.cpp
//.cpp file for the cardDeck class.

#include "cardDeck.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

//Default constructor, 52 cards
cardDeck::cardDeck() {
	size = 52;
	numdealt=0;
	deck = new int[size];
	for (int i = 0; i < size; i++) {
		deck[i] = i;
	}
}

cardDeck::cardDeck(int cards) {
	size = cards;
	numdealt=0;
	deck = new int[size];
	for (int i = 0; i < size; i++) {
		deck[i] = i;
	}
}

//Destructor that uses delete to free memory
cardDeck::~cardDeck() {
	delete [] deck;
}

//Returns the size of the deck
int cardDeck::getSize() {
	return size;
}

//Returns the number of cards dealt
int cardDeck::getNumdealt() {
	return numdealt;
}

//Allows the number of dealt cards to be reset when deck is reshuffled.
void cardDeck::setNumdealt(int n) {
	numdealt = n;
}

//deals each card in order, incrementing the counter as the card is dealt
int cardDeck::deal() {
	return deck[numdealt++];
}

//Method that shuffles the cards in the deck usink Knuth's algorithm
void cardDeck::shuffle() {
	int temp, currcard;
	//Allows for randomness
	srand (time(NULL));
	//Swaps each card with a random card in the deck
	for (int i = 0; i < size; i++) {
		temp = deck[i];
		currcard = rand() % size;
		deck[i] = deck[currcard];
		deck[currcard] = temp;
	}
}

//Overloads the output operator so that the full deck can be printed
ostream& operator<<( ostream &s, cardDeck &x) {
	for (int i = 0; i < x.size; i++) {
		s << x.deck[i];
		if (i != x.size - 1) {
			s << ", ";
		}
	}
	s << "\n";
	return s;
}


