#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

class Electronic {
    protected:
        double wattage;
        double voltage;
    public:
        Electronic(double wattage, double voltage) {
            this->wattage = wattage;
            this->voltage = voltage;
        }
};

class Fridge : public Electronic {
    private:
        double capacity;
        int slot;
    public:
        Fridge(double wattage, double voltage, double capacity, int slot) : Electronic(wattage, voltage) {
            this->capacity = capacity;
            this->slot = slot;
        }
        void output();
};

class WashingMachine : public Electronic {
    private:
        double capacity;
        char type[30];
    public:
        WashingMachine(double wattage, double voltage, double capacity, char type[]) : Electronic(wattage, voltage) {
            this->capacity = capacity;
            strcpy(this->type, type);
        }
        void output();
};

void Fridge::output() {
    cout << "\tWattage: " << wattage << " W" << endl;
    cout << "\tVoltage: " << voltage << " V" << endl;
    cout << "\tCapacity: " << capacity << " liters" << endl;
    cout << "\tSLot: " << slot << endl;
}

void WashingMachine::output() {
    cout << "\tWattage: " << wattage << " W" << endl;
    cout << "\tVoltage: " << voltage << " V" << endl;
    cout << "\tCapacity: " << capacity << " Kg" << endl;
    cout << "\tType: " << type << endl;
}

main() {
    Fridge fridge(150, 220, 200, 2);
    WashingMachine washingMachine(1000, 220, 7, "front load");
    cout << "-------------------------------------" << endl;
    cout << "FRIDGE'S INFORMATION" << endl;
    fridge.output();
    cout << "-------------------------------------" << endl;
    cout << "WASHING MACHINE'S INFORMATION" << endl;
    washingMachine.output();
}

