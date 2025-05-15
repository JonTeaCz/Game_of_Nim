
// Header guards to avoid multiple definitions of the Player class
#ifndef PLAYER_H
#define PLAYER_H

// Includes necessary headers
#include <string>
#include <iostream>

// Includes the base class Participant and the class NimGame
#include "Participant.h"
#include "NimGame.h"

// Player class declaration
class Player : public Participant{
private:
    std::string name;
public:

    /**
     * @brief display is just used to call PlayByPlay print functions
    */

    PlayByPlay display; // Object of the PlayByPlay class to display game progress
    Player(); // Default constructor
    void takeMarbles(); // Function to take marbles from the pile


    /**
     * @return returns name of the player
    */
        
    std::string getName(){ // Function to get the player's name
        return name;
    }
    };

// End of header guard
#endif