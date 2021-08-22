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
    char hotline[30];
public:
    friend class Coupon;
};

class Product {
private:
    char id[10];
    char nameProduct[30];
    char status[30];
    int amount;
    double unitPrice;
    double price;
public:
    friend class Coupon;
};

class Coupon {
private:
    char idCoupon[10];
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
    cout << "\tInformation of provider: " << endl;
    cout << "\t\tID: ";                 fflush(stdin);      gets(provider.idPro);
    cout << "\t\tProvider: ";           fflush(stdin);      gets(provider.namePro);
    cout << "\t\tAddress: ";            fflush(stdin);      gets(provider.addressPro);
    cout << "\t\tHotline: ";            fflush(stdin);      gets(provider.hotline);
    cout << "\tAmount of products: ";   cin >> n;
    product = new Product[n];
    for(int i=0; i<n; i++) {
        cout << "\tProduct " << i+1 << ": " << endl;
        cout << "\t\tID: ";             fflush(stdin);      gets(product[i].id);
        cout << "\t\tProduct: ";        fflush(stdin);      gets(product[i].nameProduct);
        cout << "\t\tStatus: ";         fflush(stdin);      gets(product[i].status);
        cout << "\t\tAmount: ";         cin >> product[i].amount;
        cout << "\t\tUnit price: ";     cin >> product[i].unitPrice;
        product[i].price = product[i].amount * product[i].unitPrice;
    }
}

void titleTable() {
    cout << setw(15) << "ID";
    cout << setw(15) << "Product";
    cout << setw(15) << "Status";
    cout << setw(15) << "Amount";
    cout << setw(15) << "Unit price";
    cout << setw(15) << "Price" << endl;
}

void Coupon::showCoupon() {
    cout << "----------------------------------------------------------------------------------" << endl;
    cout << setw(45) << "IMPORT COUPON EQUIPMENT OF COMPUTER" << endl;
    cout << setw(20) << left << "ID coupon: " << setw(20) << idCoupon << endl;
    cout << setw(20) << left << "ID provider: " << setw(20) << provider.idPro;
    cout << setw(20) << "Provider: " << setw(20) << provider.namePro << endl;
    cout << setw(20) << left << "Address: " << setw(20) << provider.addressPro;
    cout << setw(20) << "Hotline: " << setw(20) << provider.hotline << endl;
    cout << "----------------------------------------------------------------------------------" << endl;
    titleTable();
    double total = 0;
    int sumAmount = n;
    for(int i=0; i<n; i++) {
        cout << setw(15) << product[i].id;
        cout << setw(15) << product[i].nameProduct;
        cout << setw(15) << product[i].status;
        cout << setw(15) << product[i].amount;
        cout << setw(15) << product[i].unitPrice;
        cout << setw(15) << product[i].price << endl;
        total += product[i].price;
    }
    cout << "----------------------------------------------------------------------------------" << endl;
    cout << setw(20) << left << "Amount of products: " << setw(20) << sumAmount;
    cout << setw(20) << "Total: " << setw(20) << total << endl;
}

main() {
    Coupon coupon;
    coupon.inputCoupon();
    coupon.showCoupon();
}
