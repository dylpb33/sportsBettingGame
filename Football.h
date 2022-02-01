/* CSCI261 Final Project
 *
 * Description: Declaration file for Football class.
 *
 * Author: Dylan Blaine
 *
 */

// This include section adds extra definitions from the C++ standard library.
#include <iostream>
#include <string>
using namespace std;

#ifndef FINALPROJECT_FOOTBALL_H
#define FINALPROJECT_FOOTBALL_H

class Football {
public:
    //Declares public member functions and integers of Football class.
    Football();
    int score1;
    int score2;
    int playGame();
    int getScore1();
    int getScore2();
    void setScore1();
    void setScore2();
    int getBalance();
    void setBalance(int balanceAmount);
    void setBet(int betAmount);
    void introduction() const;


private:
    //Declares bet and balance as private integer members.
    int bet;
    int balance;

};


#endif //FINALPROJECT_FOOTBALL_H
