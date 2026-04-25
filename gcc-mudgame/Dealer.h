#pragma once
#include "Participant.h"

using namespace std;

class Dealer : public Participant
{
private:
    
public:
    Dealer();
    bool shouldHit() const; // 17점 미만이면 Hit(한장 더 받기)
};
