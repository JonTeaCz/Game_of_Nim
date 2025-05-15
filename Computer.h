// Header guard to prevent multiple inclusions of the same file
#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>
#include <vector>
#include "Mode.h"

// A class for the computer player
class COMPUTER : public Participant {
    private:
        // A vector of "cheat" values used in level 0 mode
        std::vector<int> cheat = { 3, 7, 15, 31, 63, 127, 255, 511 };
        std::string name = "Bot"; // The name of the computer participant
    public:

        /**
         * @brief display is just used to call PlayByPlay print functions
        */
       
        PlayByPlay display; // The play-by-play object used to display the computer's move
        // Default constructor for the computer player

        /**
         * @brief regular default constructor
        */
       
        COMPUTER(){
        }

        // Getter method for the computer player's name

        /**
         * @return returns name of the computer
        */
       
        std::string getName() {
            return name;
        }

        // Method to take marbles from the game


        /**
         * @brief level 0, put the bot into advance mode which makes it take away a certain amount of marbles
         * that is in the sequence { 3, 7, 15, 31, 63, 127, 255, 511 }, and if it can't then it will just
         * take a random amount from 1 to half of the pile size. If level is 1, then it just chooses a random
         * amount of marbles to take, again from 1 to half of the pile size. 
        */
       
        void takeMarbles() {
            int n;

            // If the game mode is level 0
            if(Mode::level == 0) {
                bool found = true;
                // Iterate through the cheat vector in reverse order
                for(int i = cheat.size() - 1; i >= 0; i--) {
                    // If the current cheat value is less than the number of marbles 
                    //in the game and it has not already been used, calculate the number of marbles to take
                    if(cheat[i] < NimGame::marbles && found && cheat[i] != NimGame::marbles) {
                        n = NimGame::marbles - cheat[i];
                        // If the number of marbles to take is less than or equal to 
                        //half of the remaining marbles, mark found as false and exit the loop
                        if(n <= NimGame::marbles / 2) {
                            found = false;
                        }
                    }
                }
                // If a valid cheat value was not found, take a random
                // number of marbles between 1 and half of the remaining marbles
                if(found) {
                    n = rand() % (NimGame::marbles / 2) + 1;
                }
        // If the game mode is level 1, take a random number of marbles between 1 and half of the remaining marbles
            } else if(Mode::level == 1) { 
                n = rand() % (NimGame::marbles / 2) + 1;
            }

            // Display the computer's move
            display.nextMove(name, n);
            std::cout << "Bot took " << n << " marbles" << std::endl; // Print the number of marbles the computer took
            NimGame::take(n); // Take the marbles from the game
        }
};
#endif // End of header guard to prevent multiple inclusions of the same file