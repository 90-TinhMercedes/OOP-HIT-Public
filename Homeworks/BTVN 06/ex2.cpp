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
    void input();
    void output();
    friend class Television;
};

class Manufacturer {
  private:
    char manufacturer[30];
    char address[30];
  public:
    void input();
    void output();
    friend class Product;
};

class Product {
  protected:
    char nameProduct[30];
    Manufacturer manufacturer;
    double unitPrice;
  public:
    Product();
    void input();
    void output();
};

class Television : public Product {
  private:
    double size;
    Date date;
  public:
    Television() : Product() {
      date.day = 0;
      date.month = 0;
      date.year = 0;
      size = 0;
    }
    void input();
    void output();
};

// Constructor...
Product::Product() {
  strcpy(nameProduct, "");
  strcpy(manufacturer.manufacturer, "");
  strcpy(manufacturer.address, "");
  unitPrice = 0;
}

// Method...
void Date::input() {
  cout << "\tDate (dd/mm/yyyy): ";        cin >> day >> month >> year;
}

void Date::output() {
  cout << day << "/" << month << "/" << year << endl;
}

void Manufacturer::input() {
  cout << "\tManufacturer: ";             fflush(stdin);    gets(manufacturer);
  cout << "\tAddress: ";                  fflush(stdin);    gets(address);
}

void Manufacturer::output() {
  cout << "Manufacturer: " << manufacturer << endl;
  cout << "Address: " << address << endl;
}

void Product::input() {
  cout << "\tProduct: ";                  fflush(stdin);    gets(nameProduct);
  manufacturer.input();
  cout << "\tUnit price: ";               cin >> unitPrice;
}

void Product::output() {
  cout << "Product: " << nameProduct << endl;
  manufacturer.output();
  cout << "Unit price: " << unitPrice << " USD" << endl;
}

void Television::input() {
  cout << "Television's information: " << endl;
  date.input();
  Product::input();
  cout << "\tScreen size: ";              cin >> size;
}

void Television::output() {
  cout << "Date: ";
  date.output();
  Product::output();
  cout << "Screen size: " << size << " inch." << endl;
}

main() {
  Television television;
  television.input();
  cout << "-------------------------------------------" << endl;
  cout << "INFORMATION" << endl;
  television.output();
}