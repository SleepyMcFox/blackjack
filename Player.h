#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
#include <string>

class Player
{
    public:
        bool willHit;
        bool natural;
        int plaNumber;
        int plaScore;
        int plaHandValue;
        int handSize;
        Card *plaHand;
        std::string plaName;
        Player();
        Player(int num);
        
};

#endif



