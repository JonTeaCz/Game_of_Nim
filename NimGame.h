#ifndef NIMGAME_H // Include guard to prevent multiple includes of this header file
#define NIMGAME_H

#include "PlayByPlay.h" // Include statement for the PlayByPlay header file.
#include "Participant.h" // Include statement for the Participant header file.

#include <iostream> // Include statement for the iostream library.

class NimGame{ // Definition of the NimGame class
    private:
        static int order; // Static variable declaration for the order of the game
    public:
        static int marbles; // Static variable declaration for the number of marbles in the game
        Participant* p1; // Pointer variable declaration for the first participant of the game
        Participant* p2; // Pointer variable declaration for the second participant of the game

        // Static member function definition for getting the order of the game

        /**
         * @brief getter function for order
         * @return Returns the order member
        */

        static int getOrder(){
            return order;
        }

        // Static member function definition for setting the order of the game

        /**
         * @brief setter function for order
         * @param n sets order = to n
        */

        static void setOrder(int n){
            order = n;
        }

        // Static member function definition for taking a specified number of marbles from the game

        /**
         * @brief removes n amount of marbles from pile
         * @param takes away input n amount of marbles 
        */

        static void take(int n){
            marbles -= n;
        }

        // Default constructor definition for the NimGame class

        /**
         * @brief regular default constructor
        */
       
        NimGame(){
        }

        // Destructor definition for the NimGame class

        /**
         * @brief deletes memory allocated for first and second particpants
        */

        ~NimGame(){
            delete p1; // Delete the memory allocated for the first participant
            delete p2; // Delete the memory allocated for the second participant
        }
};
#endif // End of the include guard