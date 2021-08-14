#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

class Manufacturer {
private:
    char idMan[30];
    char nameMan[30];
    char addressMan[30];
public:
    void inputManufacturer();
    void showManufacture();
};

class Product {
private:
    char idProduct[30];
    char nameProduct[30];
    Manufacturer manufacturer;
public:
    void inputProduct();
    void showProduct();
};

void Manufacturer::inputManufacturer() {
    cout << "\tManufacturer's information: " << endl;
    cout << "\tID: ";               fflush(stdin);      gets(idMan);
    cout << "\tManufacturer: ";     fflush(stdin);      gets(nameMan);
    cout << "\tAddress: ";          fflush(stdin);      gets(addressMan);
}

void Manufacturer::showManufacture() {
    cout << "\tID manufacturer: " << idMan << endl;
    cout << "\tManufacturer: " << nameMan << endl;
    cout << "\tAddress manufacturer: " << addressMan << endl;
}

void Product::inputProduct() {
    cout << "\tID product: ";       fflush(stdin);      gets(idProduct);
    cout << "\tProduct: ";          fflush(stdin);      gets(nameProduct);
    manufacturer.inputManufacturer();
}

void Product::showProduct() {
    cout << "\tID product: " << idProduct << endl;
    cout << "\tProduct: " << nameProduct << endl;
    manufacturer.showManufacture();
}

main() {
    int n;
    cout << "Enter amount of products: ";
    cin >> n;
    Product *products;
    products = new Product[n];
    for (int i=0; i<n; i++) {
        cout << "Enter information product " << i+1 << ": " << endl;
        products[i].inputProduct();
    }
    cout << "----------------------------------" << endl;
    cout << "INFORMATION PRODUCTS: " << endl;
    for (int i=0; i<n; i++) {
        cout << "PRODUCT " << i+1 << ": " << endl;
        products[i].showProduct();
    }
    cout << "----------------------------------" << endl;
}
