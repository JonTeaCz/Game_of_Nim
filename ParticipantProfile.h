#ifndef PARTICIPANTPROFILE_H
#define PARTICIPANTPROFILE_H

#include <string> // Include statement for the string library
#include <iostream> // Include statement for the iostream library

using namespace std;

class ParticipantProfile{ // Definition of ParticipantProfile Class
    private:
        // Variables to keep track of score, games played, and win percentage
        std::string name;
        double gamesPlayed, humanGames, botGames, gamesWon, wonHuman, wonBot;
        double percentage, percenthum, percentcomp;
    public:
        // Default Constructor
        ParticipantProfile(){
            gamesPlayed = humanGames = botGames = gamesWon = wonHuman = wonBot = 0;
            percentage =  percenthum = percentcomp = 0;

        }
        // Functions to Update game statistics

        /**
         * @brief itterates gamesPlayed
        */

        void iterGP(){
            gamesPlayed = gamesPlayed + 1;
        }

        /**
         * @brief itterates gamesWon
        */
       
        void iterGW(){
            gamesWon = gamesWon +1;
        }

        /**
         * @brief itterates variable wonHumans
        */
       
        void iterWH(){
            wonHuman = wonHuman + 1;
        }

        /**
         * @brief itterates variable wonBot
        */
       
        void iterWB(){
            wonBot = wonBot + 1;
        }

        /**
         * @brief itterates humanGames
        */
       
        void iterHG(){
            humanGames = humanGames + 1;
           
        }

        /**
         * @brief itterates botGames
        */
       
        void iterBG(){
            botGames = botGames +  1; 
        }

        // function to calculate all win Percentages

        /**
         * @brief sets all percentage variables such as 
         * total win percentage, percenthum, and percentcomp
        */
       
        void setAllPercentages(){
            if (gamesPlayed == 0) {
                percentage = 0;
            } else {
                percentage = (gamesWon / gamesPlayed) * 100;
            }
            if (humanGames == 0) {
                percenthum = 0;
            } else {
                percenthum = (wonHuman / humanGames) * 100;
            }
            if (botGames == 0) {
                percentcomp = 0;
            } else {
                percentcomp = (wonBot / botGames) * 100;
            }
        }

        // getter functions to access private data

        /**
         * @return returns gamesPlayed
        */
       
        double getGamesPlayed() const{
            return gamesPlayed;
        }

        /**
         * @return returns gamesWon
        */
       
        double getGamesWon() const{
            return gamesWon;
        }

        /**
         * @return percentage
        */
       
        double getWP() const{
            return percentage;
        }

        /**
         * @return returns percenthum
        */
       
        double getWPH() const{
            return percenthum;
        }

        /**
         * @return returns percentcomp
        */
       
        double getWPB() const{
            return percentcomp;
        }
        
        // friend function to overload output operator

        /**
         * @brief overloads the << opertator to cout the statistics
         * @param out,info info is the participantprofile which is being accessed and out is the ostream that is being written to
         * @return returns an ostream which can be printed
        */
       
        friend std::ostream& operator<<(std::ostream& out, const ParticipantProfile& info){
            out << "GAMES PLAYED: " << info.getGamesPlayed() << endl;
            out << "Games Won: " << info.getGamesWon() << endl;
            out << "OVERALL WIN PERCENTAGE: " << info.getWP() << "%" << endl;
            out << "WIN PERCENTAGE VS HUMAN: " << info.getWPH() << "%" << endl;
            out << "WIN PERCENTAGE VS COMPUTER: " << info.getWPB() << "%" << endl;
            return out;
        }
};

#endif