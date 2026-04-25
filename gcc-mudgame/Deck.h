#pragma once
#include <vector>

#include "Card.h"

using namespace std;

class Deck
{
private:
    vector<Card> cards; // 카드를 벡터형으로 선언
    
public:
    Deck();
    void shuffle();
    Card drawCard(); // drawCard() 했을때 Card 객체 반환
};
