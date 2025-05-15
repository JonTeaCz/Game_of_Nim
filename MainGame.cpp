/*
* This C++ program creates a game based off the Game of Nim. It has two players, 
* and the second player can either be a computer or a human which is decided by player 1. 
* There is a pile of marbles randomly generated from 10 - 1000, and the order of players
* is also randomly defined. Players take turns taking marbles (they can take up to half of pile)
* until the pile is empty. Whoever took the last marble loses. You can replay this game, 
* and even keep track of your stats and player two stats as well. 
* Cecs 275 - Spring 2023
* Instructor Minthong Nyguyen
* @author George Elassal
* @author Jonathan Cerniaz
* @Version 1.7
*/

#include <string>
#include <vector>
#include <iostream>
#include "NimGame.h"
#include "Player.h"
#include "Computer.h"
#include <cmath>
#include <ctime>
#include <cstdlib>
#include "Account.h"

using namespace std;

//Global Variables
NimGame newgame;
COMPUTER* bot = new COMPUTER;
Player* localPlayer = new Player;

/**
 * @brief This code presents a command line game of Nim where the player selects to play against either another player or the computer, the number of marbles is initialized randomly, players take turns removing marbles until there is one left, and the game results are recorded in player objects.
*/

void play();

/**
 * @brief This function displays the start menu that asks if the use wants a game description, to play, or to exit the program
*/

void displayMainMenu();

/**
 * @brief This function displays the games description and how it is played
*/

void displayDescription();

/**
 * @brief This function asks the user if they want to start a new game or view the player stats
*/

void displayPlayMenu();

/**
 * @brief This function displays a farewell message that the program will shut down
*/

void exitProgram();

/**
 * @brief This function allows the user to create a new account or login to an existing account in a game, and if the login is successful, the user can play the game or view their stats until they choose to return to the login menu.
*/

void start();

/**
 * @brief This sets up a menu for a game where the player can choose to start a new game, view the game rules, or exit the program
*/

int main() {

    // set player 1 to human, and initialize variables for menu
    newgame.p1 = new Player;
    srand(time(nullptr));
    int choice = 0;
    bool exit = false;
    while (!exit){
        cout << endl;
        // show options - title screen
        displayMainMenu();
        cin >> choice;
        if (choice == 1) {
            // goes to the main menu for starting game
            start();
        } else if (choice == 2) {
            cout << endl;
            // shows rules and how to play
            displayDescription();
        } else if (choice == 3) {
            // Exit program
            exitProgram();
            exit = true;
        } else {
            // Input checking
            cout << endl;
            cout << "Invalid input. Please try again." << endl;
        }
    }
    return 0;
}

// Menu for actually playing the game
void displayPlayMenu(){
    cout << "=========================" << endl;
    cout << "        Play Menu        " << endl;
    cout << "=========================" << endl;
    cout << "Please select an option: " << endl;
    cout << "1) Start New Game" << endl;
    cout << "2) View Stats" << endl;
    cout << "3) Go Back" << endl;
    cout << "Please enter your choice (1 - 3): ";
}

// Actual Gameplay is programmed here
void play(){
    // Display options
    cout << "==============================" << endl;
    cout << "       Choose Opponent        " << endl;
    cout << "==============================" << endl;
    cout << "Please select an option:" << endl;
    cout << "0) Computer" << endl;
    cout << "1) Another PLAYER" << endl;
    cout << "Enter your choice (1 or 0): ";
    int n = 10;
    string turn;
    // user chooses pvp or pve
    while(!(n == 1 || n == 0)){
        cin >> n;
        if(!(n == 1 || n == 0)){
            cout << "Invalid input" << endl;
        }
    }
    // Initialize marbles and order randomly
    NimGame::marbles = rand() % 991 + 10;
    NimGame::setOrder(rand() % 2);
    cout << "STARTING MARBLE PILE: " << NimGame::marbles << endl;
    localPlayer->display.startingpile(NimGame::marbles);
    Mode diff;
    Mode::level = rand() %2;
    // Set difficulty
    if(n == 0){
        if(Mode::level == 1){
            cout << endl;
            cout << "Difficulty: Normal" << endl;
        }else if(Mode::level == 0){
            cout << endl;
            cout << "Difficulty: Advanced" << endl;
        }else{
            cout << endl;
            cout << "Error" << endl;
        }
    }
    cout << endl;
    // set player 2 to either a human or computer based on input
    if(n){
        
        newgame.p2 = localPlayer;
    }else{
        newgame.p2 = bot;
    }
    cout << endl;
    cout << "Player 1 is " << newgame.p1->getName() << endl;
    cout << "Player 2 is " << newgame.p2->getName() << endl;
    cout << endl;

    string winner;
    // Decide who goes first based on order variable
    if(NimGame::getOrder() == 1){
        cout << "Player 1 goes first!" << endl;
        cout << endl;
        localPlayer->display.theOrder(newgame.p1->getName());
        while(NimGame::marbles > 1){
            // Take turns taking marbles until there is one marbles left
            cout << "Player 1's turn..." << endl;
            newgame.p1->takeMarbles();
            localPlayer->display.marblesremain(NimGame::marbles);
            cout << "Remaining marbles: " << NimGame::marbles << endl;
            cout << endl;
            turn = newgame.p2->getName();
            winner = "p1";
            if(NimGame::marbles <= 1){
            break;}
            cout << "Player 2's turn..." << endl;
            newgame.p2->takeMarbles();
            localPlayer->display.marblesremain(NimGame::marbles);
            cout << "Remaining marbles: " << NimGame::marbles << endl;
            cout << endl;
            turn = newgame.p1->getName();
            winner = "p2";
        }
    }else if(NimGame::getOrder() == 0){
        cout << "Player 2 goes first!" << endl;
        cout << endl;
        localPlayer->display.theOrder(newgame.p2->getName());
        while(NimGame::marbles > 1){
            // Take turns taking marbles until there is one marbles left
            cout << "Player 2's turn..." << endl;
            newgame.p2->takeMarbles();
            localPlayer->display.marblesremain(NimGame::marbles);
            cout << "Remaining marbles: " << NimGame::marbles << endl;
            cout << endl;
            turn = newgame.p1->getName();
            winner = "p2";
            if(NimGame::marbles <= 1){
            break;}
            cout << "Player 1's turn..." << endl;
            newgame.p1->takeMarbles();
            localPlayer->display.marblesremain(NimGame::marbles);
            cout << "Remaining marbles: " << NimGame::marbles << endl;
            cout << endl;
            turn = newgame.p2->getName();
            winner = "p1";
        }
    }
    //iterate games played 
    newgame.p1->info.iterGP();
    newgame.p2->info.iterGP();
    newgame.p2->info.iterHG();
    if(n == 1){
        newgame.p1->info.iterHG();
    }else if(n == 0){
        newgame.p1->info.iterBG();
    }

    //iterate games won for player 1
    if(winner == "p1"){
        newgame.p1->info.iterGW();
        //itterate either games won against human or bots
        if(n == 1){
            newgame.p1->info.iterWH();
        }else if(n == 0){
            newgame.p1->info.iterWB();
        }
        localPlayer->display.finished(turn, newgame.p1->getName());
    //itterate games won for player 2 and it is always against a human
    }else if(winner == "p2"){
        newgame.p2->info.iterGW();
        newgame.p2->info.iterWH();
        localPlayer->display.finished(turn, newgame.p2->getName());
    }
    // Set win percentage for player 1 and player 2
    newgame.p1->info.setAllPercentages();
    newgame.p2->info.setAllPercentages();
    cout << turn << " took the last marble! Remaining marbles: 0" << endl;
    cout << turn << " loses!" << endl;
    cout << "========= GAME OVER =========" << endl;
}

// Starting menu
void displayMainMenu() {
    cout << "=============================" << endl;
    cout << " Welcome to the Game of Nim! " << endl;
    cout << "=============================" << endl;
    cout << "Please select an option: " << endl;       
    cout << "1) Play The Game of Nim" << endl;
    cout << "2) Game Description" << endl;
    cout << "3) Exit" << endl;
    cout << "Enter your choice (1-3): ";
}

//Login menu
void displayLoginMenu(){
    cout << "=========================" << endl;
    cout << "     Sign Up or Login    " << endl;
    cout << "=========================" << endl;
    cout << "Please select an option: " << endl;
    cout << "1) Create a new profile" << endl;
    cout << "2) Login to an existing profile" << endl;
    cout << "3) Go back to main menu" << endl;
    cout << "Please enter your choice (1-3): ";
}



// Menu implementation for login and playing
void start() {
    int choice = 0;
    bool back = false;

    while (!back) {
        cout << endl;
        displayLoginMenu();
        cin >> choice;

        if (choice == 1) { // Create new account
            string username, password;
            cout << endl;
            cout << "Create a username: ";
            cin >> username;
            cout << "Create a password: ";
            cin >> password;

            Account newAccount(username, password); // Creates a new account with inputted username and password
            Account::getAccounts().push_back(newAccount); // Add and save account to vector

            cout << endl;
            cout << "Account Creation: SUCCESS... continue by logging in! " << endl;

        } else if (choice == 2) { // Login to an existing account
            string username, password;
            cout << endl;
            cout << "Enter your username: ";
            cin >> username;

            // checks to see if acount is in data base
            Account* account = Account::findAccount(username);
            if (account == nullptr) {
                cout << "Account not found..." << endl;
            } else {
                // Must login to play the game
                cout << "Enter your password: ";
                cin >> password;
                if (account->getPassword() == password) { 
                    cout << "Account Login: SUCCESS..." << endl;
                    bool goback = false;
                    int input = 0;
                    cout << endl;
                    while(!goback) {
                        // After logging in the player enters the actual game
                        displayPlayMenu();
                        cin >> input;
                        cout << endl;

                        if (input == 1){
                            // Clear text file and start a new game
                            localPlayer->display.clearTxt();
                            play();
                        } else if (input == 2){
                            // Display the players' stats
                            cout << "PLAYER 1'S STATS: " << endl;
                            cout << newgame.p1->info << endl;
                            cout << endl;
                            cout << "PLAYER 2'S STATS: " << endl;
                            cout << newgame.p2->info << endl;
                        } else if (input == 3) {
                            //return to login menu
                            goback = true;
                        } else {
                            cout << endl;
                            cout << "Invalid input. Please try again." << endl;
                        }
                    }

                } else {
                    // check if password is correct
                    cout << endl;
                    cout << "Acccount Login: FAILED... Incorrect password" << endl;
                }   
            }

        } else if (choice == 3) { // Goes back to main menu
            back = true;
        }else {
            cout << endl;
            cout << "Invalid input. Please try again." << endl;
        }
    }
}

// Tells Players how to play
void displayDescription() {
    cout << "Game Description:" << endl
         << "Two players alternately take marbles from a pile." << endl
         << "In each move, a player chooses how many marbles to take." << endl
         << "The player or computer must take at least one but at most half of the marbles." << endl
         << "The player who takes the last marble loses." << endl
         << "Press any key and then ENTER to go back to the main menu...";
    cin.ignore();
    cin.get();
}

//Exit message
void exitProgram() {
    cout << "Thanks for playing! Goodbye" << endl;
    cout << "Exiting program..." << endl;
}