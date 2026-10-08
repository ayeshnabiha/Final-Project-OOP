#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>

using namespace std;

class Payment {

private:
    string method;
    double amountPaid;
    double change;
    bool paid;

public:

    Payment();

    bool processPayment(double total);

    string getMethod() const;

    double getAmountPaid() const;

    double getChange() const;

    bool isPaid() const;
};

#endif