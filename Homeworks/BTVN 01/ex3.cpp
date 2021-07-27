#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

class CanBo {
    public:
        char maCanBo[30];
        char hoTen[30];
        char ngaySinh[30];
        int soNgayLam;
        // Cac phuong thuc (method):
        void nhap();
        void xuat();
        int tinhLuong();
};

void CanBo::nhap() {
    cout << "Nhap thong tin can bo: " << endl;
    cout << "\tMa can bo: ";        fflush(stdin);      gets(maCanBo);
    cout << "\tHo ten: ";           fflush(stdin);      gets(hoTen);
    cout << "\tNgay sinh: ";        fflush(stdin);      gets(ngaySinh);
    cout << "\tSo ngay lam: ";      cin >> soNgayLam;
}

int CanBo::tinhLuong() {
    return soNgayLam * 250000;
}

void CanBo::xuat() {
    cout << "---------------------------" << endl;
    cout << "THONG TIN CAN BO" << endl;
    cout << "\tMa can bo: " << maCanBo << endl;
    cout << "\tHo ten: " << hoTen << endl;
    cout << "\tNgay sinh: " << ngaySinh << endl;
    cout << "\tSo ngay lam: " << soNgayLam << endl;
    cout << "\tLuong: " << tinhLuong() << endl;
}

main() {
    CanBo canBo;
    canBo.nhap();
    canBo.xuat();
}
