#include "MenuItem.h"
#include <iostream>
#include <iomanip>

using namespace std;

MenuItem::MenuItem(
    int id,
    string name,
    string category,
    double basePrice
) {
    this->id = id;
    this->name = name;
    this->category = category;
    this->basePrice = basePrice;
}

MenuItem::~MenuItem() {
}

int MenuItem::getId() const {
    return id;
}

string MenuItem::getName() const {
    return name;
}

string MenuItem::getCategory() const {
    return category;
}

double MenuItem::getBasePrice() const {
    return basePrice;
}

double MenuItem::calculatePrice() const {
    return basePrice;
}

void MenuItem::display() const {

    cout << left
         << setw(4) << id
         << setw(25) << name
         << "Rp "
         << fixed << setprecision(0)
         << basePrice
         << endl;
}