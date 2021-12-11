#include "Card.h"
#include <iostream>
#include <string>

Card::Card()
{

}


Card::Card(int v)
{
    if(v < 1 || v > 13)
    {
        std::cerr << "Invalid Card Value of " << v;
    }
    else
    {
        value = v;
    }
    
}

Card::Card(int v, char s)
{
    if(v < 1 || v > 13)
    {
        std::cerr << "Invalid Card Value of " << v;
    }
    else
    {
        value = v;
    }

    if( (s != SPADES) && (s != CLUBS) && (s != HEARTS) && (s != DIAMONDS) )
    {
        std::cerr << "Invalid Card Suit of" << s;
    }
    else
    {
        suit = s;
    }  
}

//Transforms the card value and suit into text for the console
const std::string Card::toString()
{
    std::string str;

    //Defining what to display for the 
    switch (value)
    {
    case 1:
        str = "Ace of";
        face = false;
        break;
    case 2:
        str = "Two of";
        face = false;
        break;
    case 3:
        str = "Three of";
        face = false;
        break;
    case 4:
        str = "Four of";
        face = false;
        break;
    case 5:
        str = "Five of";
        face = false;
        break;
    case 6:
        str = "Six of";
        face = false;
        break;
    case 7:
        str = "Seven of";
        face = false;
        break;
    case 8:
        str = "Eight of";
        face = false;
        break;
    case 9:
        str = "Nine of";
        face = false;
        break;
    case 10:
        str = "Ten of";
        face = false;
        break;
    case 11:
        str = "Jack of";
        face = true;
        break;
    case 12:
        str = "Queen of";
        face = true;
        break;
    case 13:
        str = "King of";
        face = true;
        break;
    default:
        std::cerr << "Invalid Card Value";
        break;
    }

    switch (suit)
    {
    case 'S':
        str += " Spades";
        break;
    case 'C':
        str += " Clubs";
        break;
    case 'H':
        str += " Hearts";
        break;
    case 'D':
        str += " Spades";
        break;
    default:
        std::cerr << "Invalid Suit Value";
        break;
    }

    return str;

}

int Card::getValue()
{
    //Sets the value of the face cards to 10 as per the rules of
    //Blackjack
    if(value > 10)
    {
        value = 10;
    }
    return(value);
}

