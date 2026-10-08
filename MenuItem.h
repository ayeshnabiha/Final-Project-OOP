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
    string getCategory() const; //coffee non-coffee savory sweet
    double getBasePrice() const;

    virtual double calculatePrice() const; //for bev size pricing
    virtual void display() const;
};

#endif