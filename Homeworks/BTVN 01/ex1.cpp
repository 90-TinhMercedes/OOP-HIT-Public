#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <math.h>
//#include <bits/stdc++.h>
using namespace std;

class HinhTron {
    public:
        double banKinh;
        // Cac phuong thuc (method):
        double chuVi(double banKinh);
        double dienTich(double banKinh);
};

double HinhTron::chuVi(double banKinh){
    double chuVi = 0;
    chuVi = 2 * M_PI * banKinh;
    return chuVi;

//    or
//    return 2 * M_PI * banKinh;
}

double HinhTron::dienTich(double banKinh){
    double dienTich = 1;
    dienTich = M_PI * banKinh * banKinh;
    return dienTich;

//    or
//    return M_PI * banKinh * banKinh;
}

main() {
    HinhTron hinhTron;
    double banKinh;
    cout << "Nhap thong tin hinh tron: " << endl;
    cout << "\tBan kinh: ";     cin >> banKinh;
    cout << "----------------------------------" << endl;
    cout << "Chu vi hinh tron: " << hinhTron.chuVi(banKinh) << endl;
    cout << "Dien tich hinh tron: " << hinhTron.dienTich(banKinh) << endl;
}
