#ifndef CASHIER_H
#define CASHIER_H

#include "MenuItem.h"
#include "Beverage.h"
#include "Food.h"
#include "Order.h"

#include <vector>
#include <string>

using namespace std;

class Cashier {
private:
    string name;
    vector<MenuItem*> menu;
    Order currentOrder;

public:
    Cashier(string name);
    ~Cashier();

    void addMenuItem(MenuItem* item);

    void showMainMenu();
    void start();

    void showMenu();
    void showBeverageMenu();
    void showFoodMenu();

    void chooseBeverage(Order& order);
    void chooseFood(Order& order);
    void customizeBeverage(Beverage* beverage, Order& order);

    void showCart(Order& order);
    void checkout(Order& order);
};

#endif