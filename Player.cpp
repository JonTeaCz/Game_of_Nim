//This code implements the Player class that is derived from Participant class and allows a user to take marbles from the NimGame.

#include "Player.h"
#include <iostream>
using namespace std;

//Player constructor prompts the user to enter their name and assigns it to the name data member.
Player::Player(){
cout << "ENTER YOUR NAME: ";
cin >> name;
}

//takeMarbles function allows the user to select a valid number of marbles to take from the NimGame.

/**
 * @brief This function asks user for input, and calls the take function from NimGame
 * it checks input to see if its valid for the rules of the game
 * 
*/

void Player::takeMarbles(){
    int n;
    while(1){
        std::cout << "Enter a number ";
        std::cin >> n;
        if((n <= NimGame::marbles / 2) && (n > 0)){
            break;
        }else{
            std::cout << "INVALID NUMBER " << std::endl;
        }
    }
    //display the play in the text file
    display.nextMove(name, n);
    //take n marbles from the NimGame
    NimGame::take(n);
}