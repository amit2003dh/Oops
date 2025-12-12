This video titled **"Lecture 73: Inheritance | Access Modifier | Real Life Example"** explains the concept of Inheritance in C++ using real-world analogies and code examples.

### **1. What is Inheritance?**

- **Definition:** The capability of a class to derive properties and characteristics from another class.
- **Real-Life Analogy:** Just as a child inherits genetics (looks, height) from their parents, a **Child Class** (Derived Class) inherits data members and functions from a **Parent Class** (Base Class).
- **Key Benefit:** **Reusability**. Instead of writing the same code multiple times (DRY Principle - Don't Repeat Yourself), you write it once in a base class and let other classes inherit it.
  - _Example:_ A `Human` class has `name`, `age`, and `weight`. A `Student` class and a `Teacher` class are both humans, so instead of rewriting `name`, `age`, `weight` inside them, they can just inherit from `Human`.

### **2. Syntax of Inheritance**

```cpp
class ChildClassName : access_mode ParentClassName {
    // Body of child class
};
```

- `access_mode`: Can be `public`, `protected`, or `private`. This defines how the inherited members will be treated inside the child class.

### **3. Access Modifiers (Public, Protected, Private)**

The video explains three levels of access control:

1.  **Public:** Accessible from anywhere (inside the class, inside derived classes, and outside via objects).
2.  **Protected:** Accessible inside the class and **inside derived classes**, but **NOT** outside the class. This is specifically designed for inheritance.
3.  **Private:** Accessible **only** inside the class where it is defined. Even derived classes cannot access private members of their parent.

### **4. Modes of Inheritance**

The mode you use (`: public Parent`, `: protected Parent`, `: private Parent`) determines the visibility of the parent's members inside the child class.

| Parent Class Member | Inheritance Mode: **Public** | Inheritance Mode: **Protected** | Inheritance Mode: **Private** |
| :------------------ | :--------------------------- | :------------------------------ | :---------------------------- |
| **Public**          | Becomes **Public**           | Becomes **Protected**           | Becomes **Private**           |
| **Protected**       | Becomes **Protected**        | Becomes **Protected**           | Becomes **Private**           |
| **Private**         | **Not Accessible**           | **Not Accessible**              | **Not Accessible**            |

- **Public Inheritance:** Public remains public, Protected remains protected. This is the most common mode.
- **Protected Inheritance:** Both Public and Protected members of the parent become **Protected** in the child.
- **Private Inheritance:** Both Public and Protected members of the parent become **Private** in the child.

### **5. Code Snippets**

Here are the code examples demonstrating these concepts.






---

### **Combined Code with Detailed Comments**

```cpp
#include <iostream>
using namespace std;

// ==========================================
// 1. Base Class (Parent)
// ==========================================
class Human {
    // Private: Not inherited, accessible ONLY inside Human class
    private:
        string religion;

    // Protected: Accessible inside Human AND Derived classes (Student), but NOT outside (main)
    protected:
        string name;
        int age;
        int weight;

    // Public: Accessible everywhere
    public:
        // Function to show private member access within class
        void setReligion(string r) {
            religion = r;
        }
};

// ==========================================
// 2. Derived Class (Child)
// ==========================================
// Inheriting in 'protected' mode:
// - Public members of Human become Protected in Student
// - Protected members of Human remain Protected in Student
// - Private members of Human are NOT accessible
class Student : protected Human {
    private:
        int roll_number;
        int fees;

    public:
        // Constructor
        Student(string n, int a, int w, int r, int f) {
            // Accessing Inherited Protected Members
            name = n;
            age = a;
            weight = w;

            // Accessing Own Private Members
            roll_number = r;
            fees = f;
        }

        void display() {
            // We can access 'name' here because it is protected in parent and we inherited it
            cout << "--- Student Details ---" << endl;
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "Weight: " << weight << endl;
            cout << "Roll No: " << roll_number << endl;
            cout << "Fees: " << fees << endl;
        }
};

int main() {
    // Creating Child Object
    Student s1("Rohit", 18, 65, 101, 50000);

    // s1.name = "Mohit"; // ERROR: 'name' is protected in Student class (cannot access from main)

    s1.display(); // Public function of Student class allows us to view data

    return 0;
}
```

http://googleusercontent.com/youtube_content/11
