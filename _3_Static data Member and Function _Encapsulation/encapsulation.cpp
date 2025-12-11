// This code demonstrates protecting the `balance` variable from invalid modifications (like negative deposits).

#include <iostream>
using namespace std;

class Customer
{
    // 1. Data Hiding: Making variables private
    string name;
    int balance;
    int age;

public:
    Customer(string name, int balance, int age)
    {
        this->name = name;
        this->balance = balance;
        this->age = age;
    }

    // 2. Public Interface: Controlling access via functions
    void deposit(int amount)
    {
        // Validation Logic: Preventing invalid data
        if (amount > 0)
        {
            balance += amount;
            cout << amount << " Rs deposited. Current Balance: " << balance << endl;
        }
        else
        {
            cout << "Invalid Amount: Cannot deposit negative value." << endl;
        }
    }

    void updateAge(int newAge)
    {
        // Validation: Age cannot be illogical
        if (newAge > 0 && newAge < 100)
        {
            age = newAge;
        }
        else
        {
            cout << "Invalid Age Provided" << endl;
        }
    }

    void display()
    {
        cout << name << " | Age: " << age << " | Balance: " << balance << endl;
    }
};

int main()
{
    Customer A1("Rohit", 1000, 25);

    // A1.balance = -500; // ERROR: Cannot access private member directly

    // Valid Deposit
    A1.deposit(500);

    // Invalid Deposit (Handled by Encapsulation logic)
    A1.deposit(-200);

    A1.display();
    return 0;
}