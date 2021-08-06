#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

class PhanSo {
private:
    double tuSo;
    double mauSo;
public:
    PhanSo();
    PhanSo(double tuSoNew, double mauSoNew);
    ~PhanSo();
    void nhap();
    void xuat();
    void rutGon();
};

PhanSo::PhanSo() {
    tuSo = 0;
    mauSo = 1;
}

PhanSo::PhanSo(double tuSoNew, double mauSoNew) {
    tuSo = tuSoNew;
    mauSo = mauSoNew;
}

PhanSo::~PhanSo() {
    tuSo = 0;
    mauSo = 1;
}

void PhanSo::nhap() {
    cout << "\tTu so: ";
    cin >> tuSo;
    cout << "\tMau so: ";
    cin >> mauSo;
}

void PhanSo::xuat() {
    cout << tuSo << "/" << mauSo << endl;
}

int uocChungLonNhat(int a, int b) {
    if (a % b == 0)
        return b;
    return uocChungLonNhat(b, a%b);
}

void PhanSo::rutGon() {
    int uoc = uocChungLonNhat(tuSo, mauSo);
    cout << tuSo / uoc << "/" << mauSo / uoc << endl;
}

main() {
    PhanSo P(6, 11);
    PhanSo Q;
    cout << "Nhap phan so Q: " << endl;
    Q.nhap();
    cout << "-----------------------------------" << endl;
    cout << "Phan so P: ";
    P.xuat();
    cout << "Phan so Q: ";
    Q.xuat();
    cout << "Phan so Q sau khi rut gon: ";
    Q.rutGon();
    cout << "-----------------------------------" << endl;
}
