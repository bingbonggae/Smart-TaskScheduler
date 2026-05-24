#include "TaskScheduler.h"

int main()
{
    TaskScheduler scheduler;

    scheduler.count = 0;

    int choice;

    while (1) {

        printf("\n===== TASK SCHEDULER =====\n");

        printf("1. Add Task\n");
        printf("2. Add Dependency\n");
        printf("3. Execute Task\n");
        printf("4. Show Tasks\n");
        printf("5. Detect Cycle\n");
        printf("6. Exit\n");

        printf("Enter choice: ");

        scanf("%d", &choice);

        if (choice == 1) {

            int id;
            int priority;
            int deadline;
            char name[50];

            printf("Enter ID: ");
            scanf("%d", &id);

            printf("Enter Name: ");
            scanf("%s", name);

            printf("Enter Priority: ");
            scanf("%d", &priority);

            printf("Enter Deadline: ");
            scanf("%d", &deadline);

            addTask(
                &scheduler,
                id,
                name,
                priority,
                deadline
            );

        }

        else if (choice == 2) {

            int task;
            int dependsOn;

            printf("Task ID: ");
            scanf("%d", &task);

            printf("Depends On Task ID: ");
            scanf("%d", &dependsOn);

            addDependency(
                &scheduler,
                task,
                dependsOn
            );

        }

        else if (choice == 3) {

            executeTask(&scheduler);

        }

        else if (choice == 4) {

            showTasks(&scheduler);

        }

        else if (choice == 5) {

            if (detectCycle(&scheduler))

                printf("Cycle Detected\n");

            else

                printf("No Cycle\n");

        }

        else if (choice == 6) {

            printf("Exiting...\n");
            break;

        }

        else {

            printf("Invalid Choice\n");

        }
    }

    return 0;
}