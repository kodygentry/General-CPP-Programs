// File Name: assign2_kmg221.cpp
//
// Author: Kody Gentry
// Date: 2/22/2020
// Assignment Number: 2
// CS 2308 Spring 2020
// Instructor: Vladyslav Prokopenko
//
// a program that processes a restaurant database

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

struct Restaurant{
    string name;
    string city;
    int rank{};
    double rating{};
    string priceRange;
    int reviews{};
};

int readRestaurants(ifstream &in, Restaurant restaurant[]){

    string rankStr, ratingStr, reviewsStr; // temporary strings
    string titles; // header variable
    int SIZE = 0; // index

    getline(in, titles); // skips first line (header)

    // assigns file data to struct array
    while(getline(in, restaurant[SIZE].name, ',')){

        getline(in, restaurant[SIZE].city, ',');

        getline(in, rankStr, ',');
        restaurant[SIZE].rank = stoi(rankStr); // string to int

        getline(in, ratingStr, ',');
        restaurant[SIZE].rating = stod(ratingStr); // string to double

        getline(in, restaurant[SIZE].priceRange, ',');

        getline(in, reviewsStr);
        restaurant[SIZE].reviews = stoi(reviewsStr); //string to int

        SIZE++;
    }

    return SIZE;
}
void printRestaurants(int SIZE, Restaurant restaurant[]){

    // print header
    cout << left << setw(26) << "Name "
         << left << setw(11) << "City "
         << "Ranking "
         << "Rating "
         << left << setw(8)  << "Price Range "
         << "Reviews\n";
    for(int k=0; k<70; k++){
        cout << "-";
    }
    cout << endl;


    for (int i=0; i<SIZE; i++) {
        cout << left << setw(25) << restaurant[i].name << " "
             << left << setw(10) << restaurant[i].city << " "
             << left << setw(7)  << restaurant[i].rank << " "
             << left << setw(6)  << restaurant[i].rating << " "
             << left << setw(11) << restaurant[i].priceRange << " "
             << left << setw(6)  << restaurant[i].reviews << endl;
    }
}
void printRestaurant(int position, Restaurant restaurant[]){

    // prints a single restaurant given an index
    cout << left << setw(25) << restaurant[position].name << " "
         << left << setw(10) << restaurant[position].city << " "
         << left << setw(7)  << restaurant[position].rank << " "
         << left << setw(6)  << restaurant[position].rating << " "
         << left << setw(11) << restaurant[position].priceRange << " "
         << left << setw(6)  << restaurant[position].reviews << endl;
}
void sortRestaurantsByName(int SIZE, Restaurant restaurant[]){

    // compares first letters of each name
    bool swapped = false; // loop condition
    do {
        swapped = false;
        for (int i=0; i<(SIZE-1); i++) {
            if ((int)restaurant[i].name[0] > (int)restaurant[i+1].name[0]){
                swap(restaurant[i], restaurant[i+1]);
                swapped = true;
            }
            else if((int)restaurant[i].name[0] == (int)restaurant[i+1].name[0]){
                if((int)restaurant[i].name[1] > (int)restaurant[i+1].name[1]) {
                    swap(restaurant[i], restaurant[i+1]);
                    swapped = true;
                }
                else if((int)restaurant[i].name[1] == (int)restaurant[i+1].name[1]) {
                        if((int)restaurant[i].name[2] > (int)restaurant[i+1].name[2]) {
                            swap(restaurant[i], restaurant[i+1]);
                            swapped = true;
                        }
                        else if((int)restaurant[i].name[2] == (int)restaurant[i+1].name[2]) {
                            if ((int) restaurant[i].name[3] > (int) restaurant[i + 1].name[3]) {
                                swap(restaurant[i], restaurant[i + 1]);
                                swapped = true;
                            }
                        }
                }
            }
        }
    }while(swapped);

}
void sortRestaurantsByRank(int SIZE, Restaurant restaurant[]){
    bool swapped = false; // loop condition variable

    do {
        swapped = false;
        for (int i=0; i<(SIZE-1); i++) {
            if (restaurant[i].rank > restaurant[i+1].rank){
                swap(restaurant[i], restaurant[i+1]);
                swapped = true;
            }
        }
    }while(swapped);
}
int binarySearchName(int SIZE, const string& target, Restaurant restaurant[]){
    int first = 0,
        last = SIZE-1,
        middle,
        position = -1;
    bool found = false;

    while(first<=last && !found){
        middle = (first+last)/2;

        if(restaurant[middle].name == target){
            found = true;
            position = middle;
        }
        else if(target<restaurant[middle].name){
            last = middle-1;
        }
        else{
            first = middle+1;
        }
    }
    return position;
}
bool isInPriceRange(const string& targetPrice, string priceRange){
    if(targetPrice == "$"){
        priceRange = "$";
        return true;
    }
    else if(targetPrice == "$$"||targetPrice == "$$$"){
        priceRange = "$$-$$$";
        return true;
    }
    else if(targetPrice == "$$$$"){
        priceRange = "$$$$";
        return true;
    }
    else{
        return false;
    }
}
int findBestRestaurantWithPrice(int SIZE, const string& targetPrice, Restaurant restaurant[]){
    string priceRange;
    while(isInPriceRange(targetPrice, priceRange)){
        if(targetPrice == "$") {
            priceRange = "$";
            for (int i = 0; i < SIZE; i++) {
                if (restaurant[i].priceRange == priceRange) {
                    return i;
                }
            }
        }
        else if (targetPrice == "$$" || targetPrice == "$$$") {
            priceRange = "$$ - $$$";
            for (int i = 0; i < SIZE; i++) {
                if (restaurant[i].priceRange == priceRange) {
                    return i;
                }
            }
        }
        else if (targetPrice == "$$$$") {
            priceRange = "$$$$";
            for (int i = 0; i < SIZE; i++) {
                if (restaurant[i].priceRange == priceRange) {
                    return i;
                }
            }
        }
        else{
            cout << "No matching desired price\n";
            return false;
        }
    }

}

int main() {

    ifstream in("restaurants.csv"); // open file
    if (!in) {
        cout << "File failed to open!";
        return -1;
    }

    Restaurant restaurant[100]; // struct array, max 100
    int const SIZE = readRestaurants(in, restaurant);

    bool running = true;   // main program loop condition
    int actionChoice = 0; // user menu choice

    // MAIN LOOP
    do {
        cout << "Select the action:\n"
             << "1) Show restaurants sorted by name\n"
             << "2) Show restaurants sorted by rank\n"
             << "3) Find a restaurant by name\n"
             << "4) Find the best restaurant with a price\n"
             << "5) Exit the program\n";
        cin >> actionChoice;


        // USER MENU CHOICES
        if (actionChoice == 1) {
            sortRestaurantsByName(SIZE, restaurant);
            printRestaurants(SIZE, restaurant);
        }

        else if (actionChoice == 2) {
            sortRestaurantsByRank(SIZE, restaurant);
            printRestaurants(SIZE, restaurant);
        }

        else if (actionChoice == 3) {
            string target; // name target for searching
            cout << "Find a restaurant by name:";
            cin.ignore();
            getline(cin, target); // user input

            sortRestaurantsByName(SIZE, restaurant);
            int position = binarySearchName(SIZE, target, restaurant); // index of position
            printRestaurant(position, restaurant); // print elements with said index
        }

        else if (actionChoice == 4) {
            string targetPrice, // user target price
                   priceRange; // price range format from file
            cout << "Enter price range ($, $$, $$$, or $$$$):";
            cin  >> targetPrice;

            sortRestaurantsByRank(SIZE, restaurant);  // sort names for binary search
            isInPriceRange(targetPrice, priceRange); // determines if input is in range
            int index = findBestRestaurantWithPrice(SIZE, targetPrice, restaurant); // searches binary
            printRestaurant(index, restaurant);
        }

        else if (actionChoice == 5){
            cout << "Exiting program...";
            running = false;
        }

        else
            cout << "**Invalid input, choose action 1, 2, 3 or 4.**\n";

    } while (running);
    return 0;
}
