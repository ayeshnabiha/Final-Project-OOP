#include "Payment.h"

#include <iostream>
#include <iomanip>

using namespace std;

Payment::Payment() {

    method = "";
    amountPaid = 0;
    change = 0;
    paid = false;
}

bool Payment::processPayment(
    double total
) {

    int choice;

    cout << "\n========== PAYMENT ==========\n";

    cout << "Total: Rp "
         << fixed << setprecision(0)
         << total
         << "\n\n";

    cout << "1. Cash\n";
    cout << "2. QRIS\n";
    cout << "3. Debit\n";
    cout << "0. Back\n";

    cout << "\nChoose payment method: ";
    cin >> choice;

    if (choice == 0) {
        return false;
    }

    while (
        choice < 1 ||
        choice > 3
    ) {

        cout << "Invalid choice.\n";
        cout << "Choose again: ";

        cin >> choice;

        if (choice == 0) {
            return false;
        }
    }

    // CASH
    if (choice == 1) {

        method = "Cash";

        cout << "\nCash received: Rp ";
        cin >> amountPaid;

        while (amountPaid < total) {

            cout << "Insufficient amount.\n";

            cout << "Enter cash again: Rp ";
            cin >> amountPaid;
        }

        change = amountPaid - total;
    }

    // QRIS
    else if (choice == 2) {

        method = "QRIS";

        cout << "\nWaiting for QRIS payment...\n";
        
        cout << "\nPress ENTER after payment is confirmed...";
        cin.ignore();
        cin.get();

        cout << "Payment received.\n";

        amountPaid = total;

        change = 0;
    }

    // DEBIT
    else if (choice == 3) {

        method = "Debit";

        cout << "\nProcessing debit payment...\n";
        
        cout << "\nPress ENTER after the transaction is confirmed...";
        cin.ignore();
        cin.get();
        
        cout << "Payment received.\n";

        amountPaid = total;

        change = 0;
    }

    paid = true;

    cout << "\nPayment successful!\n";

    return true;
}

string Payment::getMethod() const {
    return method;
}

double Payment::getAmountPaid() const {
    return amountPaid;
}

double Payment::getChange() const {
    return change;
}

bool Payment::isPaid() const {
    return paid;
}
