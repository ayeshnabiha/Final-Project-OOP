#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

//AYESHA
class Product{
    protected:
    int id;
    string name;
    double price;
    int stock;

    public:
    
    Product(int id, string name, double price, int stock)
        : id(id), name(name), price(price), stock(stock){}

    //virtual ~Product(){}

    //getter
    int getID() const {return id;}
    string getName() const {return name;}
    double getPrice() const {return price;}
    
    //setter
    void setPrice(double p){
        price = p;
    }
    void setStock(int s){
        stock = s;
    }
    

    //function
    bool reduceStock(int n){
        if(n <= stock){
            stock -= n;
            return true;
        }
        else cout << "Out of stock!" << endl;
        return false; 
    }

    virtual void showProduct() const {
        cout << "[" << id << "] " << name << " - Rp" << fixed << setprecision(0) << price << endl;
        cout << " | Stock: " << stock << endl;
    }
};

class FoodProduct : public Product{
    private:
    bool isWarmed;

    public:
    FoodProduct(int id, string name, double price, int stock, bool isWarmed)
    : Product(id, name, price, stock), isWarmed(isWarmed) {
        isWarmed = true;
    }
    void showProduct() const override {
        cout << "[FOOD #" << id << "] " << name << " - Rp" << fixed << setprecision(0) << price << endl;
        cout << "Served: " << (isWarmed ? "Warmed Up" : "Room Temperature") << " | Stock: " << stock << endl;
    }
};

class BeverageProduct : public Product{
    private: 
    string cupSize;
    string hotOrIced;

    public:
    BeverageProduct(int id, string name, double price, int stock, string size, string temp)
    : Product(id, name, price, stock), cupSize(size), hotOrIced(temp) {
    }    
};

void showMain(){
    int choice;
    cout << string(10,'=') << "WELCOME TO FORE, JAKAL" << string(10,'=') << endl;
    cout << "CHOOSE MENU" << endl;
    cout << "SHOW CART" << endl;
    cout << "CHECK OUT" << endl;
    cout << "OUT" << endl;
    cout << "What do you want to do? ";
}

//FARA
class Cart{};
class CartItem{};
class Order{};

int main(){

    vector<Product*> menu;
    menu.push_back(new BeverageProduct(101, "Butterscotch Sea Salt Latte", 29000, 20, "Regular", "Iced"));
    menu.push_back(new BeverageProduct(102, "Pandan Latte", 28000, 15, "Regular", "Iced"));
    menu.push_back(new BeverageProduct(103, "Americano", 21000, 30, "Regular", "Hot"));
    menu.push_back(new FoodProduct(201, "Beef Egg & Cheese Toast", 35000, 10, true));
    menu.push_back(new FoodProduct(202, "Butter Croissant", 22000, 12, true));

    int choice;
    do {
        showMain();
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\n---------------- FORE COFFEE MENU ----------------" << endl;
                for (const auto& item : menu) {
                    item->showProduct();
                    cout << "--------------------------------------------------" << endl;
                }
            break;
        
        default:
            break;
        }
    }while (choice != 0);
}