#ifndef TASKSCHEDULER_H
#define TASKSCHEDULER_H

#include <stdio.h>
#include <string.h>
#include "Task.h"

#define MAX_TASKS 100

typedef struct {

    Task tasks[MAX_TASKS];
    int count;

    int graph[MAX_TASKS][MAX_TASKS];

} TaskScheduler;

void addTask(
    TaskScheduler *scheduler,
    int id,
    char name[],
    int priority,
    int deadline
);

void addDependency(
    TaskScheduler *scheduler,
    int task,
    int dependsOn
);

void executeTask(
    TaskScheduler *scheduler
);

void showTasks(
    TaskScheduler *scheduler
);

int detectCycle(
    TaskScheduler *scheduler
);

#endif