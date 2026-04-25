#pragma once
#include "Participant.h"

using namespace std;

class Player : public Participant // Participant 상속
{
private:
    int money;
    
public:
    Player(string name, int startingMoney);
    void addMoney(int amount);
    void subMoney(int amount);
    int getMoney() const;
};
