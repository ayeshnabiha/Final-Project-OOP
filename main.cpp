#include "Cashier.h"

int main() {

    Cashier cashier("Ayesha");

    // COFFEE

    cashier.addMenuItem(
        new Beverage(1, "Americano", "Coffee", 18000)
    );

    cashier.addMenuItem(
        new Beverage(2, "Cafe Latte", "Coffee",22000)
    );

    cashier.addMenuItem(
        new Beverage(3, "Cappuccino", "Coffee",23000)
    );

    cashier.addMenuItem(
        new Beverage(4, "Caramel Macchiato", "Coffee", 25000)
    );


    // NON-COFFEE

    cashier.addMenuItem(
        new Beverage(5, "Matcha Latte", "Non-Coffee", 25000)
    );

    cashier.addMenuItem(
        new Beverage(6, "Chocolate", "Non-Coffee", 22000)
    );

    cashier.addMenuItem(
        new Beverage( 7, "Taro Latte", "Non-Coffee", 24000)
    );


    // SAVORY

    cashier.addMenuItem(
        new Food(8, "French Fries", "Savory", 18000)
    );

    cashier.addMenuItem(
        new Food(9, "Chicken Sandwich", "Savory", 25000)
    );

    cashier.addMenuItem(
        new Food(10, "Croissant Sandwich", "Savory", 27000)
    );


    // SWEET

    cashier.addMenuItem(
        new Food(11, "Croissant", "Sweet", 20000)
    );

    cashier.addMenuItem(
        new Food(12, "Brownies", "Sweet", 18000)
    );

    cashier.addMenuItem(
        new Food( 13, "Cookies", "Sweet", 15000)
    );


    // Start POS
    cashier.start();

    return 0;
}