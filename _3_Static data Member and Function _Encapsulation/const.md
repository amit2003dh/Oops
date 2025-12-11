In C++, the `const` keyword in the context of classes is used to protect data and ensure that certain functions do not accidentally modify the state of an object. It enforces "read-only" behavior where appropriate.

There are two main ways to use `const` with classes:

1.  **Const Member Functions:** Functions that promise **not to modify** any member variables of the object.
2.  **Const Objects:** Objects instantiated as `const`, meaning their data cannot be changed after initialization. They can **only** call _const member functions_.

---

### C++ Code Example: Customer Class

Here is a `Customer` class that demonstrates how to strictly define read-only methods versus modification methods.

```cpp
#include <iostream>
#include <string>
using namespace std;

class Customer {
private:
    int customerID;
    string name;
    double balance;

public:
    // Constructor
    Customer(int id, string n, double b) : customerID(id), name(n), balance(b) {}

    // ---------------------------------------------------------
    // 1. CONST MEMBER FUNCTIONS (Read-Only)
    // These functions cannot change any variables (id, name, balance)
    // ---------------------------------------------------------

    // It is good practice to make 'getters' const
    int getID() const {
        return customerID;
    }

    string getName() const {
        return name;
    }

    void displayInfo() const {
        cout << "ID: " << customerID << " | Name: " << name << " | Balance: $" << balance << endl;
        // If we tried to do 'balance = 0;' here, the compiler would throw an error.
    }

    // ---------------------------------------------------------
    // 2. NON-CONST MEMBER FUNCTIONS (Read-Write)
    // These functions modify the state of the object
    // ---------------------------------------------------------

    void addToBalance(double amount) {
        balance += amount; // Modifies the object
    }

    void changeName(string newName) {
        name = newName;    // Modifies the object
    }
};

int main() {
    // Case A: A Regular Object (Mutable)
    Customer regularCust(101, "Alice", 500.0);

    regularCust.addToBalance(100.0); // Allowed: calling non-const function
    regularCust.displayInfo();       // Allowed: calling const function


    // Case B: A Const Object (Read-Only)
    // This object is locked down. It cannot change state.
    const Customer vipCust(999, "Bob", 10000.0);

    vipCust.displayInfo(); // Allowed: displayInfo() is marked 'const'

    // vipCust.addToBalance(500.0); // ERROR! Cannot call non-const function on const object
    // vipCust.changeName("Robert"); // ERROR! Cannot call non-const function on const object

    return 0;
}
```

### Key Takeaways

| Concept          | Syntax                      | Effect                                                                                                                                       |
| :--------------- | :-------------------------- | :------------------------------------------------------------------------------------------------------------------------------------------- |
| **Const Method** | `void func() const { ... }` | Ensures this specific function will not modify any data members (e.g., `balance`, `name`).                                                   |
| **Const Object** | `const Customer c1(...)`    | Creates a read-only object. The compiler will prevent you from calling any function on this object _unless_ that function is marked `const`. |

### Why use it?

Using `const` allows you to write safer code. It signals to other programmers (and the compiler) exactly which parts of your code are "safe" readers of data and which parts are "modifiers" of data.

---

**explain the `mutable` keyword, which allows a variable to be changed even inside a `const` function?**

The `mutable` keyword is a special specifier in C++ that acts as an "exception slip" for the `const` rule.

It allows a specific member variable to be modified **even inside a `const` member function**.

### Why would you do this?

Usually, `const` means "do not touch anything." However, sometimes you need to change variables that don't affect the **logical state** of the object (the data the user cares about), but are necessary for internal management.

Common use cases:

1.  **Debugging/Logging:** Counting how many times a function is called.
2.  **Caching:** Storing a calculated result so you don't have to calculate it again next time (performance optimization).
3.  **Thread Locking:** Locking a mutex (thread safety) inside a read-only function.

---

### Code Example: Customer Class with `mutable`

Let's update the `Customer` class. We want to count how many times a customer's data is viewed (`accessCount`). This counts internal usage but does not change the customer's actual data (Name, ID, Balance).

```cpp
#include <iostream>
#include <string>
using namespace std;

class Customer {
private:
    string name;

    // 'mutable' allows this variable to be changed in const functions
    mutable int accessCount = 0;

public:
    Customer(string n) : name(n) {}

    // 1. CONST FUNCTION
    // Physically, this function is "read-only", but thanks to mutable,
    // we can still update 'accessCount'.
    void displayInfo() const {
        // Incrementing the counter inside a const function!
        accessCount++;

        cout << "Customer Name: " << name << endl;
        cout << "(This record has been accessed " << accessCount << " times)" << endl;
    }
};

int main() {
    // We create a strictly CONST object
    const Customer c1("Alice");

    cout << "--- Access 1 ---" << endl;
    c1.displayInfo(); // accessCount becomes 1

    cout << "\n--- Access 2 ---" << endl;
    c1.displayInfo(); // accessCount becomes 2

    // Note: c1.name = "Bob";  <-- This would still be a COMPILER ERROR.
    // Only 'accessCount' is editable.

    return 0;
}
```

### Breakdown of the Magic

- **The Rule:** `c1` is a `const` object. You cannot change `name`.
- **The Exception:** `accessCount` is marked `mutable`.
- **The Result:** When you call `displayInfo()`, the compiler allows `accessCount++` to execute, even though `displayInfo()` promised not to change anything.

### Summary Table

| Keyword     | Use Case            | Behavior                                                                        |
| :---------- | :------------------ | :------------------------------------------------------------------------------ |
| **const**   | `void func() const` | "I promise not to change **any** variables."                                    |
| **mutable** | `mutable int x;`    | "If someone makes a `const` promise, ignore it for **this specific variable**." |
