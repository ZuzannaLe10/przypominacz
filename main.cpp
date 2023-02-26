#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

struct Task {
    string content;
    time_t notificationTime;
    time_t validityPeriod;
};

vector<Task> tasks;

void Dodaj() {
    Task task;
    cout << "Enter content: ";
    getline(cin, task.content);
    cout << "Enter notification time (in format: YYYY-MM-DD HH:MM:SS): ";
    cin >> task.notificationTime;
    cout << "Enter validity period in seconds: ";
    cin >> task.validityPeriod;
    tasks.push_back(task);
    cout << "Task added successfully.\n";
}

void Zobacz() {
    if (tasks.empty()) {
        cout << "No tasks to show.\n";
    } else {
        for (int i = 0; i < tasks.size(); i++) {
            cout << "Task " << i + 1 << ":\n";
            cout << "Content: " << tasks[i].content << endl;
            cout << "Notification time: " << ctime(&tasks[i].notificationTime);
            cout << "Validity period: " << tasks[i].validityPeriod << " seconds.\n";
        }
    }
}

void Zapisz() {
    ofstream outputFile;
    outputFile.open("tasks.txt");
    if (!outputFile.is_open()) {
        cout << "Error opening file.\n";
    } else {
        outputFile << tasks.size() << endl;
        for (int i = 0; i < tasks.size(); i++) {
            outputFile << tasks[i].content << endl;
            outputFile << tasks[i].notificationTime << endl;
            outputFile << tasks[i].validityPeriod << endl;
        }
        outputFile.close();
        cout << "Tasks saved successfully.\n";
    }
}

int main() {
    int choice = 0;
    while (true) {
        cout << "Select an option:\n";
        cout << "1. Add task\n";
        cout << "2. View tasks\n";
        cout << "3. Save tasks\n";
        cout << "4. Exit\n";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                Dodaj();
                break;
            case 2:
                Zobacz();
                break;
            case 3:
                Zapisz();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice.\n";
                break;
        }
    }
    return 0;
}
