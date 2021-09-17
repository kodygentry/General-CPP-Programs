// File Name: assign6_kmg221.cpp
// Author: Kody Gentry
// Date: 04/29/2020
// Assignment #: 6
// CS 2308.252 Spring 2020
// Instructor: Vladyslav Prokopenko
// C++ Program to  implement a simple scheduler that gives
// each running process equal share of the CPU and minimizes
// the distance between two moments of time when the same process is run.


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
#include "Scheduler.h"


vector<PendingProcess> readPendingProcessList(ifstream &in){
    vector<PendingProcess>processList; // create a vector of processes
    string name, line, numStr;        // string variables
    int time;

    while(getline(in, line)){
        stringstream s(line);
        getline(s,name,','); // fetch name
        getline(s, numStr);       // fetch time
        stringstream num(numStr);       // new string stream object that stores time as a string
        num>>time;                     // converts time string into int
        PendingProcess process(name,time); // creates new process
        processList.push_back(process);   // adds process to vector
    }
    return processList; // return vector of processes

    /*
     * Given an input ﬁle handle it pending processes stored in this ﬁle
     * and puts them to the vector.
     * It should return a vector of pending processes.
     * See Programming Assignment #4 for an example of how to implement such function.
     */
}

int main() {

    int seconds = 0; // process time variable

    // create file output variable
    ifstream in("pendingProcessList.csv");

    // copy vector from function to local vector
    vector<PendingProcess> pendingProcess = readPendingProcessList(in);

    // create Scheduler object
    Scheduler s;

    // add each process to Scheduler queue
    for (PendingProcess& name : pendingProcess) {
        s.add(name);
    }
    // while queue isn't empty, output contents of s.next
    while(s.empty()){
        cout << "Second " << seconds << ": " << s.next() << endl;
        seconds ++;
    }
    return 0;
}
