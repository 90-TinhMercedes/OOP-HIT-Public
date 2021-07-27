#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

class SinhVien {
    public:
        char maSinhVien[30];
        char hoTen[30];
        int ngay, thang, nam;
        char gioiTinh[30];
        double diemTrungBinh;
        char xepLoaiDaoDuc[30];
        // Cac phuong thuc: (method)
        void nhapThongTin();
        void xuatThongTin();
};

void SinhVien::nhapThongTin() {
    cout << "\tMa sinh vien: ";         fflush(stdin);      gets(maSinhVien);
    cout << "\tHo ten: ";               fflush(stdin);      gets(hoTen);
    cout << "\tNgay sinh (dd/mm/yyyy): ";         cin >> ngay >> thang >> nam;
    cout << "\tGioi tinh: ";            fflush(stdin);      gets(gioiTinh);
    cout << "\tDiem trung binh: ";      cin >> diemTrungBinh;
    cout << "\tXep loai dao duc: ";     fflush(stdin);      gets(xepLoaiDaoDuc);
}

void SinhVien::xuatThongTin() {
    cout << "\tMa sinh vien: " << maSinhVien << endl;
    cout << "\tHo ten: " << hoTen << endl;
    cout << "\tNgay sinh: " << ngay << "/" << thang << "/" << nam << endl;
    cout << "\tGioi tinh: " << gioiTinh << endl;
    cout << "\tDiem trung binh: " << diemTrungBinh << endl;
    cout << "\tXep loai dao duc: " << xepLoaiDaoDuc << endl;
}

void hoanDoiThongTinSinhVien(SinhVien sinhVienDiemCao, SinhVien sinhVienDiemThap) {
    if (sinhVienDiemCao.diemTrungBinh < sinhVienDiemThap.diemTrungBinh) {
        SinhVien sinhVien = sinhVienDiemCao;
        sinhVienDiemCao = sinhVienDiemThap;
        sinhVienDiemThap = sinhVien;
//        or
//        swap(sinhVienDiemCao, sinhVienDiemThap);
    }
    cout << "---------------------------------" << endl;
    cout << "THONG TIN SAU KHI HOAN DOI" << endl;
    cout << "Sinh vien diem cao: " << endl;
    sinhVienDiemCao.xuatThongTin();
    cout << "Sinh vien diem thap: " << endl;
    sinhVienDiemThap.xuatThongTin();
}

main() {
    SinhVien sinhVienDiemCao, sinhVienDiemThap;
    cout << "Nhap thong tin sinh vien diem cao: " << endl;
    sinhVienDiemCao.nhapThongTin();
    cout << "Nhap thong tin sinh vien diem thap: " << endl;
    sinhVienDiemThap.nhapThongTin();
    cout << "---------------------------------" << endl;
    cout << "THONG TIN SINH VIEN" << endl;
    sinhVienDiemCao.xuatThongTin();
    cout << "---------------------------------" << endl;
    sinhVienDiemThap.xuatThongTin();
    hoanDoiThongTinSinhVien(sinhVienDiemCao, sinhVienDiemThap);
}






















