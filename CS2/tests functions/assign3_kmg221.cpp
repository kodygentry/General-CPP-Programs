// File Name: assign3_kmg221.cpp
//
// Author: Kody Gentry
// Date: 3/5/2020
// Assignment Number: 3
// CS 2308 Spring 2020
// Instructor: Vladyslav Prokopenko
//
// a program that tests functions

#include <iostream>
using namespace std;

// main test functions
void rightCircularShift(int *testPtr, const int SIZE){

    int temp = *(testPtr+(SIZE-1)); // store value of last element in array
    for(int i=SIZE; i>0; i--){
        *(testPtr+i) = *(testPtr+(i-1)); // swap last element and 2nd to last element
    }                                   // sort of a bubble sort
    *(testPtr) = temp; // assign value of first element to temp (last element)

    /*-----------------------------------------------
     * Takes a pointer to an array of integers
     * and its size
     * then shifts elements to the right once
    *///---------------------------------------------
}
int sort2withSum(int *x, int *y){

    if (*x > *y){
        int temp = *x;
        *x = *y;
        *y = temp;
    }
    return *x+*y;


    /*-----------------------------------------------
     * takes in two values
     * bubble sorts them if not in order
     * returns the sum of values
    *///---------------------------------------------


}
int *resize(const int test[], const int SIZE){

    int newTest[SIZE*2]; // new array, twice the size of argument array
    int *newPtr;        // make a new pointer for new array (for returning)

    for(int i=0; i<(SIZE); i++){ // copies elements from original array to new array
        newTest[i] = test[i];   // in the first half
    }
    for(int i=SIZE; i<(SIZE*2); i++){ // fills the second half of the array with -1
        newTest[i] = -1;
    }

    newPtr = &newTest[0];  // assigns address to newPtr
    *newPtr = newTest[0]; // assigns value to newPtr

    return newPtr; // returns pointer to new array

    /*-----------------------------------------------
     * takes an int array and size as arguments
     * creates a new array that is twice the size
     * copies the contents of the argument array to new
     * initialize unused elements w/ -1
     * return ptr to new array
    *///---------------------------------------------
}
int *concatenate(const int test[], const int test2[], int SIZE, int SIZE2){

    int newSIZE = (SIZE+SIZE2);  // initializes new size to the sum of both argument sizes
    int newTest[newSIZE];       // new array with new size
    for(int i=0; i<SIZE; i++){ // copies first array up to its size into new array
        newTest[i] = test[i];
    }
    for(int i=0; i<SIZE2; i++){ // copies second array from the first size until the second size
        newTest[i+SIZE] = test2[i];
    }

    int *newPtr;            // new array pointer
    newPtr = &newTest[0];  // assign pointer to address
    *newPtr = newTest[0]; // first element value to pointer
    return newPtr;       // return address of new array

    /*-----------------------------------------------
     * takes two int arrays and their sizes
     * creates a new array to store both
     * copies contents of both arrays
     * return pointer of new array
    *///---------------------------------------------

}
int *duplicateArray(int *test, const int SIZE){

    int *newArray;
    if (SIZE<=0) {
        return NULL; // size must be positive
    }
    newArray = new int [SIZE]; // new array
    for (int index=0; index<SIZE; index++){
        newArray[index] = test[index]; // copy test array to new array;
    }
    return newArray; // return pointer

    // takes in pointer of array and its size
    // creates a new array dynamically
    // copies argument array into new array
    // returns pointer to new array

}
int *subArray(int test[], int start, int length){

    int *result = duplicateArray(test+start, length); // passes start+test and length
    return result; // return pointer

    /*-----------------------------------------------
     * takes int array, start index, length
     * creates a new array that is a copy of
     * the elements from the original array
     * starting at starting index
     * length of array equal to length
     * return pointer
    *///---------------------------------------------
}

// other functions
void undoShift(int *testPtr, const int SIZE){
    int temp = *(testPtr); // stores first element of array
    for(int i=0; i<SIZE; i++){
        *(testPtr+i) = *(testPtr+(i+1)); // swaps first and 2nd element
    }                                   // sort of a bubble sort
    *(testPtr+(SIZE-1)) = temp; // makes last element = temp (first element)

    // takes in a pointer to array and its size
    // undo right circular shift on the main array
    // by shift array to the left
}
void displayHeader(int order){

    // possible functions being tested
    string funcTitles[6] = {"Test Values","Right Circular Shift",
                            "Sort 2 With Sum","Resize",
                            "Concatenate","Sub Array"};
    // test separator and outputs function being tested
    cout << "\n----------------------------------------------------------------\n"
         << "--> " << funcTitles[order] << ":\n";

    // displays what function is being tested

}
void printArray(int *array, int size){

    for(int i=0; i<size; i++){ // loops through each element in order and outputs it
        cout << *(array+i) << " ";
    }

    // takes in a pointer to an array and its size
    // outputs array elements
}

int main(){

    // test arrays size values
    const int SIZE = 10;
    const int SIZE2 = 4;

    // main test array
    // used for rightCircularShift(),resize(),concatenate(),subArray()
    int test[SIZE] = {1,2,3,4,5,6,7,8,9,0};

    // secondary test array
    // used for concatenate()
    int test2[SIZE2] = {11,22,33,44};


    // establish test array pointer
    int *testPtr;
    testPtr = &test[0];  // address
    *testPtr = test[0]; // value

    // established test2 array pointer
    int *testPtr2;
    testPtr2 = &test2[0];
    *testPtr2 = test2[0];


    //=============================================
    //-------------RIGHT CIRCULAR SHIFT------------
    //=============================================
    displayHeader(1); // displays function that's being tested

    cout  << "Test Data: "; // displays elements in test array
    printArray(testPtr, SIZE);

    cout  << "\nExpected Result: 0 1 2 3 4 5 6 7 8 9\n" // hardcoded expectation of output
          << "Actual Result:   ";

    rightCircularShift(testPtr, SIZE); // shifts array right once
    printArray(testPtr, SIZE);           // prints array
    undoShift(testPtr, SIZE);        // shifts array left once
    // to revert back to normal

    //=============================================
    //--------------SORT 2 WITH SUM----------------
    //=============================================
    displayHeader(2);

    int a = 15, // sort2withSum input test values
        b = 10;

    int *aPtr, *bPtr;      // pointers for input test values
    aPtr = &a, bPtr = &b; // point to address of values


    cout << "Test Data: a: " << a << " b: " << b; // displays test inputs
    cout << "\nExpected Result: 25 a: 10 b: 15"; // hardcoded expectation of output

    int sum = sort2withSum(aPtr, bPtr); // initializes sum and sorts argument values
    cout << "\nActual Result:" << "   " << sum
         << " a: " << a << " b: " << b;

    //=============================================
    //------------------RESIZE---------------------
    //=============================================
    displayHeader(3);

    cout << "Test Data: ";  // displays elements in test array
    printArray(testPtr, SIZE);

    cout << "\nExpected: " // hardcoded expectation of output
         << "1 2 3 4 5 6 7 8 9 0 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1\n"
         << "Actual:   ";

    for (int j=0; j<(SIZE*2); j++) {  // displays entire new array
        cout << *(resize(test, SIZE)+j) << " ";
    }

    //=============================================
    //----------------CONCATENATE------------------
    //=============================================
    displayHeader(4);

    cout << "Test Data: ";
    printArray(testPtr, SIZE);    // displays test array
    cout << "\n   and     ";
    printArray(testPtr2, SIZE2); // displays test2 array

    cout << "\nExpected: 1 2 3 4 5 6 7 8 9 0 11 22 33 44\n"
         << "Actual:   ";

    for(int i=0; i<(SIZE+SIZE2); i++){ // displays entire new array
        cout << *(concatenate(test, test2, SIZE, SIZE2)+i) << " ";
    }

    //=============================================
    //-----------------SUB ARRAY-------------------
    //=============================================
    displayHeader(5);

    // test inputs for subArray
    int start  = 4,
        length = 5;

    cout << "Test Data: ";
    printArray(testPtr, SIZE); // displays test array
    cout << "\nStart: " << start << " " << "Length: " << length;

    cout << "\nExpected Result: 5 6 7 8 9\n"
         << "Actual Result:   ";

    int *subArr = subArray(test, start, length); // assign pointer to result of dupArr

    printArray(subArr, length); // prints fixed array with size=length
    cout << endl;

    delete[] subArray(test, start, length); // deletes dynamically allocated array
    // made in sub func

    //==============================================
    //==============================================

    return 0;
}