This video titled **"Lecture 72: Object Oriented Programming: Static data Member and Function | Encapsulation"** covers three key pillars of C++ Object-Oriented Programming:

### **1. Static Data Members & Static Member Functions**

- **Static Data Member:**
  - A variable declared with the `static` keyword inside a class.
  - **Crucial difference:** Unlike normal variables (where each object gets its own copy), a `static` member is created **only once** and is **shared by all objects** of that class.
  - **Use Case:** To keep track of data common to all objects, such as the `total_customer_count` in a bank. If you have 3 customers (objects), they all share one single variable for the count.
  - **Initialization:** Must be initialized **outside** the class using the scope resolution operator `::`.
- **Static Member Function:**
  - A function declared with `static`.
  - It can access **only** static data members (it cannot touch normal/non-static variables like `name` or `balance` because it doesn't belong to any specific object).
  - It can be called **without creating an object** using the class name (e.g., `Customer::totalCustomers()`).

### **2. Encapsulation**

- **Definition:** Wrapping up data (variables) and information (functions) into a single unit (Class) while **restricting access** to them.
- **Data Hiding:** It involves making data members `private` so they cannot be accessed or modified directly from outside the class.
- **Why use it?** To protect data integrity.
  - _Example:_ If `balance` is public, anyone could set it to a negative value (e.g., `-500`), which is invalid.
  - By making `balance` **private** and using a public function `deposit(amount)`, we can add logic to **validate** the input (e.g., `if (amount > 0) balance += amount;`) before changing the data.

### **3. Abstraction**

- **Definition:** Hiding complex implementation details and showing only the essential features to the user.
- **Real-world Analogy:** When you order food at a restaurant, you only care that the food arrives (Interface). You don't need to know the complex recipe or how the chef cooked it (Implementation).
- **In Programming:** When you call `pow(2, 4)` or `sort()`, you don't need to know the underlying algorithm. You just care that it gives the correct result. Similarly, a user calling `deposit()` doesn't need to know the internal tax calculations or database updates; they just want the money deposited.

---

### **Combined Code with Detailed Comments**

```cpp
#include <iostream>
using namespace std;

// ==========================================
// Class Demonstrating Static & Encapsulation
// ==========================================
class BankSystem {
    // Encapsulation: Private data members hidden from outside world
    private:
    string name;
    int balance;

    // Static Member: Belongs to the CLASS, not any single object.
    // Keeps track of the total users and money in the entire bank.
    static int total_users;
    static int total_bank_money;

    public:
    // Constructor
    BankSystem(string n, int b) {
        name = n;
        balance = b;

        // Updating Static members
        total_users++;
        total_bank_money += balance;
    }

    // Encapsulated Function: Validates deposit amount
    void deposit(int amount) {
        if(amount <= 0) {
            cout << "Error: Invalid Deposit Amount" << endl;
            return;
        }
        balance += amount;
        total_bank_money += amount; // Updates shared static variable
        cout << "Deposited " << amount << " into " << name << "'s account." << endl;
    }

    // Encapsulated Function: Validates withdrawal
    void withdraw(int amount) {
        if(amount <= 0 || amount > balance) {
            cout << "Error: Invalid Withdrawal or Insufficient Funds" << endl;
            return;
        }
        balance -= amount;
        total_bank_money -= amount;
        cout << "Withdrew " << amount << " from " << name << "'s account." << endl;
    }

    // Static Member Function
    // Can be called without any object. Can ONLY access static variables.
    static void printBankStatus() {
        cout << "\n[Bank Status Report]" << endl;
        cout << "Total Users: " << total_users << endl;
        cout << "Total Money in Bank: " << total_bank_money << endl;
        // cout << name; // ERROR: Cannot access non-static member 'name' here
    }

    void displayProfile() {
        cout << "User: " << name << " | Balance: " << balance << endl;
    }
};

// Initializing Static Members (Required scope resolution operator ::)
int BankSystem::total_users = 0;
int BankSystem::total_bank_money = 0;

int main() {
    // 1. Static Initial State
    BankSystem::printBankStatus(); // 0 Users, 0 Money

    // 2. Creating Objects
    BankSystem u1("Rohit", 1000);
    BankSystem u2("Mohit", 2000);

    // 3. Modifying Data via Encapsulated Methods
    u1.deposit(500);  // Logic checks amount > 0
    u1.deposit(-100); // Logic rejects this

    u2.withdraw(500);

    // 4. Checking Individual Profiles
    u1.displayProfile();
    u2.displayProfile();

    // 5. Checking Shared Static Data
    // Notice how u1 and u2 actions affected the global bank total
    BankSystem::printBankStatus();

    return 0;
}
```

http://googleusercontent.com/youtube_content/9

Encapsulation and Abstraction are two pillars of Object-Oriented Programming (OOP) that often get confused because they both involve "hiding" things.

The simplest way to distinguish them is:

- **Abstraction** hides **complexity** (Implementation Details).
- **Encapsulation** hides **internal data** (Information Hiding).

---

### 1\. The Key Differences

| Feature         | Abstraction                                               | Encapsulation                                                     |
| :-------------- | :-------------------------------------------------------- | :---------------------------------------------------------------- |
| **Focus**       | Focuses on **"What"** the object does.                    | Focuses on **"How"** the object does it.                          |
| **Goal**        | Reduces complexity for the user.                          | Protects data and ensures security.                               |
| **Mechanism**   | Uses **Interfaces** and **Abstract Classes**.             | Uses **Access Modifiers** (`private`, `protected`, `public`).     |
| **Perspective** | **Design Level:** Solves the problem at the design stage. | **Implementation Level:** Solves the problem at the coding stage. |

---

### 2\. A Real-World Analogy: The Car

Think of a car to understand the separation:

- **Abstraction ( The Interface):**

  - You interact with the **Steering Wheel**, **Gas Pedal**, and **Brake**.
  - You know _what_ they do (steer, go, stop).
  - You do **not** need to know the physics of the fuel injection system or how the rack-and-pinion gears work to drive the car. The car "abstracts" away that complexity.

- **Encapsulation (The Protection):**

  - The engine is placed under a **hood (bonnet)**.
  - The wires and pistons are wrapped up.
  - This prevents you from accidentally touching a hot engine block or cutting a wire while driving. It bundles the machinery together and restricts direct access to safe boundaries.

---
