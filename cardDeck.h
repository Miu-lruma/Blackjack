//Randall Krueger
//Data Structures lab 2
//2/6/17
//cardDeck.h
//.h file for the cardDeck class

#include <iostream>
using namespace std;


class cardDeck {
	friend ostream& operator<< (ostream &, cardDeck &);
	public:
	cardDeck();
	cardDeck(int);
	~cardDeck();
	int getSize();
	int getNumdealt();
	void setNumdealt(int);
	int deal();
	void shuffle();
	private:
	int size;
	int numdealt;
	int * deck;
};
