#include "Beverage.h"
#include <iostream>
#include <iomanip>

using namespace std;

Beverage::Beverage(int id, string name, string category, double basePrice)
    : MenuItem(id, name, category, basePrice)
{
    size = "Regular";
    hotOrIced = "Iced";
    sugarLevel = "Normal";
    iceLevel = "Normal";
}

void Beverage::setSize(string s) {
    size = s;
}

void Beverage::sethotOrIced(string hoi) {
    hotOrIced = hoi;
}

void Beverage::setSugarLevel(string sl) {
    sugarLevel = sl;
}

void Beverage::setIceLevel(string il) {
    iceLevel = il;
}

string Beverage::getSize() const {return size;}

string Beverage::gethotOrIced() const {return hotOrIced;}

string Beverage::getSugarLevel() const {return sugarLevel;}

string Beverage::getIceLevel() const {return iceLevel;}

double Beverage::calculatePrice() const {
    double total = basePrice;
    if (size == "Large") {total += 5000;}
    return total;
}

void Beverage::display() const {
    cout << left
         << setw(4) << id
         << setw(25) << name
         << "Rp "
         << fixed << setprecision(0)
         << calculatePrice()
         << endl;
}