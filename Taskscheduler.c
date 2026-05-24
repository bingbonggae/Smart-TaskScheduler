#include "TaskScheduler.h"

void addTask(
    TaskScheduler *scheduler,
    int id,
    char name[],
    int priority,
    int deadline
)
{
    Task t;

    t.id = id;
    strcpy(t.name, name);
    t.priority = priority;
    t.deadline = deadline;

    scheduler->tasks[scheduler->count] = t;

    scheduler->count++;

    printf("Task Added Successfully\n");
}

void addDependency(
    TaskScheduler *scheduler,
    int task,
    int dependsOn
)
{
    scheduler->graph[dependsOn][task] = 1;

    printf("Dependency Added\n");
}

void executeTask(
    TaskScheduler *scheduler
)
{
    if (scheduler->count == 0) {

        printf("No Tasks Available\n");
        return;

    }

    int highest = 0;

    for (int i = 1; i < scheduler->count; i++) {

        if (scheduler->tasks[i].priority >
            scheduler->tasks[highest].priority) {

            highest = i;

        }
    }

    Task t = scheduler->tasks[highest];

    printf(
        "Executing Task: %s (Priority: %d)\n",
        t.name,
        t.priority
    );

    for (int i = highest; i < scheduler->count - 1; i++) {

        scheduler->tasks[i] =
            scheduler->tasks[i + 1];

    }

    scheduler->count--;
}

void showTasks(
    TaskScheduler *scheduler
)
{
    if (scheduler->count == 0) {

        printf("No Tasks Found\n");
        return;

    }

    printf("\nTasks in Queue:\n");

    for (int i = 0; i < scheduler->count; i++) {

        Task t = scheduler->tasks[i];

        printf(
            "ID: %d Name: %s Priority: %d Deadline: %d\n",
            t.id,
            t.name,
            t.priority,
            t.deadline
        );
    }
}

int detectCycle(
    TaskScheduler *scheduler
)
{
    return 0;
}