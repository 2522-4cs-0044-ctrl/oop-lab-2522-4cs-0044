#include <iostream>
#include <numeric>
using namespace std;

class Fraction {
private:
    int num;
    int den;

    void simplify() {
        if (den < 0) {
            num = -num;
            den = -den;
        }
        int g = gcd(abs(num), abs(den));
        if (g > 0) {
            num /= g;
            den /= g;
        }
    }

public:
    Fraction(int n = 0, int d = 1) {
        if (d == 0) {
            cout << "Error: Denominator cannot be zero! Setting denominator to 1." << endl;
            d = 1;
        }
        num = n;
        den = d;
        simplify();
    }

    Fraction operator+(const Fraction& other) const {
        return Fraction(num * other.den + other.num * den, den * other.den);
    }

    Fraction operator-(const Fraction& other) const {
        return Fraction(num * other.den - other.num * den, den * other.den);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(num * other.num, den * other.den);
    }

    Fraction operator/(const Fraction& other) const {
        if (other.num == 0) {
            cout << "Error: Division by zero fraction!" << endl;
            return Fraction(0, 1);
        }
        return Fraction(num * other.den, den * other.num);
    }
    bool operator==(const Fraction& other) const {
        return (num == other.num && den == other.den);
    }

    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }

    bool operator<(const Fraction& other) const {
        return (num * other.den) < (other.num * den);
    }

    bool operator>(const Fraction& other) const {
        return (num * other.den) > (other.num * den);
    }

    friend ostream& operator<<(ostream& out, const Fraction& f) {
        if (f.den == 1)
            out << f.num;
        else
            out << f.num << "/" << f.den;
        return out;
    }

    friend istream& operator>>(istream& in, Fraction& f) {
        char slash;
        in >> f.num >> slash >> f.den;
        if (f.den == 0) {
            cout << "Denominator cannot be zero! Setting to 1." << endl;
            f.den = 1;
        }
        f.simplify();
        return in;
    }
};

int main() {
    Fraction f1(2, 4);   
    Fraction f2(3, 4);

    cout << "f1 = " << f1 << endl;
    cout << "f2 = " << f2 << endl;

    cout << "f1 + f2 = " << (f1 + f2) << endl;
    cout << "f1 - f2 = " << (f1 - f2) << endl;
    cout << "f1 * f2 = " << (f1 * f2) << endl;
    cout << "f1 / f2 = " << (f1 / f2) << endl;

    if (f1 == Fraction(1, 2))
        cout << "f1 is equal to 1/2" << endl;

    if (f1 < f2)
        cout << "f1 is less than f2" << endl;

    Fraction f3;
    cout << "Enter a fraction (e.g., 3/5): ";
    cin >> f3;
    cout << "Simplified fraction: " << f3 << endl;

    return 0;
}