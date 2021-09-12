#include <iostream>

using namespace std;

class Trinomial;

class Trinomial {
private:
    double a;
    double b;
    double c;
public:
    Trinomial() {};
    Trinomial(double a, double b, double c) {
      this->a = a;
      this->b = b;
      this->c = c;
    }
    friend istream& operator >> (istream& output, Trinomial &trinomial);
    friend ostream& operator << (ostream& output, Trinomial trinomial);
    Trinomial operator- ();
    Trinomial operator+ (Trinomial trinomial);
    Trinomial operator- (Trinomial trinomial);
};

istream& operator >> (istream& input, Trinomial &trinomial) {
  cout << "\ta: ";    input >> trinomial.a;
  cout << "\tb: ";    input >> trinomial.b;
  cout << "\tc: ";    input >> trinomial.c;
  return input;
}

ostream& operator << (ostream& output, Trinomial trinomial)
{
    output << trinomial.a << "x^2";
    if (trinomial.b >= 0) {
      output << " + " << trinomial.b << "x";
    } else {
      output << " - " << -trinomial.b << "x";
    }
    if (trinomial.c >= 0) {
      output << " + " << trinomial.c << endl;
    } else {
      output << " - " << -trinomial.c << endl;
    }
    return output;
}

Trinomial Trinomial::operator- () {
  this->a = -this->a;
  this->b = -this->b;
  this->c = -this->c;
  return *this;
}

Trinomial Trinomial::operator+ (Trinomial trinomial){
    Trinomial sum;
    sum.a = this->a + trinomial.a;
    sum.b = this->b + trinomial.b;
    sum.c = this->c + trinomial.c;
    return sum;
}

Trinomial Trinomial::operator- (Trinomial trinomial){
    Trinomial sub;
    sub.a = this->a - trinomial.a;
    sub.b = this->b - trinomial.b;
    sub.c = this->c - trinomial.c;
    return sub;
}

main() {
  Trinomial firstTrinomial, secondTrinomial;
  cout << "First trinomial: " << endl;
  cin >> firstTrinomial;
  cout << "Second trinomial: " << endl;
  cin >> secondTrinomial;
  firstTrinomial = -firstTrinomial;
  secondTrinomial = -secondTrinomial;
  cout << "First trinomial: " << firstTrinomial;
  cout << "Second trinomial: " << secondTrinomial;
  Trinomial sumTrinomial, subTrinomial;
  sumTrinomial = firstTrinomial + secondTrinomial;
  subTrinomial = firstTrinomial - secondTrinomial;
  cout << "Sum: " << sumTrinomial;
  cout << "Sub: " << subTrinomial;
}

