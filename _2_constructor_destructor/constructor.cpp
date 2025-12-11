#include <iostream>  // Includes the Input/Output stream library to use cout/cin
using namespace std; // Allows using standard library elements (like cout) without prefixing 'std::'

// Class Definition: A blueprint for creating Customer objects
class Customer
{
    // Private Data Members (Accessible only inside this class)
    string name;
    int *balance; // Pointer variable. We use a pointer here to simulate dynamic memory usage (Heap)
                  // and to demonstrate the importance of Deep Copy vs Shallow Copy.

public:
    // ==========================================
    // 1. DEFAULT CONSTRUCTOR
    // ==========================================
    // This runs automatically when an object is created without arguments.
    // Example: Customer c1;
    Customer()
    {
        name = "Default";
        // allocating memory on the HEAP for an integer and initializing it to 0
        balance = new int(0);
        cout << "Default Constructor Called" << endl;
    }

    // ==========================================
    // 2. PARAMETERIZED CONSTRUCTOR
    // ==========================================
    // This runs when arguments are passed during object creation.
    // Example: Customer c2("Rohit", 1000);
    Customer(string name, int bal)
    {
        // 'this->name' refers to the class member variable.
        // 'name' refers to the function parameter.
        // 'this' is a pointer that holds the address of the current object.
        this->name = name;

        // Dynamically allocating memory on the HEAP for the balance.
        this->balance = new int(bal);
        cout << "Parameterized Constructor Called for: " << name << endl;
    }

    // ==========================================
    // 3. COPY CONSTRUCTOR (Deep Copy)
    // ==========================================
    // This runs when a new object is created as a copy of an existing object.
    // Example: Customer c3(c2); OR Customer c3 = c2;
    // CRITICAL: The argument must be passed by Reference (&B) to prevent infinite recursion.
    Customer(Customer &B)
    {
        name = B.name; // Copy the name normally (string handles its own memory)

        // DEEP COPY EXPLANATION:
        // If we did 'balance = B.balance', both objects would point to the SAME memory address.
        // If one object changed the balance, the other would change too (Shallow Copy).
        // Instead, we allocate NEW memory so this object has its own independent copy.
        balance = new int(*(B.balance));

        cout << "Copy Constructor: Created a copy of " << B.name << endl;
    }

    // ==========================================
    // 4. DESTRUCTOR
    // ==========================================
    // Runs automatically when an object is destroyed.
    // Purpose: To release resources (like Heap memory) acquired by the object.
    // Name is same as class with a tilde (~).
    // Starts with '~',no arguments, no return type
    ~Customer()
    {
        cout << "Destructor Called for: " << name << endl;

        // MEMORY CLEANUP:
        // Since we used 'new int' in constructors, we MUST use 'delete' here.
        // If we forget this, the memory remains occupied (Memory Leak).
        delete balance;
    }

    // Helper function to show data
    void display()
    {
        // We use *balance to dereference the pointer and get the actual value
        cout << "Customer Name: " << name << ", Balance: " << *balance << endl;
    }
};

// ==========================================
// MAIN FUNCTION
// ==========================================
int main()
{
    // 1. Stack Allocation
    // Object A1 is created on the Stack. Parameterized Constructor is called.
    cout << "--- 1. Creating A1 (Stack) ---" << endl;
    Customer A1("Rohit", 1000);
    A1.display();

    // 2. Copy Constructor Usage
    // Object A2 is created as a copy of A1. Copy Constructor is called.
    // Because of Deep Copy, A2 has its own separate memory for balance.
    cout << "\n--- 2. Creating A2 (Copy of A1) ---" << endl;
    Customer A2(A1);
    A2.display();

    // 3. Dynamic Allocation (Heap)
    // Object A3 is created on the Heap using 'new'.
    // The pointer A3 is on the Stack, but the Object it points to is on the Heap.
    cout << "\n--- 3. Creating A3 (Dynamic/Heap) ---" << endl;
    Customer *A3 = new Customer("Mohit", 500);
    A3->display(); // Arrow operator (->) is used to access members of a pointer object.

    // 4. Explicit Deletion
    // For Heap objects (created with 'new'), Destructor is NOT called automatically.
    // We must manually call delete to trigger the destructor and free memory.
    cout << "\n--- 4. Deleting A3 Manually ---" << endl;
    delete A3;

    // 5. Stack Unwinding (Automatic Destruction)
    // As main() ends, Stack objects (A1 and A2) are destroyed automatically.
    // The order is REVERSE of creation: Last In, First Out (LIFO).
    // A2 will be destroyed first, then A1.
    cout << "\n--- 5. End of Main (Automatic Destructors) ---" << endl;

    return 0;
}