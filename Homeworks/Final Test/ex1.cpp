#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

class Company;

class Persion {
  protected:
    char fullName[30];
    int age;
    char sex[10];
  public:
    void input();
    void output();
    friend class Company;
};

class Employee : public Persion {
  private:
    char codeEmployee[10];
    char position[30];
    double salary;
  public:
    void input();
    void output();
    friend class Company;
    friend void fixSalary(Company company);
    friend void sortListEmployee(Company company);
};

class Company {
  private:
    char codeCompany[10];
    char address[30];
    Employee *listEmployee;
    int amount;
  public:
    void input();
    void output();
    friend void fixSalary(Company company);
    friend void sortListEmployee(Company company);
};

void Persion::input() {
  cout << "\tFull name: ";      fflush(stdin);    gets(fullName);
  cout << "\tAge: ";            cin >> age;
  cout << "\tSex: ";            fflush(stdin);    gets(sex);
}

void Persion::output() {
  cout << setw(15) << fullName;
  cout << setw(10) << age;
  cout << setw(10) << sex << endl;
}

void Employee::input() {
  cout << "\tCode employee: ";    fflush(stdin);    gets(codeEmployee);
  cout << "\tPosition: ";         fflush(stdin);    gets(position);
  cout << "\tSalary: ";           cin >> salary;
  Persion::input();
}

void Employee::output() {
  cout << setw(15) << codeEmployee;
  cout << setw(15) << position;
  cout << setw(10) << salary;
  Persion::output(); 
}

void Company::input() {
  cout << "\tCode company: ";     fflush(stdin);    gets(codeCompany);
  cout << "\tAddress: ";          fflush(stdin);    gets(address);
  cout << "Amount of employee: "; cin >> amount;
  listEmployee = new Employee[amount];
  for(int i = 0; i < amount; i++) {
    cout << "Information of employee " << i + 1 << ": " << endl;
    listEmployee[i].input();
  }
}

void title() {
  cout << setw(15) << "Code employee";
  cout << setw(15) << "Position";
  cout << setw(10) << "Salary";
  cout << setw(15) << "Full name";
  cout << setw(10) << "Age";
  cout << setw(10) << "Sex" << endl;
}

void Company::output() {
  cout << setw(15) << "Code company: ";
  cout << setw(15) << codeCompany;
  cout << setw(15) << "Address: ";
  cout << setw(15) << address << endl;
  cout << "List employee: " << endl;
  title();
  for (int i = 0; i < amount; i++) {
    listEmployee[i].output();
  }
}

void fixSalary(Company company) {
  for (int i = 0; i < company.amount; i++) {
    if (company.listEmployee[i].age > 40 && strcmp(company.listEmployee[i].position, "accountant") == 0)
      company.listEmployee[i].salary = 1000;
  }
}

void sortListEmployee(Company company) {
    for (int i = 0; i < company.amount; i++) {
      for (int j = i; j < company.amount; j++) {
        if (company.listEmployee[i].salary > company.listEmployee[j].salary)
          swap(company.listEmployee[i], company.listEmployee[j]);
      }
  }
}

main() {
  Company company;
  company.input();
  cout << "------------------------------" << endl;
  cout << "COMPANY'S INFORMATION" << endl;
  company.output();
  fixSalary(company);
  cout << "------------------------------" << endl;
  cout << "COMPANY'S INFORMATION AFTER FIX SALARY" << endl;
  company.output();
  sortListEmployee(company);
  cout << "------------------------------" << endl;
  cout << "COMPANY'S INFORMATION AFTER SORT" << endl;
  company.output();

}