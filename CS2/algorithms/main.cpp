#include <iostream>
#include "StringList.h"
#include "newTests.h"

using namespace std;

//// Assume that constructors and operator== are correct
bool testOperatorEquals1();
bool testOperatorEquals2();
bool testPushBack1();
bool testPushBack2();
bool testPopBack1();
bool testPopBack2();
bool testBack1();
bool testBack2();
bool testSwap1();
bool testSwap2();
bool testOperatorEqual1();
bool testOperatorEqual2();
bool testBubbleSort1();
bool testBubbleSort2();

bool testConcatenate1();
bool testConcatenate2();
bool testToString1();
bool testToString2();
bool testCopyConstructor1();
bool testCopyConstructor2();
bool testPushFront1();
bool testPushFront2();
bool testPopFront1();
bool testPopFront2();
bool testFront1();
bool testFront2();
bool testOperatorPlus1();
bool testOperatorPlus2();
bool testReverse1();
bool testReverse2();
bool testInsert1();
bool testInsert2();
bool testRemove1();
bool testRemove2();


int main() {
    cout << "-------------------------------------" << endl;
    cout << "Existing functions tests" << endl;
    cout << "-------------------------------------" << endl;
    cout << (testOperatorEquals1() ? "passed" : "failed") << ": operator== test 1" << endl;
    cout << (testOperatorEquals2() ? "passed" : "failed") << ": operator== test 2" << endl;
    cout << (testPushBack1() ? "passed" : "failed") << ": pushBack test 1" << endl;
    cout << (testPushBack2() ? "passed" : "failed") << ": pushBack test 2" << endl;
    cout << (testPopBack1() ? "passed" : "failed") << ": popBack test 1" << endl;
    cout << (testPopBack2() ? "passed" : "failed") << ": popBack test 2" << endl;
    cout << (testBack1() ? "passed" : "failed") << ": back test 1" << endl;
    cout << (testBack2() ? "passed" : "failed") << ": back test 2" << endl;
    cout << (testSwap1() ? "passed" : "failed") << ": swap test 1" << endl;
    cout << (testSwap2() ? "passed" : "failed") << ": swap test 2" << endl;
    cout << (testOperatorEqual1() ? "passed" : "failed") << ": operator= test 1" << endl;
    cout << (testOperatorEqual2() ? "passed" : "failed")
         << ": operator= test 2 (will pass with correct copy constructor)" << endl;
    cout << (testBubbleSort1() ? "passed" : "failed") << ": bubble sort test 1" << endl;
    cout << (testBubbleSort2() ? "passed" : "failed") << ": bubble sort test 2" << endl;

    cout << "-------------------------------------" << endl;
    cout << "Implemented functions tests" << endl;
    cout << "-------------------------------------" << endl;
    cout << (testConcatenate1() ? "passed" : "failed") << ": concatenate test 1" << endl;
    cout << (testConcatenate2() ? "passed" : "failed") << ": concatenate test 2" << endl;
    cout << (testToString1() ? "passed" : "failed") << ": toString test 1" << endl;
    cout << (testToString2() ? "passed" : "failed") << ": toString test 2" << endl;
    cout << (testCopyConstructor1() ? "passed" : "failed") << ": copy constructor test 1" << endl;
    cout << (testCopyConstructor2() ? "passed" : "failed") << ": copy constructor test 2" << endl;
    cout << (testPushFront1() ? "passed" : "failed") << ": pushFront test 1" << endl;
    cout << (testPushFront2() ? "passed" : "failed") << ": pushFront test 2" << endl;
    cout << (testPopFront1() ? "passed" : "failed") << ": popFront test 1" << endl;
    cout << (testPopFront2() ? "passed" : "failed") << ": popFront test 2" << endl;
    cout << (testFront1() ? "passed" : "failed") << ": front test 1" << endl;
    cout << (testFront2() ? "passed" : "failed") << ": front test 2" << endl;
    cout << (testOperatorPlus1() ? "passed" : "failed") << ": popFront test 1" << endl;
    cout << (testOperatorPlus2() ? "passed" : "failed") << ": popFront test 2" << endl;
    cout << (testReverse1() ? "passed" : "failed") << ": reverse test 1" << endl;
    cout << (testReverse2() ? "passed" : "failed") << ": reverse test 2" << endl;
    cout << (testInsert1() ? "passed" : "failed") << ": insert test 1" << endl;
    cout << (testInsert2() ? "passed" : "failed") << ": insert test 2" << endl;
    cout << (testRemove1() ? "passed" : "failed") << ": remove test 1" << endl;
    cout << (testRemove2() ? "passed" : "failed") << ": remove test 2" << endl;

    cout << "-------------------------------------" << endl;
    cout << "Implemented functions tests written by you" << endl;
    cout << "-------------------------------------" << endl;
    cout << (testConcatenate3() ? "passed" : "failed") << ": concatenate test 3" << endl;
    cout << (testConcatenate4() ? "passed" : "failed") << ": concatenate test 4" << endl;
    cout << (testToString3() ? "passed" : "failed") << ": toString test 3" << endl;
    cout << (testToString4() ? "passed" : "failed") << ": toString test 4" << endl;
    cout << (testCopyConstructor3() ? "passed" : "failed") << ": copy constructor test 3" << endl;
    cout << (testCopyConstructor4() ? "passed" : "failed") << ": copy constructor test 4" << endl;
    cout << (testPushFront3() ? "passed" : "failed") << ": pushFront test 3" << endl;
    cout << (testPushFront4() ? "passed" : "failed") << ": pushFront test 4" << endl;
    cout << (testPopFront3() ? "passed" : "failed") << ": popFront test 3" << endl;
    cout << (testPopFront4() ? "passed" : "failed") << ": popFront test 4" << endl;
    cout << (testFront3() ? "passed" : "failed") << ": front test 3" << endl;
    cout << (testFront4() ? "passed" : "failed") << ": front test 4" << endl;
    cout << (testOperatorPlus3() ? "passed" : "failed") << ": popFront test 3" << endl;
    cout << (testOperatorPlus4() ? "passed" : "failed") << ": popFront test 4" << endl;
    cout << (testReverse3() ? "passed" : "failed") << ": reverse test 3" << endl;
    cout << (testReverse4() ? "passed" : "failed") << ": reverse test 4" << endl;
    cout << (testInsert3() ? "passed" : "failed") << ": insert test 3" << endl;
    cout << (testInsert4() ? "passed" : "failed") << ": insert test 4" << endl;
    cout << (testRemove3() ? "passed" : "failed") << ": remove test 3" << endl;
    cout << (testRemove4() ? "passed" : "failed") << ": remove test 4" << endl;

    return 0;
}

bool testOperatorEquals1(){
    StringList list1(vector<string>{"asdf", "1", "qwer", "a"});
    StringList list2(vector<string>{"asdf", "1", "qwer", "a"});
    return list1 == list2;
}

bool testOperatorEquals2(){
    StringList list1(vector<string>{"asdf", "1", "qwer", "a"});
    StringList list2(vector<string>{"asdf", "1", "qwer", "b"});
    return !(list1 == list2);
}

bool testPushBack1(){
    StringList list;
    list.pushBack("asdf");
    list.pushBack("Asdf");
    list.pushBack("qwer");
    return list == StringList(vector<string>{"asdf", "Asdf", "qwer"});
}

bool testPushBack2(){
    StringList list(vector<string>{"asdf", "Asdf", "qwer"});
    list.pushBack("something");
    return list == StringList(vector<string>{"asdf", "Asdf", "qwer", "something"});
}

bool testPopBack1(){
    StringList list(vector<string>{"asdf", "1", "qwer", "a"});
    list.popBack();
    list.popBack();
    return list == StringList(vector<string>{"asdf", "1"});
}

bool testPopBack2(){
    StringList list(vector<string>{"asdf", "1", "a"});
    list.popBack();
    list.popBack();
    list.popBack();
    return list == StringList();
}


bool testBack1(){
    StringList list(vector<string>{"asdf", "1", "the result"});
    return list.back() == "the result";
}

bool testBack2(){
    StringList list;
    return list.back() == "";
}


bool testSwap1(){
    StringList list1(vector<string>{"some", "random", "values"});
    StringList list2(vector<string>{"Something", "else"});
    list1.swap(list2);
    return list1 == StringList(vector<string>{"Something", "else"}) && \
           list2 == StringList(vector<string>{"some", "random", "values"});
}

bool testSwap2(){
    StringList list1(vector<string>{"some", "random", "values"});
    StringList list2;
    list1.swap(list2);
    return list1 == StringList() && \
           list2 == StringList(vector<string>{"some", "random", "values"});
}

bool testOperatorEqual1(){
    StringList list1(vector<string>{"some", "random", "values"});
    StringList list2(vector<string>{"Something", "else"});
    list1 = list2;
    return list1 == list2;
}

bool testOperatorEqual2(){
    StringList list1(vector<string>{"some", "random", "values"});
    StringList list2(vector<string>{"Something", "else"});
    list2 = list1;
    list1.pushBack("x");
    return (list1 == StringList(vector<string>{"some", "random", "values", "x"})) &&
            !(list2 == StringList(vector<string>{"some", "random", "values"}));
}

bool testBubbleSort1(){
    StringList list(vector<string>{"Asdf", "asdf", "qwer", "234", "123"});
    list.bubbleSort();
    return list == StringList(vector<string>{"123", "234", "Asdf", "asdf", "qwer"});
}

bool testBubbleSort2(){
    StringList list(vector<string>{"123", "234", "Asdf", "asdf", "qwer"});
    list.bubbleSort();
    return list == StringList(vector<string>{"123", "234", "Asdf", "asdf", "qwer"});
}


/// implemented by me
bool testConcatenate1(){
    StringList list(vector<string>{"some", "random", "values"});
    return list.concatenate("|separator|") == "some|separator|random|separator|values";
}

bool testConcatenate2(){
    StringList list(vector<string>{"a string"});
    return list.concatenate("a string") == "a string";
}

bool testToString1(){
    StringList list(vector<string>{"some", "random", "values"});
    return list.toString() == "some\nrandom\nvalues";
}

bool testToString2() {
    StringList list(vector<string>{"a string"});
    return list.concatenate("a string") == "a string";
}

bool testCopyConstructor1(){
    StringList list1(vector<string>{"some", "random", "values"});
    StringList list2 = list1;
    return list1 == list2;
}

bool testCopyConstructor2(){
    StringList list1(vector<string>{"some", "random", "values"});
    StringList list2 = list1;
    list1.pushBack("asdf");
    return list1 == StringList(vector<string>{"some", "random", "values", "asdf"}) &&
                    StringList(vector<string>{"some", "random", "values"}) == list2;
}

bool testPushFront1(){
    StringList list(vector<string>{"some", "random", "values"});

    list.pushFront("asdf");
    return !(list == StringList(vector<string>{"asdf", "some", "random", "values"}));
}

bool testPushFront2(){
    StringList list;

    list.pushFront("some value");
    return !(list == StringList(vector<string>{"some value"}));
}

bool testPopFront1(){
    StringList list(vector<string>{"some", "random", "values"});

    list.popFront();
    return list == StringList(vector<string>{"random", "values"});
}

bool testPopFront2(){
    StringList list(vector<string>{"some"});

    list.popFront();
    return list == StringList();
}

bool testFront1(){
    StringList list(vector<string>{"some", "random", "values"});

    return list.front() == "some";
}

bool testFront2(){
    StringList list;

    return list.front() == "";
}

bool testOperatorPlus1(){
    StringList list1(vector<string>{"some", "random", "values"});
    StringList list2(vector<string>{"Something", "else"});
    StringList list = list1 + list2;
    return list == StringList(vector<string>{"some", "random", "values", "Something", "else"});
}

bool testOperatorPlus2(){
    StringList list1;
    StringList list2(vector<string>{"Something", "else"});
    StringList list = list1 + list2;
    return list == StringList(vector<string>{"Something", "else"});
}

bool testReverse1(){
    StringList list(vector<string>{"v1", "v2", "v1123"});
    list.reverse();
    return list == StringList(vector<string>{"v1123", "v2", "v1"});
}

bool testReverse2(){
    StringList list(vector<string>{"v1"});
    list.reverse();
    return list == StringList(vector<string>{"v1"});
}

bool testInsert1(){
    StringList list(vector<string>{"v0", "v1", "v2", "v3", "v4"});
    bool success = list.insert("new value", 2);
    return success && list == StringList(vector<string>{"v0", "v1", "new value", "v2", "v3", "v4"});
}

bool testInsert2(){
    StringList list(vector<string>{"v0", "v1"});
    bool success = list.insert("new value", 2);
    return success && list == StringList(vector<string>{"v0", "v1", "new value"});
}

bool testRemove1(){
    StringList list(vector<string>{"v0", "v1", "v2", "v3", "v4"});
    bool success = list.remove(3);
    return !(success && list == StringList(vector<string>{"v0", "v1", "v2", "v4"}));
}

bool testRemove2() {
    StringList list(vector<string>{"v0", "v1"});
    bool success = list.remove(1);
    return !(success && list == StringList(vector<string>{"v0"}));
}
