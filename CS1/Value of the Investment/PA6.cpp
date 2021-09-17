// File Name: assign6_kmg221.cpp
//
// Author: Kody Gentry
// Date: 11/11/2019
// Assignment Number: 6
// CS 1428.003 Fall 2019
// Instructor: Jill Seaman
//
// a program that asks the user for an initial investment amount, the interest rate
//(compounded annually), and the number of years to let the investment grow.
//Then calculate and output the final accumulated value of the investment, based on the
//input values.

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double getInput();
double calculateFV();
int yearsToDouble();
int yearsToOneMillion();
int outputTable();

int main()
{
    getInput();
    cout << "Future value of investment: " << calculateFV() << endl << endl;
    outputTable();
    cout << "Investment will double in " << yearsToDouble() << " years" << endl;
    cout << "One million dollar year: " << yearsToOneMillion() << endl;
}

int outputTable()
{
    int invest, years;
    double intrest;

    for (int i=1; i<=years; i++)
    {
        cout << i << setw(21);
        cout << (intrest/100)*invest*i << endl;
    }
    cout << endl;
    //has 3 parameters: initial investment (present value), interest rate, and
    //total years. It outputs the table with column headers, and one row for each year from
    //0 to total years, showing the balance at the end of that year.
}

double calculateFV()
{
    int invest, years;
    double intrest;

    double futureValue = invest*pow(1+(intrest/100),years);

    return futureValue;
    //has 3 parameters: present value, interest rate, and years of investment.
    //Returns the calculated future value. Do not do any output from this function.
}

int yearsToDouble()
{
    int years, timesTwo;
    double intrest;
    int estimateYears = .727/intrest;

    return estimateYears;
    //has 1 parameter: the interest rate. Returns the estimated number of
    //years it will take for a balance to double. Do not do any output from this function.
}

int yearsToOneMillion()
{
    int invest;
    double intrest;
    int millionYears = (log(1000000) - log (invest)) / log(1 + intrest);



    return millionYears;
    //has 2 parameters, the initial value and the interest rate. Returns the
    //calculated number of years it takes for the balance to reach one million. Do not do any
    //output from this function.
}

double getInput()
{
    int invest, years;
    double intrest;

    cout << "Enter your initial investment amount: ";
    cin  >> invest;
    cout << "Enter the annual interest rate: ";
    cin  >> intrest;
    cout << "Enter the number of years of the investment: ";
    cin  >> years;
    cout << endl;


    if (invest<100||invest>1000000)
    {
        cout << "Re-enter your initial investment amount: ";
        cin  >> invest;
    }

    if (intrest<0||intrest>50)
    {
        cout << "Re-enter the annual interest rate: ";
        cin  >> intrest;
    }

    if (years<0||years>80)
    {
        cout << "Re-enter the number of years of the investment: ";
        cin  >> intrest;
    }

    return invest, intrest, years;
    //has three reference parameters to input initial investment value, interest rate,
    //and number of years from the user.
}