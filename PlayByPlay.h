#ifndef PLAYBYPLAY_H
#define PLAYBYPLAY_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include "NimGame.h" // include header file for the NimGame class

using namespace std;

class PlayByPlay {
private:
public:
    // constructor that creates a new file called "playbyplay.txt" and closes it

    /**
     * @brief this default constructor actually clears the text file
    */
    
    PlayByPlay() {
        std::ofstream outfile("playbyplay.txt");
        if(!outfile.is_open()){
            std::cout << "File was unable to be opened..." << endl;
            return;
        }
        outfile.close();
    }

    // function to clear the text file

    /**
     * @brief this function clears the text file
    */

    void clearTxt(){
        std::ofstream outfile;
        outfile.open("playbyplay.txt", std::ofstream::out | std::ofstream::trunc);
        outfile.close();
    }
    
    // function to write the name of the player and the number of marbles removed to the text file

    /**
     * @brief this displays the current move of the participant in the text file
     * @param playerName,marblesTaken it takes the players name and displays how many marbles they took
    */

    void nextMove(std::string playerName, int marblesTaken) {
        std::ofstream outfile("playbyplay.txt", std::ios_base::app);

        if(!outfile.is_open()){
            std::cout << "COULD NOT OPEN FILE" << std::endl;
        }
        outfile << playerName << " removes " << marblesTaken << " marbles. ";
        outfile.close();
    }

    // function to write the number of remaining marbles to the text file

    /**
     * @brief this function displays marbles left in the text file
     * @param marblesTaken this input is actually how many marbles are left
    */

    void marblesremain(int marblesTaken){
        std::ofstream outfile("playbyplay.txt", std::ios_base::app);

        if(!outfile.is_open()){
            std::cout << "COULD NOT OPEN FILE" << std::endl;
        }
        outfile <<  "Remaining marbles: " << marblesTaken  << endl;
        outfile.close();
    }

    // function to write the order of play to the text file

    /**
     * @brief  this simply displays the order in the text file
     * @param name it takes the name of the participant who goes first
    */


    void theOrder(std::string name){
        std::ofstream outfile("playbyplay.txt", std::ios_base::app);

        if(!outfile.is_open()){
            std::cout << "COULD NOT OPEN FILE" << std::endl;
        }
        outfile << name <<  " goes first " << endl;
        outfile.close();
    }

    // function to write the number of starting marbles to the text file

    /**
     * @brief this function displays the starting pile to the text file
     * @param marbles it takes an input from the NimGame marbles member
    */


    void startingpile(int marbles){
        std::ofstream outfile("playbyplay.txt", std::ios_base::app);

        if(!outfile.is_open()){
            std::cout << "COULD NOT OPEN FILE" << std::endl;
        }
        outfile <<  "Starting pile: " << marbles  << endl;
        outfile.close();
    }

    // function to write the loser and winner of the game to the text file

    /**
     * @brief prints to the text file the winner and final play
     * @param loser,winner these are strings that say who won and lost
    */

    void finished(std::string loser, std::string winner){
        std::ofstream outfile("playbyplay.txt", std::ios_base::app);

        if(!outfile.is_open()){
            std::cout << "COULD NOT OPEN FILE" << std::endl;
        }
        outfile << loser <<  " removed the last marble. Remaining marbles: 0 " << endl;
        outfile << winner << " WINS!!!" << endl;
        outfile.close();
    }


};

#endif