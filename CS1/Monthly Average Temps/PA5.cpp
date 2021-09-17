// File Name: assign5_kmg221.cpp
//
// Author: Kody Gentry (Worked with Pierce Herchede to help solve 
//                      some issues)
// Date: 10/28/2019
// Assignment Number: 5
// CS 1428.003 Fall 2019
// Instructor: Jill Seaman
//
//  a program that computes some statistics based on monthly average
//  temperatures for a given month in each of the years 1901 to 2016.

#include <iostream>
#include <string>
#include <fstream> 
#include <iomanip> 

#define MAX_COUNT 116 
#define BASE_YEAR 1901 
using namespace std;

int main() 
{

// VARIABLES
string fileName,data;
int minYear,maxYear,yearCount;
float X,minTemp,maxTemp,averageTemp,totalTemp;
float temperature[MAX_COUNT];

// FILE INPUT
cout << endl << "Please enter the name of the temperature data file: ";
cin  >> fileName;
cout << setprecision(1) << fixed; 

// OUTPUT CONTENTS
ifstream fin (fileName);
if (fin.is_open() == true)
{
    int i = 0;
    while (getline(fin,data))
    {
        temperature[i] = stof(data); //STRING TO FLOAT 
        cout << temperature[i] << " ";
        i++;
    }
    cout<<fixed;
    fin.close();
}

else
{
cout << "Error opening file" << endl;
}

// BOUNDARY TEMP
cout << endl << endl <<"Please enter the boundary temperature: ";
cin  >> X;

// AVERAGE TEMP
cout << endl << "Climate Data statistics: ";

totalTemp = 0;
for(int i=0; i<MAX_COUNT; i++)
{
totalTemp = totalTemp + temperature[i];
}
averageTemp = totalTemp/MAX_COUNT;
cout << endl << "Average temperature: " << averageTemp;

// # OF YEARS AVERAGE COUNT REACHES X
yearCount = 0;

for(int i=0;i<MAX_COUNT;i++)
{
    if(temperature[i] >= X)
    {
    yearCount = yearCount + 1;
    }
}
cout<<endl<<"Years that averaged at least "<<X<<" degrees: "<<yearCount<<" ";

// SPECIFIC YEARS AVERAGE COUNT REACHES X
for(int i=0;i<MAX_COUNT;i++)
{
    if(temperature[i] >= X)
    {
        cout << BASE_YEAR+i << " ";
    }
}

// MAX TEMP
maxTemp = temperature[0];
for(int i=0;i<MAX_COUNT;i++)
{
    if (temperature[i] > maxTemp)
    {
        maxTemp = temperature[i];
    }
}
cout << endl << "Maximum average temperature: " << maxTemp << " ";

// YEAR MAX TEMP
for(int i=0;i<MAX_COUNT;i++)
{
    if(temperature[i] == maxTemp)
    {
    maxYear = BASE_YEAR+i;
    }
}
cout << "occurred in " << maxYear;


// MIN TEMP
minTemp = temperature[0];
for(int i=0;i<MAX_COUNT;i++)
{
    if (temperature[i] < minTemp)
    {
        minTemp = temperature[i];
    }
}
cout << endl << "Minimum average temperature: " << minTemp << " ";

// YEAR MIN TEMP
for(int i=0;i<MAX_COUNT;i++)
{
    if(temperature[i] == minTemp)
    {
        minYear = BASE_YEAR+i;
    }
}
cout << "occurred in " << minYear;

return 0;
}