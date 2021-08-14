#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

class Address {
private:
    char hotline[12];
    char ward[30];
    char district[30];
    char city[30];
public:
    friend class Enterprise;
};

class Date {
private:
    int day;
    int month;
    int year;
public:
    void inputDate();
    void showDate();
};

class Enterprise {
private:
    int idEnterprise;
    char nameEnterprise[30];
    Date establishedDate;
    Address address;
    char director[30];
    long revenue;
public:
    void inputEnterprise();
    void showEnterprise();
};

void Date::inputDate() {
    cout << "(dd/mm/yyyy): ";       cin >> day >> month >> year;
}

void Date::showDate() {
    cout << day << "/" << month << "/" << year << endl;
}

void Enterprise::inputEnterprise() {
    cout << "Enter enterprise's information: " << endl;
    cout << "\tID: ";        cin >> idEnterprise;
    cout << "\tEnterprise: ";           fflush(stdin);          gets(nameEnterprise);
    cout << "\tEstablished date ";      establishedDate.inputDate();
    cout << "\tAddress: " << endl;
    cout << "\t\tHotline: ";            fflush(stdin);          gets(address.hotline);
    cout << "\t\tWard: ";               fflush(stdin);          gets(address.ward);
    cout << "\t\tDistrict: ";           fflush(stdin);          gets(address.district);
    cout << "\t\tCity: ";               fflush(stdin);          gets(address.city);
    cout << "\tDirector: ";             fflush(stdin);          gets(director);
    cout << "\tRevenue: ";              cin >> revenue;
}

void Enterprise::showEnterprise() {
    cout << "\tID: " << idEnterprise << endl;
    cout << "\tEnterprise: " << nameEnterprise << endl;
    cout << "\tEstablished date: ";
    establishedDate.showDate();
    cout << "\tAddress: " << endl;
    cout << "\t\tHotline: " << address.hotline << endl;
    cout << "\t\tWard: " << address.ward << endl;
    cout << "\t\tDistrict: " << address.district << endl;
    cout << "\t\tCity: " << address.city << endl;
    cout << "\tDirector: " << director << endl;
    cout << "\tRevenue: " << revenue << " USD." << endl;
}
main() {
    Enterprise enterprise;
    enterprise.inputEnterprise();
    cout << "-----------------------------------------" << endl;
    cout << "INFORMATION" << endl;
    enterprise.showEnterprise();
    cout << "-----------------------------------------" << endl;
}
