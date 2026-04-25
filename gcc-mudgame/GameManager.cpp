#include "GameManager.h"
#include <iostream>
using namespace std;

GameManager::GameManager() : player("User", 1000) { }

void GameManager::startGame()
{
    // 플레이어가 0원 이상 가지고 있다면 계속 반복
    while (player.getMoney() > 0)
    {
        system("CLS");
        cout << "--- Welcom to Blackjack ---" << endl;
        
        // 매 판 시작 초기화
        deck = Deck();
        deck.shuffle();
        player.clearHand();
        dealer.clearHand();
        
        // 베팅 된 금액
        int bet = 0;
        cout << "\nCurrent Money :" << player.getMoney() << endl;
        cout << "Enter bet amount : ";
        cin >> bet;
        system("CLS");
        
        // 만약 베팅 금액보다 돈이 적다면
        if (bet > player.getMoney())
        {
            cout << "You don't have enough money!" << endl;
            continue;
        }
        
        // 초기 카드 분배
        player.addCard(deck.drawCard());
        dealer.addCard(deck.drawCard());
        player.addCard(deck.drawCard());
        dealer.addCard(deck.drawCard());
        
        // 덱 보여주기
        dealer.showHand();
        player.showHand();
        
        // 플레이어 턴
        char choice;
        while (player.getTotalScore() < 21) // 플레이어 카드 합이 21 이하일때,
        {
            cout << "\nHit (h) or Stay (s)? ";
            cin >> choice;
            
            system("CLS"); // 선택 이후 화면 클리어
            if (choice == 'h')
            {
                player.addCard(deck.drawCard());
                cout << "--- you drew a card! ---" << endl;
            
                // 현재 상황 다시 출력
                dealer.showHand(); 
                player.showHand();
            }
            else break;
        }
        
        // 결과판정
        int pScore = player.getTotalScore();
        
        if (pScore > 21)
        {
            cout << "Player Bust! You lose!" << endl;
            player.subMoney(bet); // 베팅한 금액 차감
        }
        else
        {
            // 딜러 턴
            cout << "\n--- Dealer's Turn ---" << endl;
            while (dealer.shouldHit()) {
                cout << "Dealer draws a card..." << endl;
                dealer.addCard(deck.drawCard());
                dealer.showHand();
            }

            int dScore = dealer.getTotalScore();
            
            // 최종 점수 비교
            cout << "\n--- Final Result ---" << endl;
            if (dScore > 21 || pScore > dScore) {
                cout << "You Win!" << endl;
                player.addMoney(bet);
            } else if (pScore < dScore) {
                cout << "Dealer Wins!" << endl;
                player.subMoney(bet);
            } else {
                cout << "Push (Draw)!" << endl;
            }
        }
        
        if (player.getMoney() <= 0) {
            cout << "You are bankrupt! Game Over." << endl;
            break;
        }

        cout << "\nPlay again? (y/n): ";
        cin >> choice;
        if (choice == 'n') break;
        
    }
    
}
