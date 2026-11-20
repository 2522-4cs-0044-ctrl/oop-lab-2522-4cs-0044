#include <iostream>
using namespace std;
class Payment {
public:
    virtual double calculateFee() = 0;
};
class BankTransfer : public Payment {
private:
    double amount;
public:
    BankTransfer(double amt) {
        amount = amt;
    }
double calculateFee() {
        return (amount * 2) / 100.0;
    }
};
class DigitalWallet : public Payment {
private:
    double amount;
public:
    DigitalWallet(double amt) {
        amount = amt;
    }

    double calculateFee() {
        return (amount * 1) / 100.0;
    }
};

int main() {
    BankTransfer bt(10000);
    DigitalWallet dw(10000);

    cout << "Bank Transfer Fee: " << bt.calculateFee() << endl;
    cout << "Digital Wallet Fee: " << dw.calculateFee() << endl;

    return 0;
}