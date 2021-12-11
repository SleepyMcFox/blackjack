#include "Player.h"
#include "Card.h"
#include <iostream>
#include <string>

//Default Constructor
Player::Player()
{
    plaNumber = 0;
    plaScore = 0;
    plaHandValue = 0;
    handSize = 0;
    natural = false;
    //Maximum amount of cards that can possibly be in
    //one hand before busting
}
//Non-Default Constructor
Player::Player(int num)
{
    plaNumber = num;
    if(plaNumber == 0)
    {
        plaName = "Dealer";
    }
    else
    {
        plaName = "Player"; 
    }
    plaScore = 0;
    plaHandValue = 0;
    handSize = 0;
    natural = false;
}

