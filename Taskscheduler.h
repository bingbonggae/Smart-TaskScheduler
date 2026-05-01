#ifndef TASKSCHEDULER_H
#define TASKSCHEDULER_H

#include <vector>
#include <queue>
#include <unordered_map>
#include <stack>
#include <iostream>
#include "Task.h"

using namespace std;

class TaskScheduler {

private:

    struct Compare {

        bool operator()(Task a, Task b) {

            return a.priority < b.priority;

        }

    };

    priority_queue<Task, vector<Task>, Compare> pq;

    unordered_map<int, vector<int>> graph;

public:

    void addTask(
        int id,
        string name,
        int priority,
        int deadline
    );

    void addDependency(
        int task,
        int dependsOn
    );

    void executeTask();

    void showTasks();

    bool detectCycle();

};

#endif