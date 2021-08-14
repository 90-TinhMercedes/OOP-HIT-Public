#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

class Student;

class School {
private:
    char nameSchool[30];
    char establishedDateSchool[30];
public:
    friend class Faculty;
    friend class Student;
};

class Faculty {
private:
    char nameFaculty[30];
    char establishedDateFaculty[30];
    School school;
public:
    void inputFaculty();
    void showFaculty();
    friend class Student;
};

class Student {
private:
    Faculty faculty;
    char grade[30];
    double score;
public:
    void inputStudent();
    void showStudent();
    Student();
};

Student::Student() {
    strcpy(faculty.school.nameSchool, "");
    strcpy(faculty.school.establishedDateSchool, "");
    strcpy(faculty.nameFaculty, "");
    strcpy(faculty.establishedDateFaculty, "");
    strcpy(grade, "");
    score = 0.0;
}

void Faculty::inputFaculty() {
    cout << "\tSchool's information: " << endl;
    cout << "\t\tSchool: ";             fflush(stdin);      gets(school.nameSchool);
    cout << "\t\tEstablished date: ";   fflush(stdin);      gets(school.establishedDateSchool);
    cout << "\tFaculty's information: " << endl;
    cout << "\t\tFaculty: ";            fflush(stdin);      gets(nameFaculty);
    cout << "\t\tEstablished date: ";   fflush(stdin);      gets(establishedDateFaculty);
}

void Faculty::showFaculty() {
    cout << "\tSchool: " << school.nameSchool << endl;
    cout << "\tEstablished date school: " << school.establishedDateSchool << endl;
    cout << "\tFaculty: " << nameFaculty << endl;
    cout << "\tEstablished date faculty: " << establishedDateFaculty << endl;
}

void Student::inputStudent() {
    faculty.inputFaculty();
    cout << "\tClass: ";                fflush(stdin);      gets(grade);
    cout << "\tScore: ";                cin >> score;
}

void Student::showStudent() {
    faculty.showFaculty();
    cout << "\tClass: " << grade << endl;
    cout << "\tScore: " << score << endl;
}

main() {
    int n;
    cout << "Enter amount of students: ";
    cin >> n;
    Student *students;
    students = new Student[n];
    for (int i=0; i<n; i++) {
        cout << "Enter information student " << i+1 << ": " << endl;
        students[i].inputStudent();
    }
    cout << "----------------------------------" << endl;
    cout << "INFORMATION STUDENT: " << endl;
    for (int i=0; i<n; i++) {
        cout << "STUDENT " << i+1 << ": " << endl;
        students[i].showStudent();
    }
    cout << "----------------------------------" << endl;
}

















