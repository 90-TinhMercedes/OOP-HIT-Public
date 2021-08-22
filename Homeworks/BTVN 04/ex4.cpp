#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

class Coupon;

class Address {
private:
    int number;
    char lane[10];
    char quarter[30];
    char ward[30];
    char district[30];
    char city[30];
public:
    void inputAddress();
    void showAddress();
};

class Persion {
private:
    char fullName[30];
    char phoneNumber[30];
    Address address;
public:
    void inputPersion();
    void showPersion();
};

class Product {
private:
    char nameProduct[30];
    double unitPrice;
    int amount;
    double price;
public:
    void inputProduct();
    void showProduct();
    friend class Coupon;
};

class Coupon {
private:
    char idCoupon[10];
    char date[30];
    Persion persion;
    Product *product;
    int n;
public:
    void inputCoupon();
    void showCoupon();
};

void Address::inputAddress() {
    cout << "\tAddress: " << endl;
    cout << "\t\tApartment number: ";           cin >> number;
    cout << "\t\tLane: ";                       fflush(stdin);      gets(lane);
    cout << "\t\tQuarter: ";                    fflush(stdin);      gets(quarter);
    cout << "\t\tWard: ";                       fflush(stdin);      gets(ward);
    cout << "\t\tDistrict: ";                   fflush(stdin);      gets(district);
    cout << "\t\tCity: ";                       fflush(stdin);      gets(city);
}

void Address::showAddress() {
    cout << "No. " << number << ", " << lane << " lane, " << quarter << " quarter, " << ward << " ward, "
    << district << " district, " << city << endl;
}

void Persion::inputPersion() {
    cout << "\t\tFull name: ";                  fflush(stdin);      gets(fullName);
    cout << "\t\tPhone number: ";               fflush(stdin);      gets(phoneNumber);
    address.inputAddress();
}

void Persion::showPersion() {
    cout << setw(20) << left << "Full name: " << setw(20) << fullName << endl;
    cout << setw(20) << left << "Phone number: " << setw(20) << phoneNumber << endl;
    cout << setw(20) << left << "Address: ";
    address.showAddress();
}

void Product::inputProduct() {
    cout << "\t\tProduct: ";        fflush(stdin);      gets(nameProduct);
    cout << "\t\tUnit price: ";     cin >> unitPrice;
    cout << "\t\tAmount: ";         cin >> amount;
    price = amount * unitPrice;
}

void Product::showProduct() {
    cout << setw(20) << nameProduct;
    cout << setw(20) << unitPrice;
    cout << setw(20) << amount;
    cout << setw(20) << price << endl;
}


void Coupon::inputCoupon() {
    cout << "Information of coupon: " << endl;
    cout << "\t\tID coupon: ";          fflush(stdin);      gets(idCoupon);
    cout << "\t\tDate: ";          fflush(stdin);      gets(date);
    cout << "\tPersion's information: " << endl;
    persion.inputPersion();
    cout << "\tAmount of products: ";   cin >> n;
    product = new Product[n];
    for(int i=0; i<n; i++) {
        cout << "\tProduct " << i+1 << ": " << endl;
        product[i].inputProduct();
    }
}

void titleTable() {
    cout << setw(20) << "Product";
    cout << setw(20) << "Unit price";
    cout << setw(20) << "Amount";
    cout << setw(20) << "Price" << endl;
}

void Coupon::showCoupon() {
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(45) << "MARKET COUPON" << endl;
    cout << setw(20) << left << "ID coupon: " << setw(20) << idCoupon;
    cout << setw(20) << "Date: " << setw(20) << date << endl;
    persion.showPersion();
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    titleTable();
    double total = 0;
    for(int i=0; i<n; i++) {
        product[i].showProduct();
        total += product[i].price;
    }
    cout << setw(60) << "Total: " << setw(20) << total << endl;
}

main() {
    Coupon coupon;
    coupon.inputCoupon();
    coupon.showCoupon();
}
