#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
//#include <bits/stdc++.h>
using namespace std;

class Coupon;

class Employee {
  private:
    char name[30];
    char position[30];
  public:
    friend class Coupon;
};

class Department {
  private:
    char codeRoom[10];
    char room[30];
    char manager[30];
  public:
    friend class Coupon;
};

class Asset {
  private:
    char nameAsset[30];
    int amount;
    char status[30];
  public:
    friend class Coupon;
    friend void fixAmountOfComputer(Coupon coupon);
    friend void insertAsset(Coupon &coupon, int pos);
    friend void sortAssetsByAmount(Coupon coupon);
};

class Coupon {
  private:
    char codeCoupon[10];
    char date[30];
    Employee employee;
    Department department;
    Asset *assets;
    int amountOfAssets;
  public:
    void inputCoupon();
    void showCoupon();
    friend void fixAmountOfComputer(Coupon coupon);
    friend void insertAsset(Coupon &coupon, int pos);
    friend void sortAssetsByAmount(Coupon coupon);
};

void Coupon::inputCoupon() {
  cout << "Information of coupon: " << endl;
  cout << "\tCode coupon: ";            fflush(stdin);    gets(codeCoupon);
  cout << "\tDate: ";                   fflush(stdin);    gets(date);
  cout << "Employee: " << endl;
  cout << "\tEmployee: ";               fflush(stdin);    gets(employee.name);
  cout << "\tPosittion: ";              fflush(stdin);    gets(employee.position);
  cout << "Department: " << endl;
  cout << "\tCode department: ";        fflush(stdin);    gets(department.codeRoom);
  cout << "\tDepartment: ";             fflush(stdin);    gets(department.room);
  cout << "\tManager: ";                fflush(stdin);    gets(department.manager);
  cout << "Information of assets: " << endl;
  cout << "Amount of assets: ";         cin >> amountOfAssets;
  assets = new Asset[amountOfAssets];
  for (int i = 0; i < amountOfAssets; i++) {
    cout << "Asset " << i+1 << ": " << endl;
    cout << "\tAsset: ";                fflush(stdin);    gets(assets[i].nameAsset);
    cout << "\tAmount: ";               cin >> assets[i].amount;
    cout << "\tStatus: ";               fflush(stdin);    gets(assets[i].status);
  }
}

void title() {
  cout << setw(20) << "ASSET";
  cout << setw(20) << "AMOUNT";
  cout << setw(20) << "STATUS" << endl;
}

void Coupon::showCoupon() {
  int amountAssets = 0;
  cout << "\t\t\tASSET STATISTIC COUPON" << endl;
  cout << setw(20) << left << "Coupon code: " << setw(20) << codeCoupon;
  cout << setw(20) << "Date: " << setw(20) << date << endl;
  cout << setw(20) << left << "Employee: " << setw(20) << employee.name;
  cout << setw(20) << "Position: " << setw(20) << employee.position << endl;
  cout << setw(20) << left << "Department: " << setw(20) << department.room;
  cout << setw(20) << "Department code: " << setw(20) << department.codeRoom << endl;
  cout << setw(20) << "Manager: " << setw(20) << department.manager << endl; 
  title();
  for (int i = 0; i < amountOfAssets; i++) {
    cout << setw(20) << assets[i].nameAsset;
    cout << setw(20) << assets[i].amount;
    cout << setw(20) << assets[i].status << endl;
    amountAssets += assets[i].amount;
  }
  cout << setw(20) << left << "Amount of assets: " << setw(20) << amountOfAssets;
  cout << setw(20) << left << "Sum amount: " << setw(20) << amountAssets << endl;
}

void fixAmountOfComputer(Coupon coupon) {
  for (int i = 0; i < coupon.amountOfAssets; i++) {
    if (strcmp(coupon.assets[i].nameAsset, "Personal computer") == 0 || strcmp(coupon.assets[i].nameAsset, "personal computer") == 0) {
      coupon.assets[i].amount = 20;
    }
  }
}

void insertAsset(Coupon &coupon, int pos) {
  Asset tempAsset;
  strcpy(tempAsset.nameAsset, "Laptop");
  tempAsset.amount = 10;
  strcpy(tempAsset.status, "Good");
  coupon.assets = (Asset*) realloc(coupon.assets, (coupon.amountOfAssets + 1)*sizeof(Asset));
  for (int i = coupon.amountOfAssets; i >= pos; i--) {
    coupon.assets[i] = coupon.assets[i-1];
  }
  coupon.amountOfAssets++;
  coupon.assets[pos-1] = tempAsset;
}

void sortAssetsByAmount(Coupon coupon) {
  for (int i = 0; i < coupon.amountOfAssets - 1; i++) {
    for (int j = i + 1; j < coupon.amountOfAssets; j++) {
      if (coupon.assets[i].amount > coupon.assets[j].amount) {
        swap(coupon.assets[i], coupon.assets[j]);
      }
    }
  }
}

main() {
  Coupon coupon;
  coupon.inputCoupon();
  cout << "--------------------------------------------" << endl;
  cout << "COMPLETE COUPON" << endl;
  coupon.showCoupon();
  fixAmountOfComputer(coupon);
  cout << "--------------------------------------------" << endl;
  cout << "COUPON AFTER FIX AMOUNT OF COMPUTER" << endl;
  coupon.showCoupon();
  insertAsset(coupon, 2);
  cout << "--------------------------------------------" << endl;
  cout << "COUPON AFTER INSERT ASSET" << endl;
  coupon.showCoupon();
  sortAssetsByAmount(coupon);
  cout << "--------------------------------------------" << endl;
  cout << "COUPON AFTER SORT BY AMOUNT OF ASSET" << endl;
  coupon.showCoupon();
}
