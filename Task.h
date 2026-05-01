#ifndef TASK_H
#define TASK_H

#include <string>
using namespace std;

class Task {

public:

    int id;
    string name;
    int priority;
    int deadline;

    Task() {}

    Task(
        int i,
        string n,
        int p,
        int d
    )
    {
        id = i;
        name = n;
        priority = p;
        deadline = d;
    }

};

#endif