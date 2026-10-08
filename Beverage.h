#ifndef BEVERAGE_H
#define BEVERAGE_H

#include "MenuItem.h"

class Beverage : public MenuItem {

private:
    string size;
    string hotOrIced;
    // string sugarLevel;
    // string iceLevel;

public:
    Beverage(
        int id,
        string name,
        string category,
        double basePrice
    );

    void setSize(string size);
    void sethotOrIced(string hotOrIced);
    // void setSugarLevel(string sugarLevel);
    // void setIceLevel(string iceLevel);

    string getSize() const;
    string gethotOrIced() const;
    // string getSugarLevel() const;
    // string getIceLevel() const;

    double calculatePrice() const override;

    void display() const override;
};

#endif