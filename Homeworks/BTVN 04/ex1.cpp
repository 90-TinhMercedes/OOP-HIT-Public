#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;
public:
    void inputDate();
    void showDate();
    friend class Personnel;
};

class Personnel {
private:
    int id;
    char fullName[30];
    static int idAuto;
    Date date;
public:
    void inputPersonnel();
    void showPersonnel();
    Personnel();
    ~Personnel();
};

int Personnel::idAuto = 1;

Personnel::Personnel() {
    this->id = idAuto;
    idAuto++;
    strcpy(this->fullName, "");
    this->date.day = 0;
    this->date.month = 0;
    this->date.year = 0;
}

Personnel::~Personnel() {
    this->id = 0;
    strcpy(this->fullName, "");
    this->date.day = 0;
    this->date.month = 0;
    this->date.year = 0;
}

void Date::inputDate() {
    cout << "(dd/mm/yyyy): ";
    cin >> day >> month >> year;
}

void Date::showDate() {
    cout << day << "/" << month << "/" << year << endl;
}

void Personnel::inputPersonnel() {
    cout << "\tFull name: ";        fflush(stdin);      gets(fullName);
    cout << "\tDate ";              date.inputDate();
}

void title() {
    cout << setw(10) << left << "ID";
    cout << setw(20) << left << "Full name";
    cout << setw(10) << left << "Date" << endl;
    cout << setfill('-');
    cout << setw(40) << "-" << endl;
    cout << setfill(' ');
}

void Personnel::showPersonnel() {
    cout << setw(10) << left << id;
    cout << setw(20) << left << fullName;
    date.showDate();
}
main() {
    Personnel *personnel;
    int n;
    cout << "Enter amount of personnel: ";
    cin >> n;
    personnel = new Personnel[n];
    for (int i=0; i<n; i++) {
        cout << "Information of personnel " << i+1 << ":" << endl;
        personnel[i].inputPersonnel();
    }
    cout << "LIST PERSONNELS" << endl;
    title();
    for (int i=0; i<n; i++) {
        personnel[i].showPersonnel();
    }
}

