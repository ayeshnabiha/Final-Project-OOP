#ifndef CARTITEM_H
#define CARTITEM_H

#include "MenuItem.h"

class CartItem {

private:
    MenuItem* item;
    int quantity;

public:
    CartItem(MenuItem* item, int quantity);

    MenuItem* getItem() const;

    int getQuantity() const;

    void setQuantity(int quantity);

    void increaseQuantity(int amount);

    double getSubtotal() const;

    void display() const;
};

#endif