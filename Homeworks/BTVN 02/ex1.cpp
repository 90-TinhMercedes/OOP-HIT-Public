#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <math.h>
//#include <bits/stdc++.h>
using namespace std;

class PhuongTrinhBacHai {
private:
    double a;
    double b;
    double c;
public:
    PhuongTrinhBacHai();
    PhuongTrinhBacHai(double aNew, double bNew, double cNew);
    void nhap();
    void xuat();
    void giai();
    ~PhuongTrinhBacHai();
};

PhuongTrinhBacHai::PhuongTrinhBacHai() {
    a = 0;
    b = 0;
    c = 0;
}

PhuongTrinhBacHai::PhuongTrinhBacHai(double aNew, double bNew, double cNew) {
    a = aNew;
    b = bNew;
    c = cNew;
}

PhuongTrinhBacHai::~PhuongTrinhBacHai() {
    a = 0;
    b = 0;
    c = 0;
}

void PhuongTrinhBacHai::nhap() {
    cout << "\tNhap he so a, b, c: ";
    cin >> a >> b >> c;
}

void PhuongTrinhBacHai::xuat() {
    cout << a << "x2 ";
    if (b > 0)
        cout << "+ " << b << "x ";
    else
        cout << b << "x ";
    if (c > 0)
        cout << "+ " << c << endl;
    else
        cout << c << endl;
}

void PhuongTrinhBacHai::giai() {
    double delta = (b * b) - 4 * a * c;
    double x1, x2;
    if (a == 0) {
    	cout << "Khong phai phuong trinh bac hai." << endl;
	} else if (delta == 0) {
        x1 = -b / (2 * a);
        cout << "Phuong trinh co nghiem kep: x1 = x2 = " << x1 << endl;
    } else if (delta > 0) {
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
        cout << "Phuong trinh co hai nghiem phan biet: " << endl;
        cout << "\tx1 = " << x1 << endl;
        cout << "\tx2 = " << x2 << endl;
    } else {
        cout << "Phuong trinh vo nghiem" << endl;
    }
}

main() {
    PhuongTrinhBacHai P(3, 2, -5);
    PhuongTrinhBacHai Q;
    cout << "Nhap phuong trinh Q: " << endl;
    Q.nhap();
    cout << "-----------------------------------" << endl;
    cout << "Phuong trinh P: ";
    P.xuat();
    cout << "Phuong trinh Q: ";
    Q.xuat();
    cout << "Giai phuong trinh P: " << endl;
    P.giai();
    cout << "Giai phuong trinh Q: " << endl;
    Q.giai();
    cout << "-----------------------------------" << endl;
}
