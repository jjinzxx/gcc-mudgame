#include "Card.h"
using namespace std;

Card::Card(Suit suit, Rank rank) : suit(suit), rank(rank) {}

int Card::getValue()
{
    int value = static_cast<int>(rank); // 1부터 킹까지 열거형 자료형을 int형 정수로 명시적 형변환
    if (value > 10) return 10; // J, Q, K은 10점 처리
    if (value == 1) return 11; // Ace는 일단 11점 처리
    return value;
}

string Card::getName()
{
    string suitName[] = {"Spade", "Diamond", "Heart", "Club"};
    string rankName[] = {"", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    
    return suitName[static_cast<int>(suit)] + " " + rankName[static_cast<int>(rank)];
}