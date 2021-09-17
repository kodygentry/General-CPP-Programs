#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
#include "user.h"

vector<User> loadUserDatabase(ifstream &in){
    string userName;
    unsigned long long passwordHash;
    vector<User> userDatabase;
    while (in >> userName >> passwordHash)
        userDatabase.push_back(User(userName,passwordHash));

    return userDatabase;

    /*
     * takes a file input identifier
     * inputs file contents - username and hashed password
     * into a vector of the datatype User
     */
}

void saveUserDatabase(ofstream &of, vector<User>& userDatabase) {
    unsigned int size = userDatabase.size();

    for (int i = 0; i < size; ++i) {
        of << userDatabase[i].getUsername() << " " << userDatabase[i].getPasswordHash()
           << endl;
    }
    of.close();

    /*
     * takes a vector of the User class and a file output identifier
     * then outputs vector contents into file
     */
}

void printError(int errorCase){
    if(errorCase == 1){
        cout << "New password does not meet criteria, password not changed.\n";
    }
    else if(errorCase == 2){
        cout << "Old password is incorrect, password not changed.\n";
    }
    else if(errorCase == 3) {
        cout << " User with the given name not exist, password not changed.\n";
    }
    /*
     * a function that prints error messages
     * depending on the error case number
     * errorCase provided in int main()
     */
}

bool userFound(const vector<User>& userDatabase, string userNameInput) {
    // initialize size of list
    unsigned int size = userDatabase.size();
    bool found = false;

    // loop through vector username's to find a match
    for (unsigned int i = 0; i < size; i++) {
        if (userNameInput == userDatabase[i].getUsername()) {
            found = true;
            return true;
        } else
            return false;
    }

    /*
     * takes a vector of datatype User and an inputted username
     * returns true if match found
     */
}


int main() {

    // declare variables for user input
    string userNameInput, oldPasswordInput, newPasswordInput;

    // show menu (username, password and new password)
    cout << "Please enter your username:";
    cin  >> userNameInput;
    cout << "Please enter your old password:";
    cin  >> oldPasswordInput;
    cout << "Please enter your new password:";
    cin  >> newPasswordInput;

    // read file
    ifstream in("userDatabase.txt");

    // declare User field variables
    string username;
    unsigned long long password;

    // copy database vector into a local vector (ease of access)
    vector<User> userDatabase = loadUserDatabase(in);

    // assign size to the how many users are in the database
    unsigned int size = userDatabase.size();

    // compare inputted username to database username's
    for (unsigned int i = 0; i < size; i++) {
        if (userNameInput == userDatabase[i].getUsername()) {
            username = userDatabase[i].getUsername();
            password = userDatabase[i].getPasswordHash();
        }
    }

    // User class object with parameters satisfied from userDatabase
    User u (username, password);

    // if the inputted username is found in the database...
    if(userFound(userDatabase, userNameInput)){
        // if the inputted password, after being hashed,
        // matches hashed password connected to username in the database...
        if(u.authenticate(oldPasswordInput)){
            // if new password meets criteria, hash it and set it
            // as 'hashedPassword' class field...
            if(u.setNewPassword(newPasswordInput)){
                ofstream of("userDatabase.txt");
                saveUserDatabase(of, userDatabase);
                cout << "Password has been changed for user: "
                     << username << endl;
            } else
                printError(1); // call error function of case #1, same for the below
        } else
            printError(2);
    } else
        printError(3);

    return 0;
}