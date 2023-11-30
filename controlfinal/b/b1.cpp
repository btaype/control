#include <iostream>
#include <vector>
#include <algorithm>

struct Task {
    int deadline;
    int profit;

    Task(int d, int p) : deadline(d), profit(p) {}
};

bool compareTasks(const Task& task1, const Task& task2) {
    return task1.profit > task2.profit;
}

void scheduleTasks(const std::vector<Task>& tasks, std::vector<int>& result) {
    std::vector<Task> sortedTasks = tasks;
    std::sort(sortedTasks.begin(), sortedTasks.end(), compareTasks);

    int n = tasks.size();
    std::vector<bool> slot(n, false);

    for (int i = 0; i < n; ++i) {
        for (int j = std::min(n, sortedTasks[i].deadline) - 1; j >= 0; --j) {
            if (!slot[j]) {
                result.push_back(i);
                slot[j] = true;
                break;
            }
        }
    }
}

void printSelectedTasks(const std::vector<Task>& tasks, const std::vector<int>& selectedTasks) {
    std::cout << "Conjunto de tareas seleccionado:\n";
    for (int index : selectedTasks) {
        const Task& task = tasks[index];
        std::cout << "Plazo límite: " << task.deadline << ", Beneficio: " << task.profit << "\n";
    }
    std::cout << std::endl;
}

int main() {
   
    std::vector<Task> tasks = {
        {4, 70},
        {2, 60},
        {4, 50},
        {3, 40},
        {1, 30},
        {4, 20}
    };

    std::vector<int> result;
    scheduleTasks(tasks, result);

    printSelectedTasks(tasks, result);

    return 0;
}
