#include <algorithm>
#include <string>
using namespace std;
#include "StringList.h"

StringList::StringList(): head(nullptr) {}

StringList::StringList(const vector<string>& stringVector) {
    if (stringVector.empty())
        this->head = nullptr;
    else{
        this->head = new StringNode(stringVector[0]);
        StringNode* node = this->head;
        for(int i = 1; i < stringVector.size(); ++i){
            node->next = new StringNode(stringVector[i]);
            node = node->next;
        }
    }

}

void StringList::swapNodes(StringNode *&previousNext, StringNode* node1, StringNode* node2) {
    node1->next = node2->next;
    node2->next = node1;
    previousNext = node2;
}

void StringList::bubbleSort(){
    if (this->head == nullptr || this->head->next == nullptr)
        return;

    bool swapped;
    do{
        swapped = false;
        StringNode* prevNode = this->head;
        StringNode* currNode = this->head;

        // Handle case when we want to change the first node
        if (currNode->data > currNode->next->data){
            StringList::swapNodes(this->head, currNode, currNode->next);
            swapped = true;
        }
        currNode = currNode->next;

        // Standard bubble sort, iterate until the end of list is reached, swap if out of order
        while(currNode->next != nullptr){
            if (currNode->data > currNode->next->data){
                // swap nodes
                StringList::swapNodes(prevNode->next, currNode, currNode->next);
                swapped = true;

                // because we have swapped currNode with the next one
                // so we don't need to update it like this currNode = currNode->next;
                prevNode = prevNode->next;
            }
            else{
                prevNode = prevNode->next;
                currNode = currNode->next;
            }
        }
    }while(swapped);
}

bool StringList::operator==(const StringList& other){
    bool equal = true;
    StringNode* thisNode = this->head;
    StringNode* otherNode = other.head;

    while(thisNode != nullptr && otherNode != nullptr){
        if (thisNode->data != otherNode->data){
            equal = false;
            break;
        }
        thisNode = thisNode->next;
        otherNode = otherNode->next;
    }
    if (thisNode != nullptr || otherNode != nullptr)
        equal = false;
    return equal;
}

void StringList::pushBack(string s){
    auto newNode = new StringNode(s);

    if (this->head == nullptr){
        this->head = newNode;
    }
    else{
        StringNode* node = this->head;
        while (node->next != nullptr)
            node = node->next;
        node->next = newNode;
    }
}

void StringList::popBack(){
    if (this->head == nullptr) {
        // do nothing
    }
    else if (this->head->next == nullptr){
        delete this->head;
        this->head = nullptr;
    }
    else {
        StringNode* node = this->head;
        while (node->next->next != nullptr)
            node = node->next;
        delete node->next;
        node->next = nullptr;
    }
}

string StringList::back(){
    string result;

    if (this->head != nullptr){
        StringNode* node = this->head;
        for(; node->next != nullptr; node = node->next) {}
        result = node->data;
    }
    return result;
}


void StringList::swap(StringList& other) {
    std::swap(this->head, other.head);
}

StringList& StringList::operator=(StringList other) {
    this->swap(other);
    return *this;
}


/// implemented by me

StringList::StringList(const StringList &other)
{
    if(other.head == nullptr)
    {
        head = nullptr;
    }
    else
    {
        head = new StringNode(other.head->data);
        StringNode* nodePointer = head;
        StringNode* otherNodePointer = other.head;
        StringNode* currentNode = other.head;

        while (currentNode->next != nullptr)
        {
            nodePointer->next = new StringNode(currentNode->next->data);
            currentNode = currentNode->next;
            nodePointer = nodePointer->next;
        }
    }
}

StringList::~StringList(){
    StringNode* current = head;
    StringNode* next;

    while(current != nullptr){
        next = current->next;
        free(current);
        current = next;
    }

    head = nullptr;
}

string StringList::concatenate(const std::string& separator){

    string concatenate = "";

    StringNode* thisNode = this->head;

    for(;thisNode->next != nullptr; thisNode = thisNode->next){
        concatenate = concatenate + (thisNode->data) + separator;
    }
    concatenate = concatenate + (thisNode->data);
    return concatenate;

}

string StringList::toString(){
    string concatenate = "";
    string separator = "\n";
    StringNode* thisNode = this->head;

    for(;thisNode->next != nullptr; thisNode = thisNode->next){
        concatenate = concatenate + (thisNode->data) + separator;
    }
    concatenate = concatenate + (thisNode->data);
    return concatenate;
}

void StringList::pushFront(std::string s){
    StringNode* newString = new StringNode(s);
    StringNode* current = head;
    if (head != nullptr){
        head = newString;
        newString->next = current;
    }
    else if(head == nullptr){
        head = newString;
        newString->next = nullptr;
    }
}

void StringList::popFront()
{
    StringNode* temp = head;
    head = head->next;

    delete temp;
}

string StringList::front()
{
    string first;

    if(this->head == nullptr)
    {
        //nothing
    }
    else
    {
        StringNode* premier = head;
        first = premier->data;
    }

    return first;
}

StringList StringList::operator+(const StringList& other){
    StringNode* newHead;
    StringNode* thisNode = this->head;
    StringNode* otherNode = other.head;
    if(thisNode == nullptr && otherNode == nullptr){
        newHead = nullptr;
    }
    else if (thisNode == nullptr){
        newHead = new StringNode(otherNode->data);
        otherNode = otherNode->next;
    }
    else if (otherNode == nullptr){
        newHead = new StringNode(thisNode->data);
        thisNode = thisNode->next;
        otherNode = otherNode;
    }
    StringNode* newNode = newHead;

    while(thisNode != nullptr) {
        newNode->next = new StringNode(thisNode->data);
        newNode = newNode->next;
        thisNode = thisNode->next;
    }
    while(otherNode != nullptr){
        newNode->next = new StringNode(otherNode->data);
        newNode = newNode->next;
        otherNode = otherNode->next;

    }
}

void StringList::reverse()
{
    StringNode* current = head;
    StringNode* previous = nullptr;
    StringNode* next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        current->next = previous;

        previous = current;
        current = next;
    }

    head = previous;
}

bool StringList::insert(std::string s, int position)
{
    StringNode* previousNode;
    StringNode* newNode = new StringNode(s);

    if (previousNode == nullptr)
    {
        return false;
    }

    newNode->data = position;
    newNode->next = previousNode->next;
    previousNode->next = newNode;

    return true;
}

bool StringList::remove(int position){
    int count = 0;

    StringNode* current = head;
    while(current!=NULL){
        if(count==position){
            count++;
            current=current->next;
            delete current;
            return true;
        } else {
            return false;
        }
    }
}
