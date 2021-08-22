#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

class Report;

class Student {
private:
    char id[10];
    char name[30];
    char grade[30];
    int academicYear;
public:
    friend class Report;
};

class Subject {
private:
    char nameSubject[30];
    int credits;
    double point;
public:
    friend class Report;
};

class Report {
private:
    Student student;
    Subject *subjects;
    int n;
public:
    void inputReport();
    void showReport();
};

void Report::inputReport() {
    cout << "Information of report: " << endl;
    cout << "\tInformation of student: " << endl;
    cout << "\t\tID: ";                 fflush(stdin);      gets(student.id);
    cout << "\t\tFull name: ";          fflush(stdin);      gets(student.name);
    cout << "\t\tGrade: ";              fflush(stdin);      gets(student.grade);
    cout << "\t\tAcademic year: ";      cin >> student.academicYear;
    cout << "\tAmount of subjects: ";   cin >> n;
    subjects = new Subject[n];
    for(int i=0; i<n; i++) {
        cout << "\tSubject " << i+1 << ": " << endl;
        cout << "\t\tSubject: ";        fflush(stdin);      gets(subjects[i].nameSubject);
        cout << "\t\tCredits: ";        cin >> subjects[i].credits;
        cout << "\t\tPoint: ";          cin >> subjects[i].point;
    }
}

void titleTable() {
    cout << setw(20) << "Subject";
    cout << setw(20) << "Credits";
    cout << setw(20) << "Point" << endl;
}

void Report::showReport() {
    cout << "---------------------------------------------------------" << endl;
    cout << setw(25) << "REPORT" << endl;
    cout << setw(15) << left << "ID: " << setw(15) << student.id;
    cout << setw(15) << "Full name: " << setw(15) << student.name << endl;
    cout << setw(15) << left << "Grade: " << setw(15) << student.grade;
    cout << setw(15) << "Academic Year: " << setw(15) << student.academicYear << endl;
    cout << "---------------------------------------------------------" << endl;
    titleTable();
    double average = 0;
    int countCredits = 0;
    for(int i=0; i<n; i++) {
        cout << setw(20) << subjects[i].nameSubject;
        cout << setw(20) << subjects[i].credits;
        cout << setw(20) << subjects[i].point << endl;
        countCredits += subjects[i].credits;
        average += subjects[i].credits * subjects[i].point;
    }
    cout << setw(40) << "Average: " << setw(20) << average/countCredits << endl;
}

main() {
    Report report;
    report.inputReport();
    report.showReport();
}
