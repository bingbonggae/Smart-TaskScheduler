#include "TaskScheduler.h"

int main()
{
    TaskScheduler scheduler;

    int choice;

    while (true) {

        cout << "\n===== TASK SCHEDULER =====\n";

        cout << "1. Add Task\n";
        cout << "2. Add Dependency\n";
        cout << "3. Execute Task\n";
        cout << "4. Show Tasks\n";
        cout << "5. Detect Cycle\n";
        cout << "6. Exit\n";

        cout << "Enter choice: ";

        cin >> choice;

        if (choice == 1) {

            int id;
            int priority;
            int deadline;
            string name;

            cout << "Enter ID: ";
            cin >> id;

            cout << "Enter Name: ";
            cin >> name;

            cout << "Enter Priority: ";
            cin >> priority;

            cout << "Enter Deadline: ";
            cin >> deadline;

            scheduler.addTask(
                id,
                name,
                priority,
                deadline
            );

        }

        else if (choice == 2) {

            int task;
            int dependsOn;

            cout << "Task ID: ";
            cin >> task;

            cout << "Depends On Task ID: ";
            cin >> dependsOn;

            scheduler.addDependency(
                task,
                dependsOn
            );

        }

        else if (choice == 3) {

            scheduler.executeTask();

        }

        else if (choice == 4) {

            scheduler.showTasks();

        }

        else if (choice == 5) {

            if (scheduler.detectCycle())

                cout
                << "Cycle Detected\n";

            else

                cout
                << "No Cycle\n";

        }

        else if (choice == 6) {

            cout << "Exiting...\n";
            break;

        }

        else {

            cout
            << "Invalid Choice\n";

        }

    }

    return 0;
}