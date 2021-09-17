// File Name: assign3_kmg221.cpp
//
// Author: Kody Gentry
// Date: 10/1/2019
// Assignment Number: 3
// CS 1428.003 Fall 2019
// Instructor: Jill Seaman
//
// program that calculates amount due per month


#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    
    //-------------------------------------------------------------------------
    // USER: CHOOSE LINE (user chooses A or B to determine monthlyRate)
    //-------------------------------------------------------------------------
    
    char lineChoice;
    cout << "How many lines: \n"
         << "A. One Line\n"
         << "B. Two Lines\n";
    cin  >> lineChoice;
    cout << endl;
    
    //-------------------------------------------------------------------------
    // DETERMINING monthlyRate
    //-------------------------------------------------------------------------
    
    int monthlyRate;
    switch (lineChoice)
    {
         case 'A':
         case 'a':
             monthlyRate=6;
             break;
         case 'B':
         case 'b':
             monthlyRate=12;
             break;
         default:
             cout << "Please enter A, or B: ";
             cin  >> lineChoice;
    }
    
    //-------------------------------------------------------------------------
    // USER: HOW MANY MINUTES (user inputs minutes to determine voiceRate)
    //-------------------------------------------------------------------------
    
    int minutes;
    cout << "Enter the total number of minutes used during the month: \n";
    cin  >> minutes;
    cout << endl;
    
    //-------------------------------------------------------------------------
    // DETERMINING voiceRate 
    //-------------------------------------------------------------------------
    
    double voiceRate;
    if (minutes>=44641) {cout << "Please enter a number between 0 "
                                    "and 44640 for the minutes: ";
        cin  >> minutes;
        cout << endl;}
    if (minutes==0) voiceRate=0;
    else if (minutes>=1&&minutes<=400) voiceRate=9;
    else if (minutes>=401&&minutes<=800) voiceRate=16;
    else if (minutes>=801&&minutes<=44640) voiceRate=((minutes-800)*1.9)+16;
    
    //-------------------------------------------------------------------------
    // USER: CHOOSE UNLIMITED Y/N (user chooses Y/N to determine unlimitedText)
    //-------------------------------------------------------------------------
    
    char unlimitedChoice;
    cout << "Unlimited text messages? (Y/N): ";
    cin  >> unlimitedChoice;
    cout << endl;
    
    //-------------------------------------------------------------------------
    // DETERMINING unlimitedText
    //-------------------------------------------------------------------------
    
    int unlimitedText;
    switch (unlimitedChoice)
    {
        case 'Y':
        case 'y':
            unlimitedText=5;
            break;
        case 'N':
        case 'n':
            unlimitedText=0;
            break;
        default:
            cout << "Please enter Y, or N: ";
            cin  >> unlimitedChoice;
            cout << endl;
    }
    
    //-------------------------------------------------------------------------
    // AMOUNT DUE (add all variables together)
    //-------------------------------------------------------------------------
    
    double amountDue;
    amountDue= monthlyRate+voiceRate+unlimitedText;
    cout << "The amount due for the month is $"
         << setprecision(2) << fixed << amountDue
         << endl;
}