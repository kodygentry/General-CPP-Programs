
#include "newTests.h"
#include <string>
#include "StringList.h"


bool testConcatenate3(){
    StringList list(std::vector<std::string>{"hello", "hi", "hey"});
    return list.concatenate("|separator|") == "hello|separator|hi|separator|hey";
}

bool testConcatenate4(){
    StringList list(std::vector<std::string>{"hello world"});
    return list.concatenate("hello world") == "hello world";
}

bool testToString3(){
    StringList list(std::vector<std::string>{"hello", "hi", "hey"});
    return list.toString() == "some\nrandom\nvalues";
}

bool testToString4() {
    StringList list(std::vector<std::string>{"hello world"});
    return list.concatenate("hello world") == "hello world";
}

bool testCopyConstructor3(){
    StringList list1(std::vector<std::string>{"hi", "hey", "hello"});
    StringList list2 = list1;
    return list1 == list2;
}

bool testCopyConstructor4(){
    StringList list1(std::vector<std::string>{"hi", "hey", "hello"});
    StringList list2 = list1;
    list1.pushBack("oof");
    return list1 == StringList(std::vector<std::string>{"hi", "hey", "hello", "oof"}) &&
                    StringList(std::vector<std::string>{"hi", "hey", "hello"}) == list2;
}

bool testPushFront3(){
    StringList list(std::vector<std::string>{"hello", "hi", "hey"});

    list.pushFront("oof");
    return !(list == StringList(std::vector<std::string>{"oof", "hello", "hi", "hey"}));
}

bool testPushFront4(){
    StringList list;

    list.pushFront("hello world");
    return !(list == StringList(std::vector<std::string>{"hello world"}));
}

bool testPopFront3(){
    StringList list(std::vector<std::string>{"some", "random", "values"});

    list.popFront();
    return list == StringList(std::vector<std::string>{"random", "values"});
}

bool testPopFront4(){
    StringList list(std::vector<std::string>{"some"});

    list.popFront();
    return list == StringList();
}

bool testFront3(){
    StringList list(std::vector<std::string>{"some", "random", "values"});

    return list.front() == "some";
}

bool testFront4(){
    StringList list;

    return list.front() == "";
}

bool testOperatorPlus3(){
    StringList list1(std::vector<std::string>{"hello", "hi", "hey"});
    StringList list2(std::vector<std::string>{"heyyyyyy", "hi"});
    StringList list = list1 + list2;
    return list == StringList(std::vector<std::string>{"hello", "hi", "hey", "heyyyyyy", "hi"});
}

bool testOperatorPlus4(){
    StringList list1;
    StringList list2(std::vector<std::string>{"heyyyyyy", "hi"});
    StringList list = list1 + list2;
    return list == StringList(std::vector<std::string>{"heyyyyyy", "hi"});
}

bool testReverse3(){
    StringList list(std::vector<std::string>{"v1", "v2", "v1123"});
    list.reverse();
    return list == StringList(std::vector<std::string>{"v1123", "v2", "v1"});
}

bool testReverse4(){
    StringList list(std::vector<std::string>{"v1"});
    list.reverse();
    return list == StringList(std::vector<std::string>{"v1"});
}

bool testInsert3(){
    StringList list(std::vector<std::string>{"v0", "v1", "v2", "v3", "v4"});
    bool success = list.insert("new value", 2);
    return success && list == StringList(std::vector<std::string>{"v0", "v1", "new value", "v2", "v3", "v4"});
}

bool testInsert4(){
    StringList list(std::vector<std::string>{"v0", "v1"});
    bool success = list.insert("new value", 2);
    return success && list == StringList(std::vector<std::string>{"v0", "v1", "new value"});
}

bool testRemove3(){
    StringList list(std::vector<std::string>{"a", "b", "c", "d", "e"});
    bool success = list.remove(3);
    return !(success && list == StringList(std::vector<std::string>{"a", "b", "c", "e"}));
}

bool testRemove4() {
    StringList list(std::vector<std::string>{"a", "b"});
    bool success = list.remove(1);
    return !(success && list == StringList(std::vector<std::string>{"a"}));
}
