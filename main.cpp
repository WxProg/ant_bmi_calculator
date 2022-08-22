#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
// #include "main.h"
using namespace std;

double DrawNum (int max);
void displayPlayerInfo(int player, double bet, double & totalBalance, int wager);
bool RollDice(int player, int count);
bool RollDiceMulti(int player, int count, int point);
int GetPlayerBet(int player, const double balance, const double initialBalance);
void AdjustWages(int activePlayer, double & p1Balance, double & p2Balance, double bet, bool winner);

// I am greatness
int main()
{

    int playerTurn = 1;
    double p1Balance = 1000, p2Balance = 1000;
    const double p1InitBalance = 1000 , p2InitBalance = 1000;
    bool winner = true;
    cout << "**************************" << endl;
    cout << " Welcome to the Craps Game" << endl;
    cout << "**************************" << endl;
   //run 20  wagers
    for(int i = 1; i <= 20; i++){

        double & balance  = (playerTurn == 1) ? p1Balance : p2Balance;
        const double initBalance  = (playerTurn == 1) ? p1InitBalance : p2InitBalance;
        
        double playerBet = GetPlayerBet(playerTurn, balance, initBalance );

        displayPlayerInfo(playerTurn, playerBet, balance, i );
        
        winner = RollDice(playerTurn, i);

        AdjustWages(playerTurn, p1Balance, p2Balance, playerBet, winner);

        //call rol dice;
        if(!winner){
            //changing player
            playerTurn = (playerTurn == 1)?2 : 1;
        }
    }
    
    return 0;
}

void displayPlayerInfo(int player, double bet, double & totalBalance, int wager){
    cout << "Wager " << wager << ": Bet is $"<< bet << endl;
    cout << "\tPlayer " << player << " is rolling the dice" << endl;
}

bool RollDice(int player, int count){
    const int NATURAL7 = 7;
    const int NATURAL11 = 11;
    const  int MAX = 6;

    double point = DrawNum(MAX) + DrawNum(MAX);

    //change the count  when a new player is chosen
    if((point == NATURAL7) || (point == NATURAL11)){

        cout<<"\t The roll is "<< point << ". Player "<< player << " wins." <<endl;
        return true;

    }else if((point == 2) || (point == 12) || (point == 3)){
         cout<<"\t The roll is "<< point <<endl; 
         cout << "\tThat is craps! Player "<< player << " loses.." <<endl;
        return false;
    } else{

        cout << "\tThe roll is a "<< point <<".  The point is "<< point <<". Player " << player <<" rolls again." <<endl;
        return RollDiceMulti(player, count, point);
    }

}

bool RollDiceMulti(int player, int count, int point){
    bool contRoll = true;
    int newRoll = 0;
    const  int MAX = 6;

    while(newRoll != point && newRoll != 7 ){

        newRoll = DrawNum(MAX) + DrawNum(MAX);
        cout << "\tThe roll is a "<< newRoll <<".  The point is "<< point <<". Player " << player <<" rolls again." <<endl;
        
    }

    return newRoll == point;
    
}

void AdjustWages(int activePlayer, double & p1Balance, double & p2Balance, double bet, bool winner){
     
    if(winner){
        double & balanceToIncrease = (activePlayer == 1)? p1Balance : p2Balance;
        double & balanceToDecrease = (activePlayer == 1)? p2Balance : p1Balance;

        balanceToIncrease+=bet;
        balanceToDecrease-=bet;
  
    }else{
        double & balanceToIncrease = (activePlayer == 1)? p2Balance : p1Balance;
        double & balanceToDecrease = (activePlayer == 1)? p1Balance : p2Balance;

        balanceToIncrease+=bet;
        balanceToDecrease-=bet;
    }
    
    cout << "\nCurrently, Player 1 has $" << p1Balance <<" and Player 2 has $" << p2Balance <<"." << endl;
}


int GetPlayerBet(int player, const double balance, const double initialBalance){

    double p1Bet = 100;
    double p2HighBet = 150;
    double p2LowBet = 50;

    if(player == 1){

        return p1Bet;

    }else{
        //base on the initial bet p2 will choose either a low or high bet
        if(balance > initialBalance){
            return p2HighBet;
        }else{
            return p2LowBet;
        }
    }

}

double DrawNum (int max) {
    /* function drawNum */

    double x = RAND_MAX + 1.0;        /* x and y are both auxiliary */
    int y;                            /* variables used to do the */
    /* calculation */

    y = static_cast<int> (1 + rand() * (max / x));
    return (y);                       /* y contains the result */

}    /* function drawNum */
