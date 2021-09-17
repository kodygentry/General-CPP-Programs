#ifndef PA6_PENDINGPROCESS_H
#define PA6_PENDINGPROCESS_H

#include <string>

struct PendingProcess {
    std::string name;
    int timeRemaining;
    PendingProcess(std::string name, int timeRemaining):
    name(name),timeRemaining(timeRemaining){}
};
#endif //PA6_PENDINGPROCESS_H
