/* CSCI 261 Final Project - Football Fanatic
 *
 * Author: Dylan Blaine
 *
 * Description: Allows user to play game where they bet on a simulated football game
 * with an input balance and bet amount as long as they wish to continue or
 * their balance reaches zero, then their betting history is output to a text file.
 *
 */

// This include section adds extra definitions from the C++ standard library.

#include <iostream>
#include <string>
#include "Football.h"
#include <vector>
#include <fstream>

using namespace std;

int main() {
    vector<string> teams; //Creates vector to store team names.
    Football football; //Creates Football object.

    //Declares variables as integers.
    int teamToWin;
    int teamToLose;
    int currentBalance;
    int currentBet;



    //Populates teams vector with the team names.
    teams.push_back("Aces");
    teams.push_back("Blaze");
    teams.push_back("Clowns");
    teams.push_back("Dragons");
    teams.push_back("Ninjas");
    teams.push_back("Riot");
    teams.push_back("Stealth");
    teams.push_back("Venom");
    teams.push_back("Warriors");
    teams.push_back("Wildcats");

    //Explains rules of game to user.
    football.introduction();
    cout <<endl;

    //Prompts user to enter their balance.
    cout <<"Enter your balance: ";
    cin >> currentBalance;

    //Do-While loop that continues to allow user to play game while they wish to continue. Loop exits when
    //user enters -1 when prompted for bet, or when players balance reaches 0.
    do{
        ofstream file ("Football.txt"); //Creates ofstream object ot open Football.txt file.

        cout <<"Enter your bet: "; //Prompts user to enter bet.
        cin >> currentBet;  //Stores bet into currentBet.
        file << currentBet; //Writes bet to Football.txt file.

        //Checks to see if user wishes to quit playing.
        if(currentBet == -1){
            break;
        }
        //If user enters negative bet, then bet is changed to positive.
        else if(currentBet < -1){
            currentBet = currentBet * -1;
        }

        //Sets the users bet using currentBet as a parameter.
        football.setBet(currentBet);

        //Prompts user to enter team number corresponding to their anticipated winner.
        cout <<"Choose your anticipated winner by entering a number 1 - 10: ";
        cin >> teamToWin;
        //Checks that anticipated winner's team number is in valid range.
        while(teamToWin < 1 || teamToWin > 10){
            cout <<"Team number out of range, try again: ";
            cin >> teamToWin;
        }
        //Prompts user to enter team number corresponding to their anticipated loser.
        cout <<"Choose your anticipated loser by entering a number 1 - 10: ";
        cin >> teamToLose;
        //Checks that anticipated loser's team number is in valid range.
        while(teamToLose < 1 || teamToLose > 10) {
            cout <<"Team number out of range, try again: ";
            cin >> teamToLose;
        }

        cout <<endl;
        cout <<"The " <<teams[teamToWin-1] <<" vs. " <<teams[teamToLose-1] <<endl; //Outputs users team choices.
        cout <<"LET'S PLAY FOOTBALL!" <<endl;
        cout <<endl;

        football.setScore1(); //Randomly sets score for anticipated winner.
        football.setScore2(); //Randomly set score for anticipated loser.
        football.playGame(); //Checks to see who won game based on scores of the teams.

        //Outputs the scores from the game.
        cout << teams[teamToWin-1] <<": " <<football.getScore1() <<" " <<teams[teamToLose-1] <<": " <<football.getScore2() <<endl;

        //Outputs whether user won bet based on the team scores.
        if (football.getScore1() > football.getScore2()){
            cout <<"Congratulations you won!" <<endl;
        }
        else if (football.getScore2() > football.getScore1()){
            cout <<"Sorry, you lost. Better luck next time!" <<endl;
        }
        else if(football.getScore1() == football.getScore2()){
            cout<<"Tie game! You push." <<endl;
        }

        //Sets balance based on result of the game and updates currentBalance.
        football.setBalance(currentBalance);
        currentBalance = football.getBalance();

        file <<currentBalance;//Writes players balance to Football.txt file.

        //Outputs the user's balance based on results of the game.
        cout<<"Your current balance is: $" <<currentBalance <<endl;
        cout <<endl;

    } while(currentBet != -1 and currentBalance > 0);

    //Outputs players balance if user has lost all their money.
    if(currentBalance <= 0){
        cout <<"Thank you for playing!" <<endl;
        cout <<"Your final balance is: $0";
    }
    //Outputs players balance if user enters -1 to quit the game.
    if(currentBet == -1){
        cout <<"Thank you for playing!" <<endl;
        cout <<"Your final balance is: $" <<currentBalance;
    }

    return 0;
}
