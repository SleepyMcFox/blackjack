#ifndef BLACKJACK_H
#define BLACKJACK_H
#include "Deck.h"
#include "Card.h"
#include "Player.h"
#include <string>

void DealCardsToHand(Player &p, Deck &d);
int CheckTotalHandValue(Player &p);
bool HitOrStand(Player &p);
void DealInitialHand(Player &p, Player &dl, Deck &d);
bool CheckForWin(Player &p, Player &dl);
bool Bust(Player &p, Player &dl);
void Game();

#endif