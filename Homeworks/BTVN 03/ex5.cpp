#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

class Employee {
private:
    int id;
    char name[30];
    int age;
    static int idAuto;
public:
    Employee();
    ~Employee();
    void inputEmployee();
    void showEmployee();
};

int Employee::idAuto = 1;

Employee::Employee() {
    id = idAuto;
    idAuto++;
    strcpy(name, "");
    age = 0;
}

Employee::~Employee() {
    strcpy(name, "");
    age = 0;
}

void Employee::inputEmployee() {
    cout << "\tName: ";         fflush(stdin);      gets(name);
    cout << "\tAge: ";          cin >> age;
}

void Employee::showEmployee() {
    cout << "\tID: " << id << endl;
    cout << "\tName: " << name << endl;
    cout << "\tAge: " << age << endl;
}

main() {
    int n;
    cout << "Enter amount of employee: ";
    cin >> n;
    Employee *employees;
    employees = new Employee[n];
    for (int i=0; i<n; i++) {
        cout << "Enter information employee " << i+1 << ": " << endl;
        employees[i].inputEmployee();
    }
    cout << "----------------------------------" << endl;
    cout << "INFORMATION EMPLOYEES: " << endl;
    for (int i=0; i<n; i++) {
        cout << "EMPLOYEE " << i+1 << ": " << endl;
        employees[i].showEmployee();
    }
    cout << "----------------------------------" << endl;
}
