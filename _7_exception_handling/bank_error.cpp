// #### **2. Customer Bank Example (Throwing Different Exceptions)**

// Handling multiple logical errors in a banking scenario.

// ```cpp
#include <iostream>
using namespace std;

class Customer {
    string name;
    int balance;
    
public:
    Customer(string n, int b) : name(n), balance(b) {}

    void deposit(int amount) {
        if (amount <= 0) {
            throw "Amount should be greater than 0";
        }
        balance += amount;
        cout << amount << " rs credited successfully." << endl;
    }

    void withdraw(int amount) {
        if (amount <= 0) {
            throw "Amount should be greater than 0";
        }
        if (amount > balance) {
            throw "Insufficient Balance";
        }
        balance -= amount;
        cout << amount << " rs debited successfully." << endl;
    }
};

int main() {
    Customer c1("Rohit", 5000);
    
    try {
        c1.deposit(100);
        c1.withdraw(6000); // This triggers exception
    } 
    catch (const char* e) {
        cout << "Exception Occurred: " << e << endl;
    }
    
    return 0;
}
