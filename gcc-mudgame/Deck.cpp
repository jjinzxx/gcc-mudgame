#include "Deck.h"

#include <algorithm>
#include <ctime>
#include <__msvc_filebuf.hpp>

using namespace std;

Deck::Deck()
{
    // 4가지 문양과 13가지 숫자를 조합하여 52장의 카드(덱) 생성
    for (int suit=0; suit<4; suit++)
    {
        for (int rank=1; rank<=13; rank++)
        {
            // emplace_back() : 벡터 끝에 새로운 요소를 추가
            // 벡터가 관리하는 메모리 공간에서 객체를 직접 생성
            cards.emplace_back(static_cast<Suit>(suit), static_cast<Rank>(rank));
        }
    }
}

void Deck::shuffle()
{
    // 현재 시간을 기준으로 숫자를 섞음, 프로그램을 실행할 때마다 다른 랜드값 생성
    // unsigned int : 부호없는 정수 타입으로 명시적 형변환
    srand(static_cast<unsigned int>(time(NULL)));
    random_shuffle(cards.begin(), cards.end());
}

Card Deck::drawCard()
{
    // 덱의 끝에서 카드 한장을 꺼내고 제거
    Card topCard = cards.back();
    cards.pop_back();
    return topCard;
}
