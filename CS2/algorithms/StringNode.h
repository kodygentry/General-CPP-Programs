#ifndef ASSIGNMENT5_SOLUTION_STRINGNODE_H
#define ASSIGNMENT5_SOLUTION_STRINGNODE_H


#include <string>

struct StringNode {
    std::string data;
    StringNode* next;
    StringNode(std::string data): data(std::move(data)), next(nullptr) {}
};


#endif //ASSIGNMENT5_SOLUTION_STRINGNODE_H
