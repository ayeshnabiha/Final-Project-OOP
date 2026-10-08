#include "Order.h"

#include <iostream>
#include <iomanip>

using namespace std;

int Order::nextOrderId = 1;

Order::Order() {

    orderId = nextOrderId++;

    status = "PENDING";
}

int Order::getOrderId() const {
    return orderId;
}

void Order::setCustomer(const Customer& customer) {

    this->customer = customer;
}

Customer Order::getCustomer() const {
    return customer;
}

Cart& Order::getCart() {
    return cart;
}

void Order::setStatus(string status) {
    this->status = status;
}

string Order::getStatus() const {
    return status;
}

bool Order::processPayment() {

    if (cart.isEmpty()) {

        cout << "\nCart is empty.\n";

        return false;
    }

    bool success =
        payment.processPayment(
            cart.calculateTotal()
        );

    if (success) {

        status = "PAID";

        return true;
    }

    return false;
}

void Order::printReceipt() const {

    cout << "\n";
    cout << "====================================\n";
    cout << "             FOYE JAKAL             \n";
    cout << "              RECEIPT               \n";
    cout << "====================================\n";

    cout << "Order ID : #"
         << orderId
         << "\n";

    cout << "Customer : "
         << customer.getName()
         << "\n";

    cout << "------------------------------------\n";

    const auto& items =
        cart.getItems();

    for (const auto& cartItem : items) {

        cout << cartItem.getItem()->getName()
             << " x"
             << cartItem.getQuantity()
             << "  Rp "
             << fixed << setprecision(0)
             << cartItem.getSubtotal()
             << "\n";
    }

    cout << "------------------------------------\n";

    cout << "TOTAL    : Rp "
         << fixed << setprecision(0)
         << cart.calculateTotal()
         << "\n";

    cout << "Payment  : "
         << payment.getMethod()
         << "\n";

    cout << "Paid     : Rp "
         << payment.getAmountPaid()
         << "\n";

    cout << "Change   : Rp "
         << payment.getChange()
         << "\n";

    cout << "Status   : "
         << status
         << "\n";

    cout << "====================================\n";

    cout << "        Thank you for ordering!     \n";

    cout << "====================================\n";
}