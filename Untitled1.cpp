#include <iostream>
#include <vector>

struct Task {
    std::string description;
    bool completed;
};

class ToDoListManager {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& description) {
        tasks.push_back({description, false});
        std::cout << "Task \"" << description << "\" added successfully.\n";
    }

    void viewTasks() {
        if (tasks.empty()) {
            std::cout << "No tasks available.\n";
        } else {
            std::cout << "Tasks:\n";
            for (size_t i = 0; i < tasks.size(); ++i) {
                const std::string status = tasks[i].completed ? "Completed" : "Pending";
                std::cout << i + 1 << ". " << tasks[i].description << " - " << status << "\n";
            }
        }
    }

    void markAsCompleted(size_t taskIndex) {
        if (taskIndex >= 1 && taskIndex <= tasks.size()) {
            tasks[taskIndex - 1].completed = true;
            std::cout << "Task \"" << tasks[taskIndex - 1].description << "\" marked as completed.\n";
        } else {
            std::cout << "Invalid task index.\n";
        }
    }

    void removeTask(size_t taskIndex) {
        if (taskIndex >= 1 && taskIndex <= tasks.size()) {
            tasks.erase(tasks.begin() + taskIndex - 1);
            std::cout << "Task removed successfully.\n";
        } else {
            std::cout << "Invalid task index.\n";
        }
    }
};

int main() {
    ToDoListManager manager;

    char choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case '1': {
                std::cin.ignore();
                std::cout << "Enter task description: ";
                std::string description;
                std::getline(std::cin, description);
                manager.addTask(description);
                break;
            }
            case '2':
                manager.viewTasks();
                break;
            case '3': {
                size_t taskIndex;
                std::cout << "Enter task index to mark as completed: ";
                std::cin >> taskIndex;
                manager.markAsCompleted(taskIndex);
                break;
            }
            case '4': {
                size_t taskIndex;
                std::cout << "Enter task index to remove: ";
                std::cin >> taskIndex;
                manager.removeTask(taskIndex);
                break;
            }
            case '5':
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '5');

    return 0;
}
