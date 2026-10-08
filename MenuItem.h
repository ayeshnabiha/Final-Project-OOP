#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>

using namespace std;

class MenuItem {
protected:
    int id;
    string name;
    string category;
    double basePrice;

public:
    MenuItem(int id, string name, string category, double basePrice);

    virtual ~MenuItem();

    int getId() const;
    string getName() const;
    string getCategory() const;
    double getBasePrice() const;

    virtual double calculatePrice() const;
    virtual void display() const;
};

#endif