#include <iostream>
using namespace std;

class Customer
{
    string name;
    int balance;
    // Static variable: Shared by ALL objects. Memory allocated only once.
    static int total_customer_count;
    static int total_balance;

public:
    Customer(string name, int balance)
    {
        this->name = name;
        this->balance = balance;
        // Increment static count every time a new object is created
        total_customer_count++;
        total_balance += balance;
    }

    // Static Member Function
    // Can ONLY access static members (total_customer_count), not 'name' or 'balance'
    static void accessStatic()
    {
        cout << "Total Customers: " << total_customer_count << endl;
        cout << "Total Bank Balance: " << total_balance << endl;
    }

    void deposit(int amount)
    {
        if (amount > 0)
        {
            balance += amount;
            total_balance += amount;
        }
    }
};

// INITIALIZATION of Static Members (MUST be done outside the class)
int Customer::total_customer_count = 0;
int Customer::total_balance = 0;

int main()
{
    Customer A1("Rohit", 1000);
    Customer A2("Mohit", 2000);
    Customer A3("Sohan", 3000);

    // Calling Static Function using Class Name (No object needed)
    Customer::accessStatic();

    // Changing state via object
    A1.deposit(500);
    Customer::accessStatic(); // Total balance updates globally

    return 0;
}