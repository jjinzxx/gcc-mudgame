#pragma once
#include <string>
using namespace std;

enum class Suit {Spade,Diamond, Heart, Club};
enum class Rank {Ace=1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};

class Card
{
private:
    Suit suit;
    Rank rank;
    
public:
    Card(Suit suit, Rank rank);
    int getValue() const;  // 1부터 킹까지를 숫자로 표현해줄 함수
    string getName() const; // 카드모양과 숫자를 이름으로 반환해줄 함수
};
