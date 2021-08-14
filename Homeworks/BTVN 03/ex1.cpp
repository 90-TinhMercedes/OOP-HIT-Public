#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

class Employee {
private:
    char id[30];
    char name[30];
    int age;
    static double salary;
public:
    void inputEmployee();
    void showEmployee();
};

void Employee::inputEmployee() {
    cout << "\tID: ";       fflush(stdin);      gets(id);
    cout << "\tName: ";     fflush(stdin);      gets(name);
    cout << "\tAge: ";      cin >> age;
}

void Employee::showEmployee() {
    cout << "\tID: " << id << endl;
    cout << "\tName: " << name << endl;
    cout << "\tAge: " << age << endl;
    cout << "\tSalary: " << salary << " USD." << endl;
}

double Employee::salary = 1500.0;

main() {
    Employee employee1, employee2;
    cout << "Enter employee1's information: " << endl;
    employee1.inputEmployee();
    cout << "Enter employee2's information: " << endl;
    employee2.inputEmployee();
    cout << "----------------------------------" << endl;
    cout << "INFORMATION" << endl;
    cout << "Employee 1: " << endl;
    employee1.showEmployee();
    cout << "Employee 2: " << endl;
    employee2.showEmployee();
    cout << "----------------------------------" << endl;
}
