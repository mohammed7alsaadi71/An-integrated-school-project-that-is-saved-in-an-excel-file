 #include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>
using namespace std;

class UserAuth {
public:
    static bool Intro() {
        Sleep(3000);
        system("cls");

        for (int i = 1; i <= 100; ++i) {
            Sleep(5);
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tWELCOME TO";
            cout << "\n\n\n\n\n\n\n\n\t\t\t\t\tLOADING " << i << "%";
            if (i == 100) {
                Sleep(1000);
            }
        }
        system("cls");
        cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\tð Welcome to My System";
        Sleep(3000);
        system("cls");

        string password;
        cout << "\n\n\n\n\t\t\tenter password: ";

        DWORD mode;
        HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
        GetConsoleMode(hInput, &mode);
        SetConsoleMode(hInput, mode & (~ENABLE_ECHO_INPUT));
        getline(cin, password);

        SetConsoleMode(hInput, mode);


        string correctPassword = "mohammed";

        if (password == correctPassword) {
            return true;
        } else {
            cout << "\t\t\tIncorrect password. Access denied." << endl;
            return false;
        }
    }
};
// Student class
class Student {
public:
    string name;
    int age;
    int grade;
    string address;
    string phoneNumber;

    // Function to save student data to a file
    void saveToFile() {
        ofstream file("students.csv", ios::app);
        file << name << "," << age << "," << grade << "," << address << "," << phoneNumber << endl;
        file.close();
    }
};

// Teacher class
class Teacher {
public:
    string name;
    string specialty;
    string phoneNumber;

    // Function to save teacher data to a file
    void saveToFile() {
        ofstream file("teachers.csv", ios::app);
        file << name << "," << specialty << "," << phoneNumber << endl;
        file.close();
    }
};

// Director class
class Director {
public:
    string name;
    int age;
    string position;
    string phoneNumber;

    // Function to save director data to a file
    void saveToFile() {
        ofstream file("directors.csv", ios::app);
        file << name << "," << age << "," << position << "," << phoneNumber << endl;
        file.close();
    }
};

// Function to add a new student
void addStudent() {
    Student student;
    cout << "Enter student name: ";
    cin >> student.name;
    cout << "Enter student age: ";
    cin >> student.age;
    cout << "Enter student grade: ";
    cin >> student.grade;
    cout << "Enter student address: ";
    cin >> student.address;
    cout << "Enter student phone number: ";
    cin >> student.phoneNumber;
    student.saveToFile();
    cout << "Student added successfully!" << endl;
}

// Function to delete a student by name or phone number
void deleteStudent() {
    string searchString;
    cout << "Enter student name or phone number to delete: ";
    cin >> searchString;

    ifstream inputFile("students.csv");
    ofstream outputFile("temp.csv");

    string line;
    bool found = false;

    while (getline(inputFile, line)) {
        size_t foundIndex = line.find(searchString);
        if (foundIndex == string::npos) {
            outputFile << line << endl;
        } else {
            found = true;
        }
    }

    inputFile.close();
    outputFile.close();

    remove("students.csv");
    rename("temp.csv", "students.csv");

    if (found) {
        cout << "Student deleted successfully!" << endl;
    } else {
        cout << "Student not found!" << endl;
    }
}

// Function to modify a student's data
void modifyStudent() {
    string searchString;
    cout << "Enter student name or phone number to modify: ";
    cin >> searchString;

    ifstream inputFile("students.csv");
    ofstream outputFile("temp.csv");

    string line;
    bool found = false;

    while (getline(inputFile, line)) {
        size_t foundIndex = line.find(searchString);
        if (foundIndex == string::npos) {
            outputFile << line << endl;
        } else {
            found = true;
            Student student;
            cout << "Enter modified student name: ";
            cin >> student.name;
            cout << "Enter modified student age: ";
            cin >> student.age;
            cout << "Enter modified student grade: ";
            cin >> student.grade;
            cout << "Enter modified student address: ";
            cin >> student.address;
            cout << "Enter modified student phone number: ";
            cin >> student.phoneNumber;
            student.saveToFile();
            cout << "Student modified successfully!" << endl;
        }
    }

    inputFile.close();
    outputFile.close();

    remove("students.csv");
    rename("temp.csv", "students.csv");

    if (!found) {
        cout << "Student not found!" <<endl;
    }
}

// Function to search for a student by name or phone number
void searchStudent() {
    string searchString;
    cout << "Enter student name or phone number to search: ";
    cin >> searchString;

    ifstream inputFile("students.csv");
    string line;
    bool found = false;

    while (getline(inputFile, line)) {
        size_t foundIndex = line.find(searchString);
        if (foundIndex != string::npos) {
            found = true;
            cout << "Student found: " << line << endl;
            break; // توقف عن البحث بمجرد العثور على الطالب
        }
    }

    inputFile.close();

    if (!found) {
       cout << "Student not found!" << endl;
    }
}

// Function to view all student data
void viewStudents() {
    ifstream inputFile("students.csv");
    string line;

    while (getline(inputFile, line)) {
        cout << line << endl;
    }

    inputFile.close();
}

// Function to add a new teacher
void addTeacher() {
    Teacher teacher;
    cout << "Enter teacher name: ";
    cin >> teacher.name;
    cout << "Enter teacher specialty: ";
    cin >> teacher.specialty;
    cout << "Enter teacher phone number: ";
    cin >> teacher.phoneNumber;
    teacher.saveToFile();
    cout << "Teacher added successfully!" << endl;
}

// Function to delete a teacher by name or specialty
void deleteTeacher() {
    string searchString;
    cout << "Enter teacher name or specialty to delete: ";
    cin >> searchString;

    ifstream inputFile("teachers.csv");
    ofstream outputFile("temp.csv");

    string line;
    bool found = false;

    while (getline(inputFile, line)) {
        size_t foundIndex = line.find(searchString);
        if (foundIndex == string::npos) {
            outputFile << line << endl;
        } else {
            found = true;
        }
    }

    inputFile.close();
    outputFile.close();

    remove("teachers.csv");
    rename("temp.csv", "teachers.csv");

    if (found) {
        cout << "Teacher deleted successfully!" << endl;
    } else {
        cout << "Teacher not found!" << endl;
    }
}

// Function to modify a teacher's data
void modifyTeacher() {
    string searchString;
    cout << "Enter teacher name or specialty to modify: ";
    cin >> searchString;

    ifstream inputFile("teachers.csv");
    ofstream outputFile("temp.csv");

    string line;
    bool found = false;

    while (getline(inputFile, line)) {
        size_t foundIndex = line.find(searchString);
        if (foundIndex == string::npos) {
            outputFile << line << endl;
        } else {
            found = true;
            Teacher teacher;
            cout << "Enter modified teacher name: ";
            cin >> teacher.name;
            cout << "Enter modified teacher specialty: ";
            cin >> teacher.specialty;
            cout << "Enter modified teacher phone number: ";
            cin >> teacher.phoneNumber;
            teacher.saveToFile();
            cout << "Teacher modified successfully!" << endl;
        }
    }

    inputFile.close();
    outputFile.close();

    remove("teachers.csv");
    rename("temp.csv", "teachers.csv");

    if (!found) {
        cout << "Teacher not found!" <<endl;
    }
}

// Function to search for a teacher by name or specialty
void searchTeacher() {
    string searchString;
    cout << "Enter teacher name or specialty to search: ";
    cin >> searchString;

    ifstream inputFile("teachers.csv");
    string line;
    bool found = false;

    while (getline(inputFile, line)) {
        size_t foundIndex = line.find(searchString);
        if (foundIndex != string::npos) {
            found = true;
            cout << "Teacher found: " << line << endl;
        }
    }

    inputFile.close();

    if (!found) {
        cout << "Teacher not found!" << endl;
    }
}

// Function to view all teacher data
void viewTeachers() {
    ifstream inputFile("teachers.csv");
    string line;

    while (getline(inputFile, line)) {
        cout << line << endl;
    }

    inputFile.close();
}

// Function to add a new director
void addDirector() {
    Director director;
    cout << "Enter director name: ";
    cin >> director.name;
    cout << "Enter director age: ";
    cin >> director.age;
    cout << "Enter director position: ";
    cin >> director.position;
    cout << "Enter director phone number: ";
    cin >> director.phoneNumber;
    director.saveToFile();
    cout << "Director added successfully!" << endl;
}

// Function to delete a director by name or position
void deleteDirector() {
    string searchString;
    cout << "Enter director name or position to delete: ";
    cin >> searchString;

    ifstream inputFile("directors.csv");
    ofstream outputFile("temp.csv");

    string line;
    bool found = false;

    while (getline(inputFile, line)) {
        size_t foundIndex = line.find(searchString);
        if (foundIndex == string::npos) {
            outputFile << line << endl;
        } else {
            found = true;
        }
    }

    inputFile.close();
    outputFile.close();

    remove("directors.csv");
    rename("temp.csv", "directors.csv");

    if (found) {
        cout << "Director deleted successfully!" << endl;
    } else {
        cout << "Director not found!" << endl;
    }
}

// Function to modify a director's data
void modifyDirector() {
    string searchString;
    cout << "Enter director name or position to modify: ";
    cin >> searchString;

    ifstream inputFile("directors.csv");
    ofstream outputFile("temp.csv");

    string line;
    bool found = false;

    while (getline(inputFile, line)) {
        size_t foundIndex = line.find(searchString);
        if (foundIndex == string::npos) {
            outputFile << line << endl;
        } else {
            found = true;
            Director director;
            cout << "Enter modified director name: ";
            cin >> director.name;
            cout << "Enter modified director age: ";
            cin >> director.age;
            cout << "Enter modified director position: ";
            cin >> director.position;
            cout << "Enter modified director phone number: ";
            cin >> director.phoneNumber;
            director.saveToFile();
            cout << "Director modified successfully!" << endl;
        }
    }

    inputFile.close();
    outputFile.close();

    remove("directors.csv");
    rename("temp.csv", "directors.csv");

    if (!found) {
        cout << "Director not found!" << endl;
    }
}

// Function to search for a director by name or position
void searchDirector() {
    string searchString;
    cout << "Enter director name or position to search: ";
    cin >> searchString;

    ifstream inputFile("directors.csv");
    string line;
    bool found = false;

    while (getline(inputFile, line)) {
        size_t foundIndex = line.find(searchString);
        if (foundIndex != string::npos) {
            found = true;
            cout << "Director found: " << line << endl;
        }
    }

    inputFile.close();

    if (!found) {
        cout << "Director not found!" << endl;
    }
}

// Function to view all director data
void viewDirectors() {
    ifstream inputFile("directors.csv");
    string line;

    while (getline(inputFile, line)) {
        cout << line << endl;
    }

    inputFile.close();
}

int main() {
    system("cls");
    cout << "\n\n\n\t\t\t\tWELCOME TO CONTACT MANAGEMENT SYSTEM" << endl;
    if (!UserAuth::Intro()) {
        return 0;
    }
    int choice;

    do {
        cout << "\n\n\t\t\t\t----- School management system -----" << endl;
        cout << "\t\t\t1. Student system" << endl;
        cout << "\t\t\t2. Teacher system" << endl;
        cout << "\t\t\t3. Manager system" << endl;
        cout << "\t\t\t4. Exit" << endl;
        cout << "\t\t==========================" << endl;
        cout << "Choose the system: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int studentChoice;
                do {
                    cout << "\n\n\t\t\t\t----- Student system -----" << endl;
                    cout << "\t\t\t1. Add student" << endl;
                    cout << "\t\t\t2. Delete a student" << endl;
                    cout << "\t\t\t3. Modify student" << endl;
                    cout << "\t\t\t4. Search for a student" << endl;
                    cout << "\t\t\t5. View students" << endl;
                    cout << "\t\t\t6. Exit" << endl;
                    cout << "\t\t==========================" << endl;
                    cout << "Choose the process: ";
                    cin >> studentChoice;

                    switch (studentChoice) {
                        case 1:
                            addStudent();
                            break;
                        case 2:
                            deleteStudent();
                            break;
                        case 3:
                            modifyStudent();
                            break;
                        case 4:
                            searchStudent();
                            break;
                        case 5:
                            viewStudents();
                            break;
                        case 6:
                            cout << "Returning to the previous menu..." << endl;
                            break;
                        default:
                            cout << "Incorrect selection. Please try again." << endl;
                            break;
                    }
                } while (studentChoice != 6);
                break;
            }
            case 2: {
                int teacherChoice;
                do {
                    cout << "\n\n\t\t\t\t----- Teacher system -----" << endl;
                    cout << "\t\t\t1. Add teacher" << endl;
                    cout << "\t\t\t2. Delete teacher" << endl;
                    cout << "\t\t\t3. Modify teacher" << endl;
                    cout << "\t\t\t4. Search for a teacher" << endl;
                    cout << "\t\t\t5. View teachers" << endl;
                    cout << "\t\t\t6. Exit" << endl;
                    cout << "\t\t==========================" << endl;
                    cout << "Choose the process: ";
                    cin >> teacherChoice;

                    switch (teacherChoice) {
                        case 1:
                            addTeacher();
                            break;
                        case 2:
                            deleteTeacher();
                            break;
                        case 3:
                            modifyTeacher();
                            break;
                        case 4:
                            searchTeacher();
                            break;
                        case 5:
                            viewTeachers();
                            break;
                        case 6:
                            cout << "Returning to the previous menu..." << endl;
                            break;
                        default:
                            cout << "Incorrect selection. Please try again." << endl;
                            break;
                    }
                } while (teacherChoice != 6);
                break;
            }
            case 3: {
                int managerChoice;
                do {
                    cout << "\n\n\t\t\t\t----- Manager system -----" << endl;
                    cout << "\t\t\t1. Add manager" << endl;
                    cout << "\t\t\t2. Delete manager" << endl;
                    cout << "\t\t\t3. Modify manager" << endl;
                    cout << "\t\t\t4. Search for a manager" << endl;
                    cout << "\t\t\t5. View managers" << endl;
                    cout << "\t\t\t6. Exit" << endl;
                    cout << "\t\t==========================" << endl;
                    cout <<"Choose the process: ";
                    cin >> managerChoice;

                    switch (managerChoice) {
                        case 1:
                            addDirector();
                            break;
                        case 2:
                            deleteDirector();
                            break;
                        case 3:
                            modifyDirector();
                            break;
                        case 4:
                            searchDirector();
                            break;
                        case 5:
                            viewDirectors();
                            break;
                        case 6:
                            cout << "Returning to the previous menu..." << endl;
                            break;
                        default:
                            cout << "Incorrect selection. Please try again." << endl;
                            break;
                    }
                } while (managerChoice != 6);
                break;
            }
            case 4:
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Incorrect selection. Please try again." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
