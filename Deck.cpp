#include "Deck.h"
#include "Card.h"
#include <iostream>
#include <string>
#include <ctime>


void Deck::DisplayDeck()
{
    for(int i = 0; i < MAX; i++)
    {
        std::cout << deck[i].toString() << std::endl;
    }
}

//shuffles the deck 
void Deck::Shuffle()
{
    srand(time(0));
    std::cout << "Shuffling..." << std::endl;
    for(int i = 0; i < MAX; i++)
    {
        //Gets a random position in the deck
        int s = (rand() + time(0)) % MAX;
        Card temp = deck[i];
        deck[i] = deck[s];
        deck[s] = temp;
    }
}

Deck::Deck()
{
    char suits[4] = {Card::SPADES, Card::CLUBS, Card::HEARTS, Card::DIAMONDS};
    //Current card count for generating the deck
    int count = 0;

    for (int s = 0; s < 4; s++)
    {
        for (int v = 1; v <= 13; v++)
        {
            deck[count] = Card(v, suits[s]);
            count++;
        }
    }

    int numberOfCardsInDeck = 0;
    //This is just so the variable numberOfdeckInDeck is used
    std::cout << numberOfCardsInDeck << std::endl;
}

Deck::Deck(int num)
{
    char suits[4] = {Card::SPADES, Card::CLUBS, Card::HEARTS, Card::DIAMONDS};
    deck = new Card[MAX];
    int count = 0;
    std::cout << "Generating Deck..." << std::endl;

    for (int s = 0; s < 4; s++)
    {
        for (int v = 1; v <= 13; v++)
        {
            deck[count] = Card(v, suits[s]);
            count++;
        }
    }

    if(num < 0 || num > MAX)
    {
        std::cerr << "Number of deck for Deck out of scope";
    }
    int numberOfCardsInDeck = num;
    //This is just so the variable numberOfdeckInDeck is used
    std::cout << numberOfCardsInDeck << std::endl;
}

Card Deck::PeekTopCard()
{
    Card c;

    if(numberOfCardsInDeck > 0)
    {
        //Gets the value of the top card
        c = deck[0];
    }
    else
    {
        std::cerr << "Cannot get value from empty deck";
    }

    return c;
}

Card Deck::DealTopCard()
{
    //ONLY occurs if the currentCard position is out of the scope
    //of the array
    if (currentCard > MAX)
    {
        Shuffle();
    }
    //if the current card is under the max value, which it always should
    //be, then return the top card
    if(currentCard < MAX)
    {
        return deck[currentCard++]; 
    }
    //default return value
    return deck[0];
}




