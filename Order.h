#ifndef ORDER_H
#define ORDER_H

#include "Cart.h"
#include "Customer.h"
#include "Payment.h"

class Order {

private:

    static int nextOrderId;

    int orderId;

    Customer customer;

    Cart cart;

    Payment payment;

    string status;

public:

    Order();

    int getOrderId() const;

    void setCustomer(
        const Customer& customer
    );

    Customer getCustomer() const;

    Cart& getCart();

    void setStatus(string status);

    string getStatus() const;

    bool processPayment();

    void printReceipt() const;
};

#endif