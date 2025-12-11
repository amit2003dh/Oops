### **1. Introduction to Constructors**

The video begins by explaining that while `Class` and `Object` are the building blocks, **Constructors** are the mechanism that breathes life into objects by giving them valid initial data.

- **Definition:** A Constructor is a special member function used to initialize an object.
- **Key Properties:**
  - It has the **same name** as the class.
  - It has **no return type** (not even `void`).
  - It is **invoked automatically** the moment an object is created.
- **The Problem it Solves:** When an object is created without a constructor, its data members (variables) contain **garbage values**. Constructors allow us to replace these garbage values with meaningful data (e.g., setting an account balance to 0 instead of a random number).

### **2. Types of Constructors**

The instructor demonstrates how to implement different types of constructors:

- **Default Constructor:**
  - A constructor that takes **no arguments**.
  - If you do not define _any_ constructor, the C++ compiler automatically provides a hidden default constructor.
  - However, if you define _any_ constructor manually, the compiler **stops** providing the default one. You must define it yourself if needed.
- **Parameterized Constructor:**
  - Accepts arguments to initialize the object with specific values.
  - _Example:_ `Customer(string name, int balance)` allows creating a customer like `Customer A("Rohit", 1000);`.
- **Inline Constructor:**
  - Constructors defined inside the class body are implicitly inline.
- **Constructor Overloading:**
  - You can have multiple constructors in the same class as long as they have different parameters (different number or types of arguments). The compiler decides which one to call based on the arguments passed.

### **3. The `this` Pointer**

A common issue arises when the **parameter name** is the same as the **class member name**.

- _Scenario:_ `void setName(string name) { name = name; }`
- _Issue:_ The compiler gets confused and assigns the local variable to itself, leaving the class member unchanged.
- _Solution:_ Use the **`this` pointer**. It stores the **address of the current object**.
  - _Syntax:_ `this->name = name;` (This tells the compiler: "Put the parameter `name` into the `name` variable belonging to _this_ object").

### **4. Copy Constructor**

- **Purpose:** Used to create a new object as an exact copy of an existing object.
- **Syntax:** `ClassName(ClassName &obj)`
- **The "&" (Reference) Rule:** You **must** pass the object by reference (`&`).
  - _Reason:_ If you pass by value, the compiler will try to make a copy to pass it to the function. To make that copy, it calls the Copy Constructor again, creating an **infinite loop** of calls until the program crashes (Stack Overflow).
- **Default Copy Constructor:** If you don't write one, the compiler provides a "shallow copy" constructor. If you write one, you can implement "deep copy" logic (important for pointers).

### **5. Destructors**

- **Definition:** A special function executed when an object is destroyed.
- **Syntax:** Same name as the class but preceded by a **tilde (~)** (e.g., `~Customer()`).
- **Properties:**
  - No return type, no arguments.
  - Only **one** destructor per class.
  - Called automatically when the object goes out of scope.
- **Real Purpose (Resource Management):**
  - Many students think destructors simply "delete variables." The instructor clarifies that variables on the Stack are deleted automatically.
  - The **true purpose** is to release **Resources** acquired during the object's life, such as:
    - **Heap Memory** (allocated via `new`).
    - **Open Files**.
    - **Hardware connections** (like printers).
  - _Example:_ If a constructor did `ptr = new int[100];`, the destructor must do `delete[] ptr;` to prevent a **memory leak**.

### **6. Order of Execution (Constructor vs. Destructor)**

The video demonstrates the lifecycle order with a practical example:

- **Construction:** Follows the order of declaration (First In).
  - Object 1 Created -> Object 2 Created -> Object 3 Created.
- **Destruction:** Follows **Reverse Order** (Last In, First Out).
  - Object 3 Destroyed -> Object 2 Destroyed -> Object 1 Destroyed.
- _Reasoning:_ Newer objects often depend on older objects. If you destroy the older object first (Object 1), Object 3 might crash if it tries to access it during its own cleanup.

### **7. Static vs. Dynamic Allocation Cleanup**

- **Static Objects:** Created on the Stack (e.g., `Customer c1;`). Destructor is called **automatically** when the function ends.
- **Dynamic Objects:** Created on the Heap (e.g., `Customer *c2 = new Customer;`).
  - **Crucial Note:** The destructor is **NOT** called automatically.
  - You must explicitly write `delete c2;` to trigger the destructor and free the memory. If you forget this, the memory remains occupied even after the program ends (Memory Leak).
