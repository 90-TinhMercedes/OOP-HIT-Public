#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

class Vahicle {
  protected:
    char brand[30];
    int year;
    char manufacturer[30];
  public:
    void input();
    void output();
};

class Car : public Vahicle {
  private:
    int slot;
    double capacity;
  public:
    void input();
    void output();
};

class Motorcycle : public Vahicle {
  private:
    double cubicCentimetre;
  public:
    void input();
    void output();
};

void Vahicle::input() {
  cout << "\tBrand: ";                    fflush(stdin);    gets(brand);
  cout << "\tYear of manufacturer: ";     cin >> year;
  cout << "\tManufacturer: ";             fflush(stdin);    gets(manufacturer);
}

void Vahicle::output() {
  cout << "Brand: " << brand << endl;
  cout << "Year of manufacturer: " << year << endl;
  cout << "Manufacturer: " << manufacturer << endl;
}

void Car::input() {
  Vahicle::input();
  cout << "\tSlot: ";       cin >> slot;
  cout << "\tCapacity: ";   cin >> capacity;
}

void Car::output() {
  Vahicle::output();
  cout << "Slot: " << slot << endl;
  cout << "Capacity: " << capacity << endl;
}

void Motorcycle::input() {
  Vahicle::input();
  cout << "\tCubic centimetre: ";     cin >> cubicCentimetre;
}

void Motorcycle::output() {
  Vahicle::output();
  cout << "Cubic centimetre: " << cubicCentimetre << endl;
}

main() {
  Car car;
  Motorcycle motorcycle;
  cout << "Information of Car:" << endl;
  car.input();
  cout << "Information of Motorcycle: " << endl;
  motorcycle.input();
  cout << "------------------------------------" << endl;
  cout << "RESULT" << endl;
  cout << "------------------------------------" << endl;
  cout << "CAR'S INFORMATION:" << endl;
  car.output();
  cout << "------------------------------------" << endl;
  cout << "MOTORCYCLE'S INFORMATION:" << endl;
  motorcycle.output();
}