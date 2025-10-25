#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    string Sap;
    string Program;
    string section;
    string contact;
    int marks[3];   
    int totalMarks;
};

// We use for calculate for total mark
void calculateTotalMarks(Student &student) {
    student.totalMarks = 0;
    for (int j = 0; j < 3; j++) {
        student.totalMarks += student.marks[j];
    }
}

// we use for grade
char calculateGrade(int totalMarks) {
    if (totalMarks >= 240) 
        return 'A';
    else if (totalMarks >= 210) 
        return 'B';
    else if (totalMarks >= 180) 
        return 'C';
    else if (totalMarks >= 150)
        return 'D';
    else return 'F';
}

// we use enter data of student 
void enter(int &total, Student data[]) {
    int numStudents;
    cout << "How many students' data do you want to enter: ";
    cin >> numStudents;

    for (int i = total; i < total + numStudents; i++) {
        cout << "\nEnter student data for student " << i + 1 << ":\n";
        cout << "Enter name: ";
        cin >> data[i].name;
        cout << "Enter SAP ID: ";
        cin >> data[i].Sap;
        cout << "Enter Program: ";
        cin >> data[i].Program;
        cout << "Enter Section: ";
        cin >> data[i].section;
        cout << "Enter contact: ";
        cin >> data[i].contact;

        for (int j = 0; j < 3; j++) {
            cout << "Enter marks for subject from 0 to 100 in subject " << j + 1 << ": ";
            do {
                cin >> data[i].marks[j];
                if (data[i].marks[j] > 100 || data[i].marks[j] < 0) {
                    cout << "Please enter marks between 0 to 100: ";
                }
            } while (data[i].marks[j] > 100 || data[i].marks[j] < 0);
        }

        calculateTotalMarks(data[i]); 
    }

    total += numStudents;
}

// We use this to display highest marks
void displayHighestMarks(int total, Student data[]) {
    if (total == 0) {
        cout << "No records available to find the highest marks.\n";
        return;
    }

    int highestIndex = 0;
    for (int i = 1; i < total; i++) {
        if (data[i].totalMarks > data[highestIndex].totalMarks) {
            highestIndex = i;
        }
    }

    cout << "\nStudent with the highest marks:\n";
    cout << "Name: " << data[highestIndex].name << endl;
    cout << "SAP ID: " << data[highestIndex].Sap << endl;
    cout << "Program: " << data[highestIndex].Program << endl;
    cout << "Section: " << data[highestIndex].section << endl;
    cout << "Contact: " << data[highestIndex].contact << endl;
    cout << "Marks: ";
    for (int j = 0; j < 3; j++) {
        cout << data[highestIndex].marks[j] << " ";
    }
    cout << "\nTotal Marks: " << data[highestIndex].totalMarks << endl;
}

// We use this to sort student marks
void sortStudentsByMarks(int total, Student data[]) {
    if (total == 0) {
        cout << "No records to sort.\n";
        return;
    }

    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            if (data[j].totalMarks < data[j + 1].totalMarks) {
                swap(data[j], data[j + 1]); // Swap students
            }
        }
    }

    cout << "\nStudents sorted by total marks highest to lowest:\n";
    for (int i = 0; i < total; i++) {
        cout << i + 1 << ". " << data[i].name << " - " << data[i].totalMarks << " marks\n";
    }
}

// We use this for showing data
void show(int total, Student data[]) {
    if (total == 0) {
        cout << "No records to display.\n";
        return;
    }

    for (int i = 0; i < total; i++) {
        cout << "\nData of student " << i + 1 << ":\n";
        cout << "Name: " << data[i].name << endl;
        cout << "SAP ID: " << data[i].Sap << endl;
        cout << "Program: " << data[i].Program << endl;
        cout << "Section: " << data[i].section << endl;
        cout << "Contact: " << data[i].contact << endl;
        cout << "Marks: ";
        for (int j = 0; j < 3; j++) {
            cout << data[i].marks[j] << " ";
        }
        cout << "\nTotal Marks: " << data[i].totalMarks << endl;
    }
}

// We use this to search data
void searchStudent(int total, Student data[]) {
    if (total == 0) {
        cout << "No records to search.\n";
        return;
    }

    string sapID;
    cout << "Enter SAP ID of the student to search: ";
    cin >> sapID;

    bool found = false;
    for (int i = 0; i < total; i++) {
        if (data[i].Sap == sapID) {
            cout << "\nStudent Found:\n";
            cout << "Name: " << data[i].name << endl;
            cout << "SAP ID: " << data[i].Sap << endl;
            cout << "Program: " << data[i].Program << endl;
            cout << "Section: " << data[i].section << endl;
            cout << "Contact: " << data[i].contact << endl;
            cout << "Marks: ";
            for (int j = 0; j < 3; j++) {
                cout << data[i].marks[j] << " ";
            }
            cout << "\nTotal Marks: " << data[i].totalMarks << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student with SAP ID " << sapID << " not found.\n";
    }
}

// We use this for updating student data
void updateStudent(int total, Student data[]) {
    if (total == 0) {
        cout << "No records to update.\n";
        return;
    }

    string sapID;
    cout << "Enter SAP ID of the student to update: ";
    cin >> sapID;

    bool found = false;
    for (int i = 0; i < total; i++) {
        if (data[i].Sap == sapID) {
            cout << "\nUpdating data for student:\n";
            cout << "Enter name: ";
            cin >> data[i].name;
            cout << "Enter SAP ID: ";
            cin >> data[i].Sap;
            cout << "Enter Program: ";
            cin >> data[i].Program;
            cout << "Enter Section: ";
            cin >> data[i].section;
            cout << "Enter contact: ";
            cin >> data[i].contact;

            for (int j = 0; j < 3; j++) {
                cout << "Enter marks for subject from 0 to 100 in subject " << j + 1 << ": ";
                do {
                    cin >> data[i].marks[j];
                    if (data[i].marks[j] > 100 || data[i].marks[j] < 0) {
                        cout << "Please enter marks between 0 to 100: ";
                    }
                } while (data[i].marks[j] > 100 || data[i].marks[j] < 0);
            }

            calculateTotalMarks(data[i]); 
            cout << "Student data updated successfully.\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student with SAP ID " << sapID << " not found.\n";
    }
}

// Function to show student grade
void showStudentWithGrade(int total, Student data[]) {
    if (total == 0) {
        cout << "No records to display.\n";
        return;
    }

    for (int i = 0; i < total; i++) {
        cout << "\nData of student " << i + 1 << ":\n";
        cout << "Name: " << data[i].name << endl;
        cout << "SAP ID: " << data[i].Sap << endl;
        cout << "Program: " << data[i].Program << endl;
        cout << "Section: " << data[i].section << endl;
        cout << "Contact: " << data[i].contact << endl;
        cout << "Marks: ";
        for (int j = 0; j < 3; j++) {
            cout << data[i].marks[j] << " ";
        }
        cout << "\nTotal Marks: " << data[i].totalMarks << endl;
        cout << "Grade: " << calculateGrade(data[i].totalMarks) << endl;  
    }
}

int main() {
    cout << "\n***Welcome to student data management***\n";
    Student data[100]; 
    int total = 0;
    int choice;

    while (true) {
        cout << "\nMenu please select one:\n";
        cout << "1. Enter Student Data\n";
        cout << "2. Show All Students Data\n";
        cout << "3. Show Student with Highest Marks\n";
        cout << "4. Sort Students by Marks\n";
        cout << "5. Search Student by SAP ID\n";
        cout << "6. Update Student Data\n";
        cout << "7. Show Student Data with Grade\n"; 
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                enter(total, data);
                break;
            case 2:
                show(total, data);
                break;
            case 3:
                displayHighestMarks(total, data);
                break;
            case 4:
                sortStudentsByMarks(total, data);
                break;
            case 5:
                searchStudent(total, data);
                break;
            case 6:
                updateStudent(total, data);
                break;
            case 7:
                showStudentWithGrade(total, data);
                break;
            case 8:
                int a;
                cout << "Are you sure you want to close the program? (Press 1 to close, 2 to continue): ";
                cin >> a;
                if (a == 1) {
                    return 0; 
                } 
                
				else {
                    break;
                }
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
