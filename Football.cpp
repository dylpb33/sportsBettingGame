/* CSCI261 Final Project
 *
 * Description: Definition file for Football class.
 *
 * Author: Dylan Blaine
 *
 */

// This include section adds extra definitions from the C++ standard library.
#include <iostream>
#include <string>
#include <random>
#include <time.h>
#include "Football.h"
using namespace std;

//Default constructor for Football class.
Football::Football() {
    bet = 5;
    balance = 100;
}

//Explains rules of game to players.
void Football::introduction() const {
    cout <<"Hello Football Fanatic!" <<endl;
    cout <<"You will bet on a battle on the gridiron." <<endl;
    cout <<"First enter your balance, then how much you would like to bet on the game." <<endl;
    cout <<"Then enter two team numbers, the first team number you enter corresponds to your anticipated winner." <<endl;
    cout <<"Goodluck! Enter -1 in bet amount to quit playing" <<endl;
}

//Sets bet amount, using user's input for the bet amount.
void Football::setBet(int betAmount) {
    bet = betAmount;
}

//Returns user's balance.
int Football::getBalance(){
    return balance;
}

//Sets user's balance based on the outcome of the football game from the Football class function playgame().
void Football::setBalance(int balanceAmount) {
    if (playGame() == 1)
        balance = balanceAmount + bet;
    else if(playGame() == -1){
        balance = balanceAmount - bet;
    }
    else if(playGame() == 0){
        balance = balanceAmount;
    }
}

//Returns three different integers corresponding to the different outcomes of the football game.
int Football::playGame(){
    if(getScore1() > getScore2()){
        return 1;
    }
    else if(getScore2() > getScore1()){
        return -1;
    }
    else if(getScore1() == getScore2()){
        return 0;
    }

}

//Returns score of anticipated winner.
int Football::getScore1() {
    return score1;
}

//Returns score of anticipated loser.
int Football::getScore2() {
    return score2;
}

//Randomly sets score 0-100 for anticipated winner.
void Football::setScore1() {
    srand(time(0));
        int randNum = rand() % 100;
        score1 = randNum;


}

//Randomly sets score 0-100 for anticipated loser. For loop used to create unique
//random numbers between score1 and score2.
void Football::setScore2() {
    vector<int>rands;
    srand(time(0));
    for (int i = 0; i < 5; ++i) {
        int num = rand() % 100;
        rands.push_back(num);
    }
    score2 = rands[4];
}