#include <iostream>
#include <string>
using namespace std;

//AYESHA
class Product{
    protected:
    int id;
    string name;
    double price;
    int stock;
    string description;

    public:
    void getID(){}
    void getName(){}
    void getPrice(){}
    void setPrice(){}
    void setStock(){}
    int reduceStock(int n){
        return stock = stock - n;
    }
    virtual void showProduct(){}
    Product(){}
};

class FoodProduct : public Product{};
class BeverageProduct : public Product{};

void showMain(){
    int choice;
    cout << string(10,'=') << "WELCOME TO FORE, JAKAL" << string(10,'=') << endl;
    cout << "1. SHOW MENU" << endl;
    // cout << "CHOOSE MENU" << endl;
    // cout << "SHOW CART" << endl;
    // cout << "CHECK OUT" << endl;
    // cout << "OUT" << endl;
    cout << "What do you want to do? ";
}

//FARA
class Cart{};
class CartItem{};
class Order{};

int main(){
    int choice;
    do {
        showMain();
        cin >> choice;

        switch (choice)
        {
        case 1:
            
            break;
        
        default:
            break;
        }
    }while (choice != 0);
}