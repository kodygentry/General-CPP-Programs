// User class
// class declaration (specification)

#ifndef PA4_USER_H
#define PA4_USER_H

#include <string>
using namespace std;

class User {
public:
    // public members
    User(string, unsigned long long);             // constructor
    string getUsername() const;                  // password getter
    unsigned long long getPasswordHash() const; // hashed password getter
    bool authenticate(string);                 // password authenticator
    bool setNewPassword(string);              // new password checker/initializer
private:
    // private fields
    string userName;                     // field holding User username
    unsigned long long hashedPassword;  // field holding User hashed password

    // private members
    unsigned long long hash(string); // algorithm that encrypts a string
    bool meetsCriteria(string);     // checks 4 requirements for a new User password
};

#endif