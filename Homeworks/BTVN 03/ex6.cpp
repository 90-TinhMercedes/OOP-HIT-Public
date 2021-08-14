#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

class Math {
public:
	static int abs(int x);
	static int add(int x, int y);
	static int subtract(int x, int y);
	static int min(int x, int y);
	static int max(int x, int y);
	static int pow(int x, int y);
};

Math::abs(int x) {
    return x < 0 ? -x : x;
}

Math::add(int x, int y) {
    return x + y;
}

Math::subtract(int x, int y) {
    return x - y;
}

Math::min(int x, int y) {
    return x < y ? x : y;
}

Math::max(int x, int y) {
    return x < y ? y : x;
}

Math::pow(int x, int y) {
    int result = 1;
    for (int i=0; i<y; i++) {
        result *= x;
    }
    return result;
}

main() {
	cout << Math::abs(-5) << endl;
	cout << Math::add(3, 7) << endl;
	cout << Math::subtract(5, 2) << endl;
	cout << Math::min(4, 6) << endl;
	cout << Math::max(4, 6) << endl;
	cout << Math::pow(2, 4) << endl;
}













