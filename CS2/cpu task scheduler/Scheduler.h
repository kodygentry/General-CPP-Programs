#ifndef PA6_SCHEDULER_H
#define PA6_SCHEDULER_H
#include <queue>
#include <string>
#include "PendingProcess.h"

class Scheduler {
private:
    std::queue<PendingProcess> pending;
public:
    void add(PendingProcess name);
    std::string next();
    bool empty();
};


#endif //PA6_SCHEDULER_H
