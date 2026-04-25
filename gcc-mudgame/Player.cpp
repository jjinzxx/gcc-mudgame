#include "Player.h"

Player::Player(string name, int startingMoney) : Participant(name), money(startingMoney) { }

void Player::addMoney(int amount)
{
    money += amount;
}

void Player::subMoney(int amount)
{
    money -= amount;
}

int Player::getMoney() const
{
    return money;
}
