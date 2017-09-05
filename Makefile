blackjack: blackjack.o cardDeck.o
	g++ blackjack.o cardDeck.o -o blackjack

blackjack.o: blackjack.cpp cardDeck.h
	g++ -c blackjack.cpp -o blackjack.o

cardDeck.o: cardDeck.cpp cardDeck.h
	g++ -c cardDeck.cpp -o cardDeck.o

clean:
	rm *.o blackjack
