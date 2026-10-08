#include "Cashier.h"

#include <iostream>
#include <iomanip>

using namespace std;

Cashier::Cashier(string name) {

    this->name = name;
}

Cashier::~Cashier() {

    for (auto item : menu) {
        delete item;
    }
}

void Cashier::addMenuItem (MenuItem* item) {

    menu.push_back(item);
}

void Cashier::showMainMenu() {

    cout << "\n";
    cout << "====================================\n";
    cout << "             FOYE JAKAL             \n";
    cout << "           COFFEE SHOP POS          \n";
    cout << "====================================\n";

    cout << "Cashier: "
         << name
         << "\n\n";

    cout << "1. Choose Menu\n";
    cout << "2. Show Cart\n";
    cout << "3. Checkout\n";
    cout << "0. Exit\n";

    cout << "\nChoose: ";
}

void Cashier::start() {
    bool running = true;

    while (running) {
        showMainMenu();

        int choice;
        cin >> choice;

        switch (choice) {

        case 1:
            showMenu();
            break;

        case 2:
            showCart(currentOrder);
            break;

        case 3:
            checkout(currentOrder);

            if (currentOrder.getStatus() == "PAID") {
                currentOrder = Order();
            }
            break;

        case 0:
            cout << "\n";
            cout << "Thank you, "
                 << name
                 << ". Goodbye!\n";

            running = false;
            break;

        default:
            cout << "\nInvalid choice.\n";
        }
    }
}

void Cashier::showMenu() {

    int choice;

    do {
        cout << "\n";
        cout << "========== MENU ==========\n";
        cout << "1. Beverage\n";
        cout << "2. Food\n";
        cout << "0. Back\n";
        cout << "\nChoose: ";

        cin >> choice;

        switch (choice) {

        case 1:
            chooseBeverage(currentOrder);
            break;

        case 2:
            chooseFood(currentOrder);
            break;

        case 0:
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);
}

void Cashier::showBeverageMenu() {

    cout << "\n";
    cout << "========== BEVERAGE ==========\n";

    cout << "\n---------- COFFEE ----------\n";

    for (auto item : menu) {

        if (
            item->getCategory()
            == "Coffee"
        ) {

            item->display();
        }
    }

    cout << "\n------- NON-COFFEE --------\n";

    for (auto item : menu) {

        if (
            item->getCategory()
            == "Non-Coffee"
        ) {

            item->display();
        }
    }

    cout << "\n0. Back\n";
}

void Cashier::showFoodMenu() {

    cout << "\n";
    cout << "============ FOOD ============\n";

    cout << "\n---------- SAVORY ----------\n";

    for (auto item : menu) {

        if (
            item->getCategory()
            == "Savory"
        ) {

            item->display();
        }
    }

    cout << "\n----------- SWEET -----------\n";

    for (auto item : menu) {

        if (
            item->getCategory()
            == "Sweet"
        ) {

            item->display();
        }
    }

    cout << "\n0. Back\n";
}

void Cashier::chooseBeverage(Order& order) {

    while (true) {

        showBeverageMenu();

        int id;

        cout << "\nChoose menu ID: ";
        cin >> id;

        if (id == 0) {
            return;
        }

        Beverage* selected =
            nullptr;

        for (auto item : menu) {

            if (
                item->getId() == id
            ) {

                selected =
                    dynamic_cast<Beverage*>(item);

                break;
            }
        }

        if (selected == nullptr) {

            cout << "\nInvalid beverage ID.\n";

            continue;
        }

        // Create a copy so customization
        // doesn't modify the original menu item
        Beverage* customized =
            new Beverage(*selected);

        customizeBeverage(
            customized,
            order
        );

        delete customized;

        return;
    }
}

void Cashier::chooseFood(Order& order) {

    while (true) {

        showFoodMenu();

        int id;

        cout << "\nChoose menu ID: ";
        cin >> id;

        if (id == 0) {
            return;
        }

        Food* selected = nullptr;

        for (auto item : menu) {

            if (
                item->getId() == id
            ) {

                selected =
                    dynamic_cast<Food*>(item);

                break;
            }
        }

        if (selected == nullptr) {

            cout << "\nInvalid food ID.\n";

            continue;
        }

        int quantity;

        cout << "Quantity: ";
        cin >> quantity;

        while (quantity <= 0) {

            cout << "Quantity must be > 0: ";

            cin >> quantity;
        }

        order.getCart().addItem(
            selected,
            quantity
        );

        cout << "\n";
        cout << "Item added to cart!\n";

        return;
    }
}

void Cashier::customizeBeverage(Beverage* beverage, Order& order) {

    int choice;

    // SIZE
    while (true) {

        cout << "\n========== SIZE ==========\n";

        cout << "1. Regular\n";
        cout << "2. Large (+Rp5.000)\n";
        cout << "0. Back\n";

        cout << "\nChoose: ";
        cin >> choice;

        if (choice == 0) {
            return;
        }

        if (choice == 1) {

            beverage->setSize(
                "Regular"
            );

            break;
        }

        if (choice == 2) {

            beverage->setSize(
                "Large"
            );

            break;
        }

        cout << "Invalid choice.\n";
    }

    // TEMPERATURE
    while (true) {

        cout << "\n======= TEMPERATURE =======\n";

        cout << "1. Hot\n";
        cout << "2. Iced\n";
        cout << "0. Back\n";

        cout << "\nChoose: ";
        cin >> choice;

        if (choice == 0) {
            return;
        }

        if (choice == 1) {

            beverage->sethotOrIced(
                "Hot"
            );

            break;
        }

        if (choice == 2) {

            beverage->sethotOrIced(
                "Iced"
            );

            break;
        }

        cout << "Invalid choice.\n";
    }

    // SUGAR
    // while (true) {

    //     cout << "\n========= SUGAR =========\n";

    //     cout << "1. No Sugar\n";
    //     cout << "2. Less Sugar\n";
    //     cout << "3. Normal\n";
    //     cout << "4. Extra Sugar\n";
    //     cout << "0. Back\n";

    //     cout << "\nChoose: ";
    //     cin >> choice;

    //     if (choice == 0) {
    //         return;
    //     }

    //     if (choice == 1) {

    //         beverage->setSugarLevel(
    //             "No Sugar"
    //         );

    //         break;
    //     }

    //     if (choice == 2) {

    //         beverage->setSugarLevel(
    //             "Less Sugar"
    //         );

    //         break;
    //     }

    //     if (choice == 3) {

    //         beverage->setSugarLevel(
    //             "Normal"
    //         );

    //         break;
    //     }

    //     if (choice == 4) {

    //         beverage->setSugarLevel(
    //             "Extra Sugar"
    //         );

    //         break;
    //     }

    //     cout << "Invalid choice.\n";
    // }

    // ICE
    // while (true) {

    //     cout << "\n========== ICE ==========\n";

    //     cout << "1. No Ice\n";
    //     cout << "2. Less Ice\n";
    //     cout << "3. Normal\n";
    //     cout << "4. Extra Ice\n";
    //     cout << "0. Back\n";

    //     cout << "\nChoose: ";
    //     cin >> choice;

    //     if (choice == 0) {
    //         return;
    //     }

    //     if (choice == 1) {

    //         beverage->setIceLevel(
    //             "No Ice"
    //         );

    //         break;
    //     }

    //     if (choice == 2) {

    //         beverage->setIceLevel(
    //             "Less Ice"
    //         );

    //         break;
    //     }

    //     if (choice == 3) {

    //         beverage->setIceLevel(
    //             "Normal"
    //         );

    //         break;
    //     }

    //     if (choice == 4) {

    //         beverage->setIceLevel(
    //             "Extra Ice"
    //         );

    //         break;
    //     }

    //     cout << "Invalid choice.\n";
    // }

    cout << "\n";
    cout << "========== ITEM ==========\n";

    cout << beverage->getName()
         << "\n";

    cout << "Size : "
         << beverage->getSize()
         << "\n";

    cout << "Temp : "
         << beverage->gethotOrIced()
         << "\n";

    // cout << "Sugar: "
    //      << beverage->getSugarLevel()
    //      << "\n";

    // cout << "Ice  : "
    //      << beverage->getIceLevel()
    //      << "\n";

    cout << "Price: Rp "
         << fixed << setprecision(0)
         << beverage->calculatePrice()
         << "\n";

    int quantity;

    cout << "\nQuantity: ";
    cin >> quantity;

    while (quantity <= 0) {

        cout << "Quantity must be > 0: ";
        cin >> quantity;
    }

    order.getCart().addItem(
        beverage,
        quantity
    );

    cout << "\n";
    cout << "Item added to cart!\n";
}

void Cashier::showCart(Order& order) {

    while (true) {

        order.getCart().showCart();

        if (
            order.getCart().isEmpty()
        ) {

            cout << "\n0. Back\n";

            int choice;
            cin >> choice;

            return;
        }

        cout << "\n";
        cout << "1. Remove Item\n";
        cout << "2. Change Quantity\n";
        cout << "3. Clear Cart\n";
        cout << "0. Back\n";

        cout << "\nChoose: ";

        int choice;
        cin >> choice;

        if (choice == 0) {return;}

        // REMOVE
        if (choice == 1) {

            int index;

            cout << "Enter item number: ";
            cin >> index;

            order.getCart().removeItem(
                index - 1
            );

            cout << "\nItem removed.\n";
        }

        // CHANGE QUANTITY
        else if (choice == 2) {

            int index;
            int quantity;

            cout << "Enter item number: ";
            cin >> index;

            CartItem* item =
                order.getCart().getCartItem(
                    index - 1
                );

            if (item == nullptr) {

                cout << "Invalid item.\n";

                continue;
            }

            cout << "New quantity: ";
            cin >> quantity;

            if (quantity <= 0) {

                cout << "Invalid quantity.\n";

                continue;
            }

            item->setQuantity(
                quantity
            );

            cout << "\nQuantity updated.\n";
        }

        // CLEAR
        else if (choice == 3) {

            order.getCart().clearCart();

            cout << "\nCart cleared.\n";
        }

        else {

            cout << "\nInvalid choice.\n";
        }
    }
}

void Cashier::checkout(Order& order) {

    if (
        order.getCart().isEmpty()
    ) {

        cout << "\n";
        cout << "Your cart is empty.\n";

        return;
    }

    cin.ignore();

    string customerName;

    cout << "\n========== CHECKOUT ==========\n";

    cout << "Customer name: ";

    getline(
        cin,
        customerName
    );

    Customer customer(
        customerName
    );

    order.setCustomer(
        customer
    );

    cout << "\n";
    cout << "========== ORDER ==========\n";

    cout << "Order ID : #"
         << order.getOrderId()
         << "\n";

    cout << "Customer : "
         << order.getCustomer().getName()
         << "\n";

    order.getCart().showCart();

    int confirm;

    cout << "\nConfirm order?\n";

    cout << "1. Confirm\n";
    cout << "0. Back\n";

    cout << "\nChoose: ";
    cin >> confirm;

    if (confirm == 0) {
        return;
    }

    if (confirm != 1) {

        cout << "Invalid choice.\n";

        return;
    }

    bool success =
        order.processPayment();

    if (!success) {

        cout << "\nPayment cancelled.\n";

        return;
    }

    order.printReceipt();
}