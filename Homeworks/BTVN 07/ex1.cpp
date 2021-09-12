#include <iostream>

using namespace std;

class ComplexNumber;

class ComplexNumber {
private:
    double realComponent;
    double virtualComponent;
public:
    ComplexNumber() {};
    ComplexNumber(double realComponent, double virtualComponent) {
        this->realComponent = realComponent;
        this->virtualComponent = virtualComponent;
    }
    friend ostream& operator << (ostream& output, ComplexNumber complexNumber);
    ComplexNumber operator+ (ComplexNumber complexNumber);
    ComplexNumber operator- (ComplexNumber complexNumber);
};
ostream& operator << (ostream& output, ComplexNumber complexNumber)
{
    output << complexNumber.realComponent;
    if (complexNumber.virtualComponent >= 0) {
      output << " + " << complexNumber.virtualComponent << "i" << endl;
    } else {
      output << " - " << -complexNumber.virtualComponent << "i" << endl;
    }
    return output;
}

ComplexNumber ComplexNumber::operator+ (ComplexNumber complexNumber){
    ComplexNumber sum;
    sum.realComponent = this->realComponent + complexNumber.realComponent;
    sum.virtualComponent = this->virtualComponent + complexNumber.virtualComponent;
    return sum;
}

ComplexNumber ComplexNumber::operator- (ComplexNumber complexNumber){
    ComplexNumber sub;
    sub.realComponent = this->realComponent - complexNumber.realComponent;
    sub.virtualComponent = this->virtualComponent - complexNumber.virtualComponent;
    return sub;
}

main() {
  double realTemp, virtualTemp;
  ComplexNumber sumCN, subCN;
  cout << "First complex number: " << endl;
  cout << "\tReal: ";     cin >> realTemp;
  cout << "\tVirtual: ";  cin >> virtualTemp;
  ComplexNumber firstCN(realTemp, virtualTemp);
  cout << "Second complex number: " << endl;
  cout << "\tReal: ";     cin >> realTemp;
  cout << "\tVirtual: ";  cin >> virtualTemp;
  ComplexNumber secondCN(realTemp, virtualTemp);
  cout << "First complex number: " << firstCN;
  cout << "Second complex number: " << secondCN;
  sumCN = firstCN + secondCN;
  subCN = firstCN - secondCN;
  cout << "Sum: " << sumCN;
  cout << "Sub: " << subCN;
}

