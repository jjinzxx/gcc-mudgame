#pragma once
#include <string>
#include <vector>
#include "Card.h"

using namespace std;

class Participant
{
private:
    string name;
    vector<Card> hand;
    
public:
    Participant(string name);
    
    void addCard(Card card);
    int getTotalScore() const;
    void showHand() const;
    void clearHand();
};
