#include <iostream>
using namespace std;
class Customer
{
private:
    static int id_counter; // Static variable to keep track of the last ID used across ALL objects
    string name;
    int account_number;
    double balance;
    bool is_active;

public:
    void create_account(string n)
    {
        name = n;
        account_number = id_counter++;

        balance = 0.0;
        is_active = true;
        cout << "Account created for " << name << " with Account Number: " << account_number << endl;
    }
    void deposit(double amount)
    {
        if (!is_active)
        {
            cout << "Account is inactive. Cannot deposit funds." << endl;
            return;
        }
        if (amount <= 0)
        {
            cout << "Invalid deposit amount." << endl;
            return;
        }
        balance += amount;
        cout << "Deposited: $" << amount << ". New Balance: $" << balance << endl;
    }
    void withdraw(double amount)
    {
        if (!is_active)
        {
            cout << "Account is inactive. Cannot withdraw funds." << endl;
            return;
        }
        if (amount <= 0)
        {
            cout << "Invalid withdrawal amount." << endl;
            return;
        }
        if (amount > balance)
        {
            cout << "Insufficient funds." << endl;
            return;
        }
        balance -= amount;
        cout << "Withdrew: $" << amount << ". New Balance: $" << balance << endl;
    }
    void transfer(Customer &to, double amount)
    {
        if (!is_active)
        {
            cout << "Account is inactive. Cannot transfer funds." << endl;
            return;
        }
        if (amount <= 0)
        {
            cout << "Invalid transfer amount." << endl;
            return;
        }
        if (amount > balance)
        {
            cout << "Insufficient funds." << endl;
            return;
        }
        balance -= amount;
        to.balance += amount;
        cout << "Transferred: $" << amount << " to " << to.name << ". New Balance: $" << balance << endl;
    }
    void print_details()
    {
        cout << "Account Holder: " << name << endl;
        cout << "Account Number: " << account_number << endl;
        cout << "Balance: $" << balance << endl;
        cout << "Status: " << (is_active ? "Active" : "Inactive") << endl;
    }
};

// Initialize static member
int Customer::id_counter = 1;

int main()
{
    Customer c1;
    c1.create_account("Alic");
    c1.deposit(500);

    Customer c2;
    c2.create_account("Bob");
    c2.deposit(1000);
    c2.print_details();
    c2.transfer(c1, 200);
    c1.print_details();
    c2.withdraw(1500);
}