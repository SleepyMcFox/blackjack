#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include <string>

class Deck
{
    private:
        //max amount of cards that can be in the deck
        static const int MAX = 52;
        //max amount of suits available, kinda given
        static const int MAX_SUITS = 4;
        //max amount of value for the cards
        static const int MAX_VALUE = 13;

        //will be used to display the number of cards in
        //the deck
        int numberOfCardsInDeck;
        int currentCard;
        Card *deck;

    public:
        //Default constructor
        Deck();
        //Non-Default constructor
        Deck(int num);

        //This will be used to transfer the card to the 'hand'
        Card DealTopCard();
        //This will be used to get the value
        Card PeekTopCard();

        bool isEmpty();

        void Shuffle();
        //Deck Checker
        void DisplayDeck();
};


#endif