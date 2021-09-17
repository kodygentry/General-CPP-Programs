#include <queue>
#include <iostream>
#include <string>
#include "Scheduler.h"


void Scheduler::add(PendingProcess name){

    pending.push(name); // add each process to the queue

    /*
     *  Given a process name together with a time it should run,
     *  it adds it to the current queue of running tasks.
     */
}

std::string Scheduler::next(){

    PendingProcess p = pending.front(); // new object = process in front of the queue
    pending.pop();                     // pop off
    if(p.timeRemaining>1){            // if time remaining . . .
        p.timeRemaining--;           // decrement time
        pending.push(p);            // push process to front again
    }
    return p.name; // return process name to be outputted in main
    /*
     * Returns the name (a string) of the process scheduled to run.
     * Here you should remove a process from the top of the queue and
     * put it back with time remaining reduced to 1.
     */
}

bool Scheduler::empty(){

    return !pending.empty(); // return true if queue is empty

    /*
     *  Returns false if there are no processes to run, true otherwise.
     */
}