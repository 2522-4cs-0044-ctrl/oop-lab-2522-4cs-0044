#include <iostream>
using namespace std;

class Fraction {
private:
    int num;
    int den;

    int getGCD(int a, int b) {
        if (a < 0) a = -a;
        if (b < 0) b = -b;
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void simplify() {
        if (den == 0) {
            den = 1;
        }
        if (den < 0) {
            num = -num;
            den = -den;
        }
        if (num == 0) {
            den = 1;
            return;
        }
        int g = getGCD(num, den);
        if (g > 1) {
            num = num / g;
            den = den / g;
        }
    }

public:
    Fraction(int n = 0, int d = 1) {
        if (d == 0) {
            d = 1;
        }
        num = n;
        den = d;
        simplify();
    }

    // Member arithmetic operators: +, -, *
    Fraction operator+(Fraction other) {
        int n = num * other.den + other.num * den;
        int d = den * other.den;
        return Fraction(n, d);
    }

    Fraction operator-(Fraction other) {
        int n = num * other.den - other.num * den;
        int d = den * other.den;
        return Fraction(n, d);
    }

    Fraction operator*(Fraction other) {
        int n = num * other.num;
        int d = den * other.den;
        return Fraction(n, d);
    }

    // Comparison operators: == and <
    bool operator==(Fraction other) {
        return (num * other.den) == (other.num * den);
    }

    bool operator<(Fraction other) {
        return (num * other.den) < (other.num * den);
    }

    // Prefix ++ (adds 1, e.g., 1/2 -> 3/2)
    Fraction& operator++() {
        num = num + den;
        simplify();
        return *this;
    }

    // Friend stream operators: << and >>
    friend ostream& operator<<(ostream& out, Fraction f) {
        out << f.num << "/" << f.den;
        return out;
    }

    friend istream& operator>>(istream& in, Fraction& f) {
        int n, d;
        in >> n >> d;
        f = Fraction(n, d);
        return in;
    }
};

int main() {
    Fraction a(1, 2);
    Fraction b(3, 4);

    cout << a << " + " << b << " = " << (a + b) << endl;
    cout << a << " - " << b << " = " << (a - b) << endl;
    cout << a << " * " << b << " = " << (a * b) << endl;

    Fraction halfCheck(2, 4);
    if (halfCheck == Fraction(1, 2)) {
        cout << "2/4 is equal to 1/2" << endl;
    }

    if (a < b) {
        cout << a << " is less than " << b << endl;
    }

    ++a;
    cout << "After ++a: " << a << endl;

    Fraction userFrac;
    cout << "Enter numerator and denominator: ";
    cin >> userFrac;
    cout << "You entered " << userFrac << endl;

    return 0;
}