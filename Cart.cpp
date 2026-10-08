#include "Cart.h"

#include <iostream>
#include <iomanip>

using namespace std;

void Cart::addItem(MenuItem* item, int quantity) {

    items.push_back(
        CartItem(item, quantity)
    );
}

void Cart::showCart() const {

    if (items.empty()) {

        cout << "\n========== CART ==========\n";
        cout << "Cart is empty.\n";

        return;
    }

    cout << "\n========== CART ==========\n";

    for (int i = 0; i < items.size(); i++) {

        cout << "\n[" << i + 1 << "]";

        items[i].display();
    }

    cout << "\n--------------------------\n";

    cout << "TOTAL: Rp "
         << fixed << setprecision(0)
         << calculateTotal()
         << endl;
}

double Cart::calculateTotal() const {

    double total = 0;

    for (const auto& cartItem : items) {

        total += cartItem.getSubtotal();
    }

    return total;
}

bool Cart::isEmpty() const {
    return items.empty();
}

int Cart::getItemCount() const {
    return items.size();
}

void Cart::removeItem(int index) {

    if (
        index >= 0 &&
        index < items.size()
    ) {
        items.erase(
            items.begin() + index
        );
    }
}

void Cart::clearCart() {
    items.clear();
}

CartItem* Cart::getCartItem(int index) {

    if (
        index >= 0 &&
        index < items.size()
    ) {
        return &items[index];
    }

    return nullptr;
}

const vector<CartItem>& Cart::getItems() const {
    return items;
}