#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

class Hang {
private:
    char maHang[30];
    char tenHang[30];
    char ngayNhap[30];
    char ngaySanXuat[30];
    double donGia;
    int soLuong;
public:
    Hang();
    Hang(char maHangNew[], char tenHangNew[], char ngayNhapNew[], char ngaySanXuatNew[], double donGiaNew, int soLuongNew);
    ~Hang();
    void nhap();
    void xuat();
};

Hang::Hang() {
    strcpy(maHang, "");
    strcpy(tenHang, "");
    strcpy(ngayNhap, "");
    strcpy(ngaySanXuat, "");
    donGia = 0.0;
    soLuong = 0;
}

Hang::Hang(char maHangNew[], char tenHangNew[], char ngayNhapNew[], char ngaySanXuatNew[], double donGiaNew, int soLuongNew) {
    strcpy(maHang, maHangNew);
    strcpy(tenHang, tenHangNew);
    strcpy(ngayNhap, ngayNhapNew);
    strcpy(ngaySanXuat, ngaySanXuatNew);
    donGia = donGiaNew;
    soLuong = soLuongNew;
}

Hang::~Hang() {
    strcpy(maHang, "");
    strcpy(tenHang, "");
    strcpy(ngayNhap, "");
    strcpy(ngaySanXuat, "");
    donGia = 0.0;
    soLuong = 0;
}

void Hang::nhap() {
    cout << "\tMa hang: ";              fflush(stdin);      gets(maHang);
    cout << "\tTen hang: ";             fflush(stdin);      gets(tenHang);
    cout << "\tNgay nhap: ";            fflush(stdin);      gets(ngayNhap);
    cout << "\tNgay san xuat: ";        fflush(stdin);      gets(ngaySanXuat);
    cout << "\tDon gia: ";              cin >> donGia;
    cout << "\tSo luong: ";             cin >> soLuong;
}

void Hang::xuat() {
    cout << "\tMa hang: " << maHang << endl;
    cout << "\tTen hang: " << tenHang << endl;
    cout << "\tNgay nhap: " << ngayNhap << endl;
    cout << "\tNgay san xuat: " << ngaySanXuat << endl;
    cout << "\tDon gia: " << donGia << endl;
    cout << "\tSo luong: " << soLuong << endl;
    cout << "\tThanh tien: " << soLuong * donGia << endl;
}

main() {
    Hang P;
    Hang Q("GPU", "AORUS RTX 3080 Ti 12GB", "25/07/2021", "10/07/2021", 48999000.0, 5);
    cout << "Nhap thong tin mat hang P: " << endl;
    P.nhap();
    cout << "-----------------------------------" << endl;
    cout << "Thong tin mat hang P: " << endl;
    P.xuat();
    cout << "Thong tin mat hang Q: " << endl;
    Q.xuat();
    cout << "-----------------------------------" << endl;
}
