#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

class Provider {
private:
    char idPro[10];
    char namePro[30];
    char addressPro[30];
public:
    friend class Coupon;
};

class Product {
private:
    char nameProduct[30];
    double unitPrice;
    int amount;
    double price;
public:
    friend class Coupon;
};

class Coupon {
private:
    char idCoupon[10];
    char createAt[30];
    Provider provider;
    Product *product;
    int n;
public:
    void inputCoupon();
    void showCoupon();
};

void Coupon::inputCoupon() {
    cout << "Information of coupon: " << endl;
    cout << "\t\tID coupon: ";          fflush(stdin);      gets(idCoupon);
    cout << "\t\tCreate at: ";          fflush(stdin);      gets(createAt);
    cout << "\tInformation of provider: " << endl;
    cout << "\t\tID: ";                 fflush(stdin);      gets(provider.idPro);
    cout << "\t\tProvider: ";           fflush(stdin);      gets(provider.namePro);
    cout << "\t\tAddress: ";            fflush(stdin);      gets(provider.addressPro);
    cout << "\tAmount of products: ";   cin >> n;
    product = new Product[n];
    for(int i=0; i<n; i++) {
        cout << "\tProduct " << i+1 << ": " << endl;
        cout << "\t\tProduct: ";        fflush(stdin);      gets(product[i].nameProduct);
        cout << "\t\tUnit price: ";     cin >> product[i].unitPrice;
        cout << "\t\tAmount: ";         cin >> product[i].amount;
        product[i].price = product[i].amount * product[i].unitPrice;
    }
}

void titleTable() {
    cout << setw(20) << "Product";
    cout << setw(20) << "Unit price";
    cout << setw(20) << "Amount";
    cout << setw(20) << "Price" << endl;
}

void Coupon::showCoupon() {
    cout << "----------------------------------------------------------------------------------" << endl;
    cout << setw(45) << "IMPORT COUPON" << endl;
    cout << setw(20) << left << "ID coupon: " << setw(20) << idCoupon;
    cout << setw(20) << "Create at: " << setw(20) << createAt << endl;
    cout << setw(20) << left << "ID provider: " << setw(20) << provider.idPro;
    cout << setw(20) << "Provider: " << setw(20) << provider.namePro << endl;
    cout << setw(20) << "Address: " << setw(20) << provider.addressPro << endl;
    cout << "----------------------------------------------------------------------------------" << endl;
    titleTable();
    double total = 0;
    for(int i=0; i<n; i++) {
        cout << setw(20) << product[i].nameProduct;
        cout << setw(20) << product[i].unitPrice;
        cout << setw(20) << product[i].amount;
        cout << setw(20) << product[i].price << endl;
        total += product[i].price;
    }
    cout << setw(60) << "Total: " << setw(20) << total << endl;
}

main() {
    Coupon coupon;
    coupon.inputCoupon();
    coupon.showCoupon();
}
