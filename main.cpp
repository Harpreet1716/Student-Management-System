#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Define Student class to hold student information
class Student {
public:
    string name;
    int rollNumber;
    int age;
    string address;
    string contact;

    // Function to display student details
    void displayDetails() const {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Age: " << age << endl;
        cout << "Address: " << address << endl;
        cout << "Contact: " << contact << endl;
    }
};

// Function to add a new student record
void addStudent(vector<Student>& students) {
    Student newStudent;
    // Input details for the new student
    cout << "Enter name: ";
    cin >> newStudent.name;
    cout << "Enter roll number: ";
    cin >> newStudent.rollNumber;
    cout << "Enter age: ";
    cin >> newStudent.age;
    cout << "Enter address: ";
    cin.ignore(); // Clear input buffer
    getline(cin, newStudent.address);
    cout << "Enter contact: ";
    getline(cin, newStudent.contact);

    students.push_back(newStudent);
    cout << "Student added successfully!" << endl;
}

// Function to display all student records
void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No records found!" << endl;
        return;
    }

    for (const auto& student : students) {
        student.displayDetails();
        cout << endl;
    }
}

int main() {
    vector<Student> students;

    // Menu-driven program for student management
    int choice;
    do {
        cout << "\nStudent Management System" << endl;
        cout << "1. Add Student\n2. Display All Students\n3. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayAllStudents(students);
                break;
            case 3:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
