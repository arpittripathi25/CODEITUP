#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string text;
    bool done;
};

// Display tasks
void showTasks(vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks yet. Add some!\n";
        return;
    }
    cout << "\n---- Your To-Do List ----\n";
    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].text;
        if (tasks[i].done) cout << " [✔]";
        cout << "\n";
    }
}

int main() {
    vector<Task> tasks;
    int choice;

    cout << "=== To-Do List Manager ===\n";

    while (true) {
        cout << "\n1. Add Task\n2. View Tasks\n3. Mark Completed\n4. Remove Task\n5. Exit\n";
        cout << "Choose option: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            Task t;
            cout << "Enter task description: ";
            getline(cin, t.text);
            t.done = false;
            tasks.push_back(t);
            cout << "Task added!\n";
        }
        else if (choice == 2) {
            showTasks(tasks);
        }
        else if (choice == 3) {
            int num;
            showTasks(tasks);
            cout << "Enter task number: ";
            cin >> num;
            if (num >= 1 && num <= tasks.size()) {
                tasks[num - 1].done = true;
                cout << "Task marked completed!\n";
            } else {
                cout << "Invalid number!\n";
            }
        }
        else if (choice == 4) {
            int num;
            showTasks(tasks);
            cout << "Enter task number to remove: ";
            cin >> num;
            if (num >= 1 && num <= tasks.size()) {
                tasks.erase(tasks.begin() + num - 1);
                cout << "Task removed!\n";
            } else {
                cout << "Invalid number!\n";
            }
        }
        else if (choice == 5) {
            cout << "Goodbye!\n";
            break;
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
