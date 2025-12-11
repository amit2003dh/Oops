Based on C++ Object Oriented Programming concepts (and expanding on the previous Coder Army context), here is the breakdown of **Shallow Copy** and **Deep Copy**.

### **1. Shallow Copy (The Default)**

A **Shallow Copy** copies the object's data member by member exactly as they are. This is what the compiler does by default if you do not write your own Copy Constructor.

- **How it works:** It copies the **values** of the variables.
- **The Problem:** If your class has a **Pointer**, it copies the _address_ held by the pointer, not the _data_ it points to.
- **Result:** Both objects (original and copy) point to the **same memory location**. If one object changes the data, the other is affected. If one deletes the memory, the other becomes a "dangling pointer" (causing a crash).

> **Analogy:** You scan a page of a notebook. You now have two sheets of paper (two objects), but they both refer to the same "page content". If you tear the original page, the copy still shows the tear.

### **2. Deep Copy**

A **Deep Copy** creates a completely independent copy of the object. This is not done by default; you must write a **Custom Copy Constructor** to achieve this.

- **How it works:** It allocates **new memory** for the copy and then copies the **actual data** from the original into this new memory.
- **The Benefit:** The objects are totally independent. Changing one does not affect the other.

> **Analogy:** You hand-write a brand new notebook page by reading the original. You now have two separate physical notebooks. If you tear the original page, your handwritten copy remains intact.

---

### **3. Code Example: Shallow vs. Deep**

Here is a C++ example showing the difference using a `Student` class with a pointer.

```cpp
#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int* cgpaPtr; // Pointer variable

    // Constructor
    Student(string n, int cgpa) {
        name = n;
        cgpaPtr = new int(cgpa); // Allocating memory on Heap
    }

    // ---------------------------------------------------------
    // SCENARIO 1: SHALLOW COPY (Default behavior if we don't write this)
    // ---------------------------------------------------------
    // Student(const Student &obj) {
    //     this->name = obj.name;
    //     this->cgpaPtr = obj.cgpaPtr; // Copies only the ADDRESS!
    // }

    // ---------------------------------------------------------
    // SCENARIO 2: DEEP COPY (Custom Copy Constructor)
    // ---------------------------------------------------------
    Student(const Student &obj) {
        this->name = obj.name;
        // 1. Allocate NEW memory
        this->cgpaPtr = new int;
        // 2. Copy the VALUE, not the address
        *this->cgpaPtr = *obj.cgpaPtr;
    }

    void display() {
        cout << "Name: " << name << " | CGPA: " << *cgpaPtr << " | Address: " << cgpaPtr << endl;
    }
};

int main() {
    Student s1("Rohit", 9);
    Student s2 = s1; // Copy Constructor called

    cout << "Before Change:" << endl;
    s1.display();
    s2.display();

    // Changing s1's CGPA
    *s1.cgpaPtr = 5;

    cout << "\nAfter Change (If Deep Copy, s2 remains 9):" << endl;
    s1.display();
    s2.display();

    return 0;
}
```

### **4. Comparison Summary**

| Feature          | Shallow Copy                               | Deep Copy                               |
| :--------------- | :----------------------------------------- | :-------------------------------------- |
| **Mechanism**    | Copies member values directly (default).   | Allocates new memory and copies values. |
| **Pointers**     | Copies the **Address** (Shared memory).    | Copies the **Value** (Separate memory). |
| **Speed**        | Faster (no new allocation).                | Slower (requires memory allocation).    |
| **Dependency**   | Objects are dependent (changes reflect).   | Objects are independent.                |
| **When to use?** | When no dynamic memory (pointers) is used. | When dynamic memory (pointers) is used. |

This video covers the concepts of Shallow and Deep copy with clear diagrams and code examples illustrating the memory differences.

[Shallow Copy and Deep Copy in C++](https://www.youtube.com/watch?v=tbtFKuTcZKs)

http://googleusercontent.com/youtube_content/2
