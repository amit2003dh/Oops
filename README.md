--

# 🚀 OOPS (Object-Oriented Programming)

## 1️⃣ Basics

* **Class** → Blueprint
* **Object** → Instance of class
* **Empty class size** → 1 byte (to ensure unique address)

---

# 🧠 Memory Concepts

### Structure Padding

* Due to data type alignment
* Arrange variables largest → smallest

  ```
  double → int → char
  ```

---

## Static vs Dynamic Memory

| Static                    | Dynamic              |
| ------------------------- | -------------------- |
| Allocated at compile time | Allocated at runtime |
| Stored in stack           | Stored in heap       |
| Auto destroyed            | Must delete manually |

```cpp
Class obj;            // Stack
Class* obj = new Class();  // Heap
delete obj;
```

---

# 🔧 Constructors

* Same name as class
* Used to initialize objects

## Types

### 1️⃣ Default Constructor

* No arguments
* Compiler provides if not defined

```cpp
ClassName() {}
```

### 2️⃣ Parameterized Constructor

```cpp
ClassName(int x) {}
```

### 3️⃣ Constructor Overloading

* Multiple constructors
* Different parameters

### 4️⃣ Inline Constructor

* Defined inside class body

---

## 🔹 this Pointer

* Stores address of current object

```cpp
this->name = name;
```

---

# 📋 Copy Constructor

Used to create new object from existing object.

```cpp
ClassName(const ClassName &obj) {}
```

⚠ Must pass by reference to avoid infinite loop.

---

# 🧹 Destructor

* Same name as class
* Prefixed with `~`
* No return type
* No arguments
* Only one allowed
* Automatically called when object goes out of scope

```cpp
~ClassName() {}
```

---

# 🧩 Static Members

* Declared using `static`
* Shared among all objects
* Accessed using scope resolution operator

```cpp
class Customer {
  static int totalCustomers;
};

int Customer::totalCustomers = 0;
```

* Static functions can access only static members
* Called without creating object

```cpp
Customer::getTotal();
```

---

# 🔐 Encapsulation

* Wrapping data + functions
* Make variables private
* Access using public methods

---

# 🎭 Abstraction

* Hiding implementation details
* Show only essential features

---

# 🧬 Inheritance

```cpp
class Child : access_modifier Parent {}
```

## Access Modifiers

| Type      | Accessible             |
| --------- | ---------------------- |
| public    | Everywhere             |
| protected | Within class + derived |
| private   | Only inside class      |

---

## Types of Inheritance

* Single
* Multilevel
* Multiple
* Hierarchical
* Hybrid

⚠ Diamond Problem → Solved using **virtual inheritance**

```cpp
class A {};
class B : virtual public A {};
```

---

# 🎭 Polymorphism

Means **many forms**

Allows objects to behave differently.

---

## Types

### 1️⃣ Compile-Time (Static)

✔ Function Overloading
✔ Operator Overloading

```cpp
int add(int a, int b);
float add(float a, float b);
```

---

### 2️⃣ Run-Time (Dynamic)

✔ Function Overriding
✔ Achieved using virtual function

```cpp
virtual void show();
```

---

# ⚠ Exception Handling

Used to handle runtime errors.

## Keywords

* `try` → risky code
* `throw` → throw error
* `catch` → handle error

```cpp
try {
   throw 10;
}
catch(int e) {
   cout << e;
}
```

* If type not specified → catches all

---

# 📁 File Handling (C++)

Library:

```cpp
#include <fstream>
```

---

## Streams

| Stream   | Purpose        |
| -------- | -------------- |
| ofstream | Write to file  |
| ifstream | Read from file |
| fstream  | Read & Write   |

---

## ✏ Writing to File

```cpp
ofstream file;
file.open("file.txt");
file << "Hello";
file.close();
```

Steps:

1. Create object
2. Open file
3. Write using `<<`
4. Close file

---

## 📖 Reading from File

```cpp
ifstream file("file.txt");
string data;
file >> data;       // word by word
getline(file, data); // line by line
file.close();
```

### Methods

* `>>` → stops at space
* `get()` → character by character
* `getline()` → full line

---

# 🎯 Quick Revision Summary

* Constructor → initializes object
* Destructor → cleans object
* Copy constructor → duplicate object
* Static → shared across objects
* Encapsulation → data hiding
* Abstraction → hide complexity
* Inheritance → reuse code
* Polymorphism → many behaviors
* Exception → handle runtime errors
* File handling → read/write files

---
