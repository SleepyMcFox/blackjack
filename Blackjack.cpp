#include "Blackjack.h"
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <ctime>


void DealInitialHand(Player &p, Player &dl, Deck &d)
{
    int dealt = 0;
    p.handSize = 0;
    dl.handSize = 0;
    p.plaHandValue = 0;
    dl.plaHandValue = 0;

    std::cout << std::endl << dl.plaName << " begins to deal..." << std::endl << std::endl;

    //Deals out the inital 2
    for (int h = 0; h < 2; h++)
    {
        p.plaHand[h] = d.DealTopCard();
        std::cout << p.plaName << " recieved a " << p.plaHand[h].toString() << std::endl<< std::endl;
        p.handSize++;
        dealt++;
        //Dealer deals their own hand: one face up, one face down
        dl.plaHand[h] = d.DealTopCard();
        if(h > 0)
        {
            std::cout << dl.plaName << " puts the second card face down" << std::endl << std::endl;
        }
        else
        {
            std::cout << dl.plaName << " revealed a " << dl.plaHand[h].toString() << std::endl << std::endl;
        }
        dl.handSize++;
        dealt++;    
    }

    p.plaHandValue += CheckTotalHandValue(p);

    std::cout << p.plaName << " hand is valued at " << p.plaHandValue << std::endl << std::endl;

    if(p.plaHandValue == 21 || dl.plaHandValue == 21)
    {
        if(p.plaHandValue == 21)
        {
            std::cout << p.plaName << " has a natural!" << std::endl;
            p.natural = true;
        }
        if (dl.plaHandValue == 21)
        {
            std::cout << dl.plaName << " has a natural!" << std::endl;
            dl.natural = true;
        }
    }
}

int CheckTotalHandValue(Player &p)
{
    int total = 0;
    int nbOfAces = 0;
    int handSize = p.handSize;

    for(int i = 0; i < handSize; i++)
    {
        if(p.plaHand[i].getValue() == 1)
        {
            nbOfAces++;
        }
        else
        {
            total += p.plaHand[i].getValue();
        }
    }

    //Checks to determine the value of the aces in your hand, Dealer
    //will have a different check
    while(nbOfAces != 0)
    {
        nbOfAces--;
        if((total + 11 + nbOfAces) <= 21)
        {
            total += 11;
        }
        else
        {
            total++;
        }
    }
    return total;
}

void DealCardsToHand(Player &p, Deck &d)
{
    int totalValue = 0;
    int size = p.handSize;
    p.plaHand[size] = d.DealTopCard();
    p.handSize++;
    std::cout << p.plaName << " recieved a " << p.plaHand[size].toString() << std::endl << std::endl;
    totalValue = CheckTotalHandValue(p);
    p.plaHandValue = totalValue;
    std::cout << p.plaName << " hand is valued at " << p.plaHandValue << std::endl << std::endl;
}

bool Bust(Player &p, Player &dl)
{
    if(p.plaHandValue > 21)
    {
        std::cout << p.plaName << " has busted" << std::endl << std::endl;
        dl.plaScore++;
        return true;
    }
    return false;
}

bool CheckForWin(Player &p, Player &dl)
{
    if(p.natural == true && dl.natural == false)
    {
        std::cout << p.plaName << " wins" << std::endl << std::endl;
        p.plaScore++;
        return true;
    }
    if(p.natural == true && dl.natural == true)
    {
        std::cout << "House and Player have tied" << std::endl << std::endl;
        return true;
    }
    if(p.plaHandValue <= 21 && p.plaHandValue > dl.plaHandValue)
    {
        std::cout << p.plaName << " wins" << std::endl << std::endl;
        p.plaScore++;
        return true; 
    }
    else
    {
        std::cout << "House has won" << std::endl << std::endl;
        dl.plaScore++;
        return true;
    }
    return false;

}

bool HitOrStand(Player &p)
{
    //The dealer will always hit until they reach a hand value of 17 or above
    if(p.plaNumber == 0)
    {
        if(p.plaHandValue < 17)
        {
            std::cout << p.plaName << " will hit!" << std::endl;
            return true;
        }else
        {
            std::cout << p.plaName << " will stand!" << std::endl;
            return false;
        }
    }
    
    //The player is a bit more dumb, so they will hit until they bust or win
    if(p.plaNumber > 0)
    {
        if(p.plaHandValue < 21)
        {
            std::cout << p.plaName << " will hit!" << std::endl;
            return true;
        }else if(p.plaHandValue >= 21)
        {
            std::cout << p.plaName << " will stand!" << std::endl;
            return false;
        }
    }
    return false;
}


void Game()
{
    //This is all setup
    bool winner = false;
    Player d(0);
    Player p(1);
    
    

    for(int i = 0; i < 100; i++)
    {
        Deck deck(52);
        p.plaHand = new Card[10];
        d.plaHand = new Card[10];
        std::cout << "Round " << i + 1 << ":" << std::endl;
        std::cout << "-------------------------------------------------------------------" << std::endl;
        deck.Shuffle();
        DealInitialHand(p, d, deck);
    

        //Game logic
        while (winner == false)
        {
        p.willHit = HitOrStand(p);
        if(p.willHit)
        {
            DealCardsToHand(p,deck);
            winner = Bust(p,d);
        }else
        {
            //After the player is done being dealt, the it is the dealer's play
            d.plaHandValue = CheckTotalHandValue(d);
            std::cout << "Dealer flips their card..." << std::endl;
            std::cout << "it is a " << d.plaHand[1].toString() << std::endl;
            std::cout << "The Dealer's total hand value is " << d.plaHandValue << std::endl << std::endl; 
            d.willHit = HitOrStand(d);
            if(d.willHit)
            {
                //if the total hand value is less that 
                DealCardsToHand(d, deck);
                winner = CheckForWin(p,d);
                d.willHit = HitOrStand(d);
            }
            else
            {
                winner = CheckForWin(p,d);
            }
        }
        }

        std::cout << "Dealer Score: " << d.plaScore << " || Player Score: " << p.plaScore << std::endl << std::endl;

        winner = false;

        
    }
}

