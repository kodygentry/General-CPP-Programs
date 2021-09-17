// File Name: assign6_kmg221.cpp
// Author: Kody Gentry
// Date: 04/29/2020
// Assignment #: 6
// CS 2308.252 Spring 2020
// Instructor: Vladyslav Prokopenko
// C++ Program to check for balanced parentheses in an expression using stack.


#include<iostream>
#include<stack>
#include<string>

using namespace std;

bool checkValidity(string input) {
    stack<int> myStack; // new stack
    bool valid = true; // return value

    for (int i = 0; i < input.length(); ++i) {
        if (input[i] == '(' || input[i] == '[' || input[i] == '{') {
            myStack.push(i); // push brace to top of stack
        }
        else if (input[i] == ')' || input[i] == ']' || input[i] == '}') {
            // check if stack is empty
            if (myStack.empty()) {
                valid = false;
                break;
            }
            char top = (input[myStack.top()]);
            if ((input[i] == ')' && top == '(') || (input[i] == ']' && top == '[') || (input[i] == '}' && top == '{')) {
                int length = (i-1) - myStack.top(); // stores the length of the sequence
                cout << input.substr(myStack.top() + 1, length) << endl; // output from first bracket to matching bracket
                myStack.pop(); // pops off substring expression
            }
            else {
                valid = false;
                cout <<"Invalid Expression\n";
                break;
            }
        }
    }
    cout << input; // output original input sequence
    return valid;
    /*
     * function that - given an input - checks if valid
     * then separates each expression by priority
     */
}

int main() {

    // create a stack of chars
    stack<char> myStack;

    // get user input
    string input;
    cout << "Input Expression: \n";
    cin  >> input;

    // converting string into array of chars
    string s(input);

    if(!checkValidity(input))
        cout <<"Invalid Expression\n";

    return 0;
}