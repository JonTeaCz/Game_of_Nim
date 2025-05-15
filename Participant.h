#ifndef PARTICIPANT_H // Include guard to prevent multiple includes of this header file
#define PARTICIPANT_H

#include <string> // Include statement for the string library
#include "ParticipantProfile.h" // Include statement for the ParticipantProfile header file
#include <iostream> // Include statement for the iostream library

class Participant{ // Definition of the Participant class
    private:
        std::string name; // Private variable declaration for the name of the participant

    public:
    ParticipantProfile info; // Public object declaration for the ParticipantProfile object
    virtual std::string getName() = 0; // Virtual member function declaration for getting the name of the participant
    virtual void takeMarbles() = 0; // Virtual member function declaration for taking marbles from the game

    /**
     * @brief for printing the information of the participant
    */

    void printInfo(){ // Member function definition for printing the information of the participant
        cout << info << endl; // Output the information of the participant
    }
    //void setName(std::string ); // Commented out member function declaration for setting the name of the participant
};

#endif // End of the include guard