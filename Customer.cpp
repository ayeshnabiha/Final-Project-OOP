#include "Customer.h"

Customer::Customer() {
    name = "";
}

Customer::Customer(string name) {
    this->name = name;
}

void Customer::setName(string name) {
    this->name = name;
}

string Customer::getName() const {
    return name;
}