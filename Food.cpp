#include "Food.h"
#include <iostream>
#include <iomanip>

using namespace std;

Food::Food(int id, string name, string category, double basePrice)
    : MenuItem(id, name, category, basePrice){}

double Food::calculatePrice() const {return basePrice;}

void Food::display() const {
    cout << left
         << setw(4) << id
         << setw(25) << name
         << "Rp "
         << fixed << setprecision(0)
         << basePrice
         << endl;
}