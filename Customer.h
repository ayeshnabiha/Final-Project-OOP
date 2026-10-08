#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

using namespace std;

class Customer {

private:
    string name;

public:

    Customer();

    Customer(string name);

    void setName(string name);

    string getName() const;
};

#endif