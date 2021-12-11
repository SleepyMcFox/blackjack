#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <string>


class Card
{
private:
    /*
    Stores the value of the card based on the pip value. As per the 
    rules of Blackjack, face cards will have a value of 10, while 
    the ace will be either 1 or 11(maybe have a CheckAceValue struct 
    or just have them always be high). Regular cards will just have 
    whatever their pip value is.
    */
    int value;
    char suit;
    //The true value of the card (Ace = 11, All Face Cards = 10)
    int cardValue;
    bool face;
public:
    //Suit Declarations
    static const char SPADES = 'S';
    static const char CLUBS = 'C';
    static const char HEARTS = 'H';
    static const char DIAMONDS = 'D';

    //Default
    Card();
    //Non-Default (Test Case for value)
    Card(int v);
    //Non-Default (Includes value and suit)
    Card(int v, char s);
    //Card Value
    int getValue();
    /*
    Gets the card's value and converts it into
    a string
    */
    const std::string toString();
    
};

#endif




