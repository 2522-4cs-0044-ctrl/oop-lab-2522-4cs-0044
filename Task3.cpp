#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class CartItem {
private:
    string name;
    double price;
    int quantity;

public:
    CartItem(string n, double p, int q) : name(n), price(p), quantity(q) {
        if (price < 0) price = 0;
        if (quantity < 1) quantity = 1;
    }

    string getName() const { return name; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }

    void setQuantity(int q) {
        if (q >= 0) quantity = q;
    }

    double getSubtotal() const {
        return price * quantity;
    }

    void display() const {
        cout << left << setw(20) << name
             << " | Price: Rs. " << setw(8) << fixed << setprecision(2) << price
             << " | Qty: " << setw(3) << quantity
             << " | Subtotal: Rs. " << getSubtotal() << endl;
    }
};

class ShoppingCart {
private:
    vector<CartItem> items;
    double discountPercent;

public:
    ShoppingCart() : discountPercent(0.0) {}

    void addItem(string name, double price, int quantity) {
        for (auto& item : items) {
            if (item.getName() == name) {
                item.setQuantity(item.getQuantity() + quantity);
                cout << "Updated quantity for '" << name << "'." << endl;
                return;
            }
        }
        items.push_back(CartItem(name, price, quantity));
        cout << "Added '" << name << "' to cart." << endl;
    }

    void removeItem(string name) {
        for (size_t i = 0; i < items.size(); i++) {
            if (items[i].getName() == name) {
                items.erase(items.begin() + i);
                cout << "Removed '" << name << "' from cart." << endl;
                return;
            }
        }
        cout << "Item '" << name << "' not found in cart." << endl;
    }

    void applyDiscount(double percent) {
        if (percent >= 0 && percent <= 100) {
            discountPercent = percent;
            cout << "Applied " << discountPercent << "% discount." << endl;
        } else {
            cout << "Invalid discount percentage!" << endl;
        }
    }

    double getTotal() const {
        double sum = 0.0;
        for (const auto& item : items) {
            sum += item.getSubtotal();
        }
        double discountAmount = (sum * discountPercent) / 100.0;
        return sum - discountAmount;
    }

    void showCart() const {
        cout << "\n--- Shopping Cart ---" << endl;
        if (items.empty()) {
            cout << "Cart is empty." << endl;
        } else {
            for (const auto& item : items) {
                item.display();
            }
            cout << "---------------------" << endl;
            cout << "Discount: " << discountPercent << "%" << endl;
            cout << "Final Total: Rs. " << fixed << setprecision(2) << getTotal() << endl;
        }
        cout << "---------------------\n" << endl;
    }
};

int main() {
    ShoppingCart cart;

    cart.addItem("USB Cable", 450.0, 2);
    cart.addItem("Wireless Mouse", 1850.0, 1);
    cart.addItem("USB Cable", 450.0, 1); // Merges quantity -> 3
    cart.applyDiscount(10.0);
    cart.showCart();

    cart.removeItem("USB Cable");
    cart.showCart();

    return 0;
}