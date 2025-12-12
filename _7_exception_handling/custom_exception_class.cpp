// #### **4. Custom Exception Class**

// Creating a user-defined exception for better readability.

// ```cpp
#include <iostream>
#include <exception>
using namespace std;

// Custom Exception Class inheriting from runtime_error
class InvalidAmountError : public runtime_error
{
public:
    // Constructor passes message to the base class
    InvalidAmountError(const string &msg) : runtime_error(msg) {}
};

class InsufficientBalanceError : public runtime_error
{
public:
    InsufficientBalanceError(const string &msg) : runtime_error(msg) {}
};

int main()
{
    int balance = 5000;
    int withdrawAmount = 6000;

    try
    {
        if (withdrawAmount > balance)
        {
            // Throwing a custom exception object
            throw InsufficientBalanceError("Balance is too low for this transaction.");
        }
    }
    catch (const exception &e)
    {
        // Polymorphism at work: 'e' refers to our custom error
        cout << "Custom Exception: " << e.what() << endl;
    }

    return 0;
}
