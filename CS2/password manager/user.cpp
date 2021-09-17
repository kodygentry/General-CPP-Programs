// User class
// Member function definitions (implementation)
// Stores user data (hashed password etc)

using namespace std;
#include "user.h"

/// PUBLIC MEMBERS
User::User(string username, unsigned long long password) {
    userName = username;
    hashedPassword = password;

    /*
     * class User constructor
     * assigns values to private fields - username and passwordHashed
     */
}

string User::getUsername() const {
    return userName;

    /*
     * returns private field value for username
     */
}

unsigned long long User::getPasswordHash() const {
    return hashedPassword;

    /*
     * returns private field value for hashed password
     */
}

bool User::authenticate(string password){
    // hash inputted password and store it in function
    unsigned long long inputHashedPassword = hash(password);

    // if this hashed password matches hashed password assigned to given username
    // return true
    if (inputHashedPassword == hashedPassword){
        return true;
    } else
        return false;


    /*
     * takes an input password (string)
     * hashes input password
     * return true if input password matches password stores in User
     */
}

bool User::setNewPassword(string password){
    // test if inputted password (string) meets criteria
    // if so, hash it and store in User hashedPassword
    if (meetsCriteria(password)){
        hashedPassword = hash(password);
        return true;
    } else
        return false;

    /*
     * takes an inputted password (string)
     * checks if meets requirements
     * if sp, hashes password and stores it in User password field
     */
}


/// PRIVATE MEMBERS
unsigned long long User::hash(string s){
    unsigned long long h = 0;
    for (int i = 0; i < s.size(); i++){
        h = s[i] + (h << 6) + (h << 16) - h;
    }
    return h;

    /*
     * takes a string password
     * converts it to hash
     * returns hashed password
     */
}

bool User::meetsCriteria(string password) {
    // initialize length of password to SIZE
    const int SIZE = password.size();

    // check for upper, lower and digit
    if (password.size() > 7) {
        for (int i = 0; i < SIZE; i++) {
            if (isupper(password[i])) {
                for (int j = 0; j < SIZE; j++) {
                    if (isdigit(password[j])) {
                        return true;
                    }
                }
            }
        }
    } else {
        return false;
    }

    /*
     * takes an inputted new password
     * checks each requirement for new password
     * using nested if statements and returns true/false
     */
}