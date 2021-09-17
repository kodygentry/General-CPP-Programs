// File Name: assign4_kmg221.cpp
//
// Author: Kody Gentry
// Date: 10/15/2019
// Assignment Number: 4
// CS 1428.003 Fall 2019
// Instructor: Jill Seaman
//
// PROGRAM THAT CALCULATES DESIRED OCCUPANCY RATES
// AND PRINTS REPORT TO A FILE.


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

    // GLOBAL VARIABLES //
    int numFloors;
    int numRooms;
    int numOccupied;
    double occupied;
    int totalRooms = 0;
    int totalOccupied = 0;

    string stringFloors   = "Please enter the number of floors: ";
    string stringRooms    = "Please enter the number of rooms on floor ";
    string stringOccupied = "Please enter the number of occupied rooms on that floor: ";

// FUNCTION PROTOTYPES/MAIN () //
int main()
{

    // OUTPUT FILE OPEN [] //
    ofstream fout ("occupancy_report.txt");

    // SET UP FILE [] //
    fout << left <<  setw(10) << left << "Floor" << setw(12) << "% Occupied" << endl;
    fout << fixed << setprecision(1);


    // FLOOR INPUT >> //
        cout << stringFloors;
        cin  >> numFloors;
    // ERROR TEST ! //
    while (numFloors <= 0)
    {
        cout << "The hotel must have at least one floor, please re-enter: ";
        cin  >> numFloors;
    }

    // ROOM INPUT >> //
    for (int k=0; k<numFloors; k++)
    {
        cout << stringRooms << (k+1) << ":";
        cin  >> numRooms;
    // ERROR TEST ! //
        while (numRooms < 0)
        {
            cout << "The number of rooms cannot be negative, please re-enter: ";
            cin  >> numRooms;
        }
        totalRooms += numRooms;


        // OCCUPIED INPUT >> //
            cout << stringOccupied;
            cin  >> numOccupied;
        // ERROR TEST ! //
        while (numOccupied < 0 || numOccupied > numRooms)
        {
            cout << "The number of occupied rooms cannot be greater than "
                 << "the number of rooms, please re-enter: ";
            cin  >> numRooms;
        }
        totalOccupied += numOccupied;

        // OCCUPIED % //
        if (numRooms == 0)
            occupied = 0;
        else
            occupied = ((numOccupied*100.00)/numRooms);

    // PRINT TO FILE [] //

    fout << left << setw(10) << (k+1) << left << setw(12) << occupied;

    if (occupied < 20)
        fout << "**low occupancy**";
    fout << endl;
    }

    // TOTALS REPORT
    occupied = ((totalOccupied*100)/totalRooms);

    fout << endl << "The Hotel has " << totalRooms << " rooms" << endl;
    fout << totalOccupied << " rooms are occupied. " << occupied
         << "% of the rooms are occupied.";

    fout.close();

    cout << "The report was successfully stored in the file: "
         << "occupancy_report.txt" << endl;


    return 0;
}