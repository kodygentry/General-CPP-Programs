// File Name: assign7_kmg221.cpp
//
// Author: KODY GENTRY
// Date: 12/2/2019
// Assignment Number: 7
// CS 1428.003 Fall 2019
// Instructor: Jill Seaman
//
// program that manages data about lab rats

#include <iostream>
#include <iomanip>
using namespace std;


const int SIZE = 7;

struct LabRat
  {
    string name;
    double weight;
    int time;
    string rating;
  };

int main()
{
    // INPUT STRUCTS INTO ARRAY //
    LabRat rat[] = {
        {"Ben",6.5},
        {"Fred",5.8},
        {"Splinter",7.7},
        {"Lima Bean",6.5},
        {"Black Bean",5.8},
        {"Big Pook",9.8},
        {"Tiger",7.7}
    };

    // GET TIME INPUT //
    cout << "Enter the maze time for each rat: " << endl;
    for (int i=0; i<SIZE; i++)
    {
        cout << rat[i].name << ": ";
        cin  >> rat[i].time;
    }
        cout << endl;

    // RATING CALC. //
    for (int i=0; i<SIZE; i++)
    {
      if (rat[i].time<30)
	rat[i].rating = "Superior";
      else if (rat[i].time>=30 && rat[i].time<35)
	rat[i].rating = "Normal";
      else
	rat[i].rating = "Slow";
    }

    // OUTPUT TABLE //
    cout << "Name" << setw(13) << setfill(' ')
         << "Weight" << setw(8) << setfill(' ')
         << "Time" << setw(12) << setfill(' ')
         << "Rating" << endl;
    for (int i=0; i<SIZE; i++)
    {
        cout << left << setw(11) << setfill(' ')
             << rat[i].name << setw(11) << setfill(' ')
             << rat[i].weight << setw(8) << setfill(' ')
             << rat[i].time << setw(10) << setfill(' ')
             << rat[i].rating << endl;
    }
    cout << endl;

    // OUTPUT AVG WEIGHT //
    double sum = 0.0, avg;
    for (int i=0; i<SIZE; i++)
        sum += rat[i].weight;
    avg = sum/SIZE;
    cout << "Average weight: " << avg << endl << endl;

    // OUTPUT FASTEST RAT //
    int minimum = rat[0].time;
    string fastest;

    for (int i=1; i<SIZE; i++)
    {
        if (rat[i].time < minimum)
        {
        minimum = rat[i].time;
        fastest = rat[i].name;
        }
    }
    
    if (minimum == rat[0].time)
    {
        fastest = rat[0].name;
    }
    cout << "Fastest Rat: " << fastest << " " << "Time: " << minimum << endl;

    return 0;
}
