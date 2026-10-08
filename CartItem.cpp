#include "CartItem.h"
#include "Beverage.h"

#include <iostream>
#include <iomanip>

using namespace std;

CartItem::CartItem(MenuItem* item,int quantity) {
    this->item = item;
    this->quantity = quantity;
}

MenuItem* CartItem::getItem() const {return item;}

int CartItem::getQuantity() const {return quantity;}

void CartItem::setQuantity(int quantity) {this->quantity = quantity;}

void CartItem::increaseQuantity(int amount) {quantity += amount;}

double CartItem::getSubtotal() const {return item->calculatePrice() * quantity;}

void CartItem::display() const {

    cout << "\n"
         << item->getName()
         << " x" << quantity;

    Beverage* beverage =
        dynamic_cast<Beverage*>(item);

    if (beverage != nullptr) {

        cout << "\n   Size : "
             << beverage->getSize();

        cout << "\n   Temp : "
             << beverage->gethotOrIced();

        // cout << "\n   Sugar: "
        //      << beverage->getSugarLevel();

        // cout << "\n   Ice  : "
        //      << beverage->getIceLevel();
    }

    cout << "\n   Subtotal: Rp "
         << fixed << setprecision(0)
         << getSubtotal()
         << "\n";
}