#include <iostream> 
#include <iomanip>
#include <windows.h>
using namespace std;

int id = 1;
string name = "apoy";

void display() {
    cout << "\n";
    cout << string(30,'=') << endl;
    cout << string(10, ' ') << "FOYE JAKAL" << string(10, ' ') << endl;
    cout << string(30,'=') << endl;
    cout << "Cashier: "
         << name
         << "\n\n";

    cout << "1. Choose Menu\n";
    cout << "2. Show Cart\n";
    cout << "3. Checkout\n";
    cout << "0. Exit\n";
}

int main() {
display();
}