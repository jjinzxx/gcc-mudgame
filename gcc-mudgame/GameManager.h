#pragma once
#include "Dealer.h"
#include "Deck.h"
#include "Player.h"

class GameManager
{
private:
    Deck deck;
    Player player;
    Dealer dealer;
    
public:
    GameManager();
    void startGame();
};
