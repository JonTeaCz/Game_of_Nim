#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>

class Account {
private:
    std::string userName;
    std::string password;

    /**
     * @brief This declares a static vector named 'accounts' to store accounts
    */

    static std::vector<Account> accounts;

public:

    /**
     * @brief This function defines a static method to return the static vector
    */

    static std::vector<Account>& getAccounts() { // Define a static method to return the static vector
        return accounts;
    }

    /**
     * @brief Defines a class Account with member functions for creating and managing accounts 
     * @param userName,password The private member variables of the Account object being created with the corresponding input parameters passed in
    */

    Account(const std::string& userName, const std::string& password) : userName(userName), password(password){}

    /**
     * @brief Member function of the Account class that returns the userName associated with the Account object 
    */

    const std::string& getUserName() const { return userName; }

    /**
     * @brief Member function of the Account class that returns the password associated with the Account object
    */

    const std::string& getPassword() const { return password; }

    /**
     * @brief Member function of the Account class that sets the userName of an Account object to a new value
     * @param newUserName Object representing the new username that the function will set as the userName of the Account object.
    */

    void setUserName(const std::string& newUserName) { userName = newUserName; }

    /**
     * @brief Member function of the Account class that sets the password of an Account object to a new value
     * @param NewPassword Object representing the new password that the function will set as the password of the Account object
    */

    void setPassword(const std::string& newPassword) { password = newPassword; }


    /**
     * @brief defines a static member function findAccount() that returns a pointer to an Account object with a given username
     * @param username which is the username to search for in the accounts vector
    */

    static Account* findAccount(const std::string& username) {
        for (std::vector<Account>::iterator acc = accounts.begin(); acc != accounts.end(); ++acc) { // Loops through all the accounts in the vector
            if (acc->getUserName() == username) { // Ff there is a match, then return a pointer to the account
                return &(*acc); // returns the account
            }
        }
        return nullptr; // If there is no account with the given username, return nullptr
    }
};

std::vector<Account> Account::accounts; // Define the static vector outside the class definition


#endif