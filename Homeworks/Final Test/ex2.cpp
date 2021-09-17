#include <iostream>

using namespace std;

class Array;

class Array {
private:
    double *arrays;
    int n;
public:
    Array() {
      this->n = 0;
      arrays = NULL;
    };
    ~Array() {
      this->n = 0;
      arrays = NULL;
    };
    friend istream& operator >> (istream& input, Array &array);
    friend ostream& operator << (ostream& output, Array array);
    Array operator- ();
    double operator+ ();
};

istream& operator >> (istream& input, Array &array) {
  cout << "\tAmout: ";    input >> array.n;
  array.arrays = new double[array.n];
  for (int i = 0; i < array.n; i++) {
    cout << "\t\ta[" << i + 1 << "] = ";
    cin >> array.arrays[i]; 
  }
  return input;
}

ostream& operator << (ostream& output, Array array) {
  for (int i = 0; i < array.n; i++) {
    output << array.arrays[i] << "  ";
  }
  return output;
}

Array Array::operator-() {
  for (int i = 0; i < this->n; i++) {
    if (this->arrays[i] > 5)
      this->arrays[i] = this->arrays[i] * -1;
  }
  return *this;
}

double Array::operator+() {
  double minTemp = arrays[0];
  double maxTemp = arrays[0];
  for (int i = 1; i < this->n; i++)
    minTemp = minTemp > arrays[i] ? arrays[i] : minTemp;
  for (int i = 1; i < this->n; i++)
    maxTemp = maxTemp < arrays[i] ? arrays[i] : maxTemp;
  return (minTemp + maxTemp) * 0.5;
}

main() {
  Array firstArray, secondArray;
  cout << "First array: " << endl;
  cin >> firstArray;
  cout << "Second array: " << endl;
  cin >> secondArray;
  cout << "First array: " << firstArray << endl;
  cout << "Second array: " << secondArray << endl;
  -firstArray;
  -secondArray;
  cout << "First array (after): " << firstArray << endl;
  cout << "Second array (after): " << secondArray << endl;
  cout << "Average min & max of first array: " << +firstArray << endl;
  cout << "Average min & max of second array: " << +secondArray << endl;
}

