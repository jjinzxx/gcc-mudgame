#include "Dealer.h"

Dealer::Dealer() : Participant("Dealer") {}

bool Dealer::shouldHit() const
{
    return getTotalScore() < 17; // 합이 17이하이면 카드를 더 뽑음
}