This video titled **"Lecture 74: Type of Inheritance in C++ | Single Inheritance | Multiple | Hybrid | Multipath"** explains the six main types of inheritance in C++ with real-world examples and code.

### **1. Types of Inheritance**

- **Single Inheritance:** A single derived class inherits from a single base class.
  - _Example:_ `Student` inherits from `Human`.
- **Multilevel Inheritance:** A chain of inheritance. A class inherits from a derived class, which in turn inherits from another class.
  - _Example:_ `Person` -\> `Employee` -\> `Manager`.
- **Multiple Inheritance:** A single class inherits from **multiple** base classes.
  - _Example:_ `CodeTeacher` inherits from both `Engineer` and `YouTuber`.
- **Hierarchical Inheritance:** Multiple derived classes inherit from a **single** base class.
  - _Example:_ `Human` is the parent of `Student` and `Teacher`.
- **Hybrid Inheritance:** A combination of two or more types of inheritance.
  - _Example:_ Combining Hierarchical and Multiple inheritance.
- **Multipath Inheritance (The Diamond Problem):** A specific form of hybrid inheritance where a class inherits from two classes that both inherit from the same base class. This causes ambiguity (e.g., two copies of the base class data).
  - _Solution:_ **Virtual Inheritance**.

### **2. The Diamond Problem (Multipath Inheritance)**

- **Scenario:** `Human` -\> `Engineer` & `YouTuber`. Then `CodeTeacher` -\> `Engineer` & `YouTuber`.
- **Issue:** `CodeTeacher` receives two copies of `Human`'s data (like `name`), one via `Engineer` and one via `YouTuber`. Accessing `name` becomes ambiguous.
- **Fix:** Use the `virtual` keyword when inheriting from the base class (e.g., `class Engineer : virtual public Human`). This ensures only one shared copy of `Human` exists.

---

### **Code Snippets**

### **Combined Code (One-Shot Example)**

This code combines the concept of Hierarchical (one parent, multiple kids) and Multilevel inheritance.

```cpp
#include <iostream>
using namespace std;

// Hierarchical Inheritance: Human -> Student, Human -> Teacher
class Human {
    protected:
        string name;
        int age;
    public:
        Human(string n, int a) : name(n), age(a) {}
        void displayBasic() { cout << "Name: " << name << ", Age: " << age << endl; }
};

class Student : public Human {
    int roll_number;
    public:
        Student(string n, int a, int r) : Human(n, a), roll_number(r) {}
        void displayStudent() {
            displayBasic();
            cout << "Roll No: " << roll_number << endl;
        }
};

class Teacher : public Human {
    int salary;
    public:
        Teacher(string n, int a, int s) : Human(n, a), salary(s) {}
        void displayTeacher() {
            displayBasic();
            cout << "Salary: " << salary << endl;
        }
};

int main() {
    cout << "--- Student (Hierarchical) ---" << endl;
    Student s1("Rohit", 20, 101);
    s1.displayStudent();

    cout << "\n--- Teacher (Hierarchical) ---" << endl;
    Teacher t1("Mohit", 35, 50000);
    t1.displayTeacher();

    return 0;
}
```

http://googleusercontent.com/youtube_content/13
