#include "Participant.h"
#include <iostream>

Participant::Participant(string name) : name(name) { }

void Participant::addCard(Card card)
{
    hand.push_back(card);
}

void Participant::clearHand()
{
    hand.clear();
}

int Participant::getTotalScore() const
{
    int total = 0;
    int aceCount =0;
    
    for (const auto& card : hand)
    {
        int val = card.getValue();
        if ( val == 11) aceCount++;
        total += val;
    }
    while (total > 21 && aceCount > 0)
    {
        total -= 10;
        aceCount--;
    }
    return total;
}

void Participant::showHand() const
{
    cout << name <<"'s Hand : ";
    for (const auto& card : hand)
    {
        cout << "[" << card.getName() << "] ";
    }
    cout << "(Score : " << getTotalScore() << ")" << endl;
}