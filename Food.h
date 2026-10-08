#ifndef FOOD_H
#define FOOD_H

#include "MenuItem.h"

class Food : public MenuItem {

public:

    Food(
        int id,
        string name,
        string category,
        double basePrice
    );

    double calculatePrice() const override;

    void display() const override;
};

#endif