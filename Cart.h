#ifndef CART_H
#define CART_H

#include "CartItem.h"
#include <vector>

using namespace std;

class Cart {

private:
    vector<CartItem> items;

public:

    void addItem(MenuItem* item, int quantity);

    void showCart() const;

    double calculateTotal() const;

    bool isEmpty() const;

    int getItemCount() const;

    void removeItem(int index);

    bool updateQuantity(int index, int quantity);

    void clearCart();

    CartItem* getCartItem(int index);

    const vector<CartItem>& getItems() const;
};

#endif
