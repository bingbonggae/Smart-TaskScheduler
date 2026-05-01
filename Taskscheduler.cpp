#include "TaskScheduler.h"
#include <functional>

void TaskScheduler::addTask(
    int id,
    string name,
    int priority,
    int deadline
)
{
    Task t(
        id,
        name,
        priority,
        deadline
    );

    pq.push(t);

    cout << "Task Added Successfully\n";
}

void TaskScheduler::addDependency(
    int task,
    int dependsOn
)
{
    graph[dependsOn].push_back(task);

    cout << "Dependency Added\n";
}

void TaskScheduler::executeTask()
{
    if (pq.empty()) {

        cout << "No Tasks Available\n";
        return;

    }

    Task t = pq.top();

    pq.pop();

    cout
        << "Executing Task: "
        << t.name
        << " (Priority: "
        << t.priority
        << ")"
        << endl;
}

void TaskScheduler::showTasks()
{
    if (pq.empty()) {

        cout << "No Tasks Found\n";
        return;

    }

    priority_queue<
        Task,
        vector<Task>,
        Compare
    > temp = pq;

    cout << "\nTasks in Queue:\n";

    while (!temp.empty()) {

        Task t = temp.top();

        cout
            << "ID: "
            << t.id
            << " Name: "
            << t.name
            << " Priority: "
            << t.priority
            << " Deadline: "
            << t.deadline
            << endl;

        temp.pop();

    }
}

bool TaskScheduler::detectCycle()
{
    unordered_map<int, bool> visited;
    unordered_map<int, bool> recStack;

    function<bool(int)> dfs =
    [&](int node)
    {
        visited[node] = true;
        recStack[node] = true;

        for (int neighbor : graph[node]) {

            if (!visited[neighbor]
                && dfs(neighbor))
                return true;

            else if (recStack[neighbor])
                return true;

        }

        recStack[node] = false;

        return false;
    };

    for (auto pair : graph) {

        int node = pair.first;

        if (!visited[node]) {

            if (dfs(node))
                return true;

        }

    }

    return false;
}