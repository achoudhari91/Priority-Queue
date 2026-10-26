#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Student {
    string name;
    float cgpa;
};

struct Compare {
    bool operator()(Student a, Student b) {
        return a.cgpa < b.cgpa;
    }
};

int main() {
    priority_queue<Student, vector<Student>, Compare> pq;
    int choice, processed = 0;
    Student s;

    do {
        cout << "\n1. Insert Student";
        cout << "\n2. Delete Highest CGPA Student";
        cout << "\n3. Display Queue";
        cout << "\n4. Count Students Processed";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter student name: ";
                cin >> s.name;
                cout << "Enter CGPA: ";
                cin >> s.cgpa;

                pq.push(s);
                cout << "\nStudent inserted successfully.";
                break;

            case 2:
                if (pq.empty()) {
                    cout << "\nQueue is empty!";
                } else {
                    cout << "\nDeleted student: "
                         << pq.top().name
                         << " (CGPA: " << pq.top().cgpa << ")";
                    pq.pop();
                    processed++;
                }
                break;

            case 3:
                if (pq.empty()) {
                    cout << "\nQueue is empty!";
                } else {
                    priority_queue<Student, vector<Student>, Compare> temp = pq;

                    cout << "\nStudents in priority order:\n";
                    while (!temp.empty()) {
                        cout << temp.top().name
                             << " - CGPA: " << temp.top().cgpa << endl;
                        temp.pop();
                    }
                }
                break;

            case 4:
                cout << "\nStudents processed: " << processed;
                break;

            case 5:
                cout << "\nProgram ended.";
                break;

            default:
                cout << "\nInvalid choice!";
        }
    } while (choice != 5);

    return 0;
}
