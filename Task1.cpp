#include <iostream>
#include <string>
using namespace std;
class Vehicle {
protected:
    string plateNumber;

public:
    Vehicle(string plate) {
        plateNumber = plate;
    }
double toll() {
        return 0.0;
    }
void showInfo() {
        cout << "Plate: " << plateNumber << endl;
    }
};
class Car : public Vehicle {
public:
    Car(string plate) : Vehicle(plate) {}
    double toll() {
        return 100.0;
    }
void showInfo() {
        cout << "Car | Plate: " << plateNumber << " | Toll: Rs. " << toll() << endl;
    }
};
class Bus : public Vehicle {
public:
    Bus(string plate) : Vehicle(plate) {}

    double toll() {
        return 250.0;
    }
void showInfo() {
        cout << "Bus | Plate: " << plateNumber << " | Toll: Rs. " << toll() << endl;
    }
};
class Truck : public Vehicle {
private:
    int axles;

public:
    Truck(string plate, int ax) : Vehicle(plate) {
        axles = (ax < 1) ? 1 : ax;
    }
double toll() {
        return 300.0 + (axles - 1) * 100.0;
    }
void showInfo() {
        cout << "Truck | Plate: " << plateNumber << " | Axles: " << axles << " | Toll: Rs. " << toll() << endl;
    }
};
int main() {
    Car c1("LEA-1234");
    Bus b1("KHI-555");
    Truck t1("ISB-909", 3);
    Car c2("RWP-77");
    c1.showInfo();
    b1.showInfo();
    t1.showInfo();
    c2.showInfo();
    double totalToll = c1.toll() + b1.toll() + t1.toll() + c2.toll();
    cout << "-------------------------" << endl;
    cout << "Total Toll Collected: Rs. " << totalToll << endl;
    return 0;
}