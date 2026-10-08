#include "MenuItem.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

MenuItem::MenuItem(int id, string name, string category, double basePrice
) : id(id), name(name), category(category), basePrice(basePrice){}

MenuItem::~MenuItem() {}

int MenuItem::getId() const {return id;}

string MenuItem::getName() const {return name;}

string MenuItem::getCategory() const {return category;}

double MenuItem::getBasePrice() const {return basePrice;}

double MenuItem::calculatePrice() const {return basePrice;}

void MenuItem::display() const {
    cout << left
         << setw(4) << id
         << setw(25) << name
         << "Rp "
         << fixed << setprecision(0)
         << basePrice
         << endl;
}