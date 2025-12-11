# Object Oriented Programming in C++

### **1. Introduction to OOP**

- **What is OOP?**
  It is a programming approach where code is structured around **Objects** rather than just functions and logic.
- **History:**
  C++ was originally called "C with Classes" because it introduced the concept of classes to the C language. It was later renamed C++ to reflect it as an updated version of C.
- **Why use OOP?**
  It helps solve real-world problems more effectively by grouping related data and behaviors together, preventing code repetition (DRY principle), and adding data security.

---

### **2. Classes and Objects**

The concept is explained using a **Student** example:

#### **Class (The Blueprint)**

A Class is a user-defined data type that acts as a blueprint or template. It describes what an object will look like but does not exist in the physical world and consumes no memory (logically).

- _Example:_ A `Student` class defines that every student will have a `name`, `age`, `roll_number`, and `grade`.

#### **Object (The Entity)**

An Object is an instance of a class. It is a real-world entity that occupies memory and has specific values for the properties defined in the class.

- _Example:_ `Rohit` is an object of the `Student` class with specific data (Age: 10, Roll No: 21).

#### **Real-World Analogies**

- **Car:** The "Car" concept is a class (4 wheels, engine). A specific "i20" or "Nano" is an object.
- **Bank:** "Customer" is a class. You and I are specific objects of that class.

---

### **3. Implementation & Access Modifiers**

- **Defining a Class:**
  A class is defined using the `class` keyword. By default, members inside a class are **Private**.

#### **Access Modifiers**

- **Private:** Data cannot be accessed from outside the class. This ensures data security (Encapsulation).
- **Public:** Data can be accessed directly from outside the class using the dot operator (e.g., `s1.name`).

#### **Getters and Setters**

Since private data cannot be accessed directly, **Public** functions are used to read (Getters) and write (Setters) data.

- **Validation:** Setters allow you to add logic to validate data before saving it. For example, ensuring `age` is not 0 or negative, or requiring a "pin" code to access a grade.

---

### **4. Memory Allocation & Padding (Crucial Concept)**

This section details how objects are stored in memory:

- **Empty Class Size:**
  An empty class takes **1 byte** of memory, not 0, to ensure it has a unique address.

#### **Structure Padding**

The size of an object is often larger than the sum of its members due to **Structure Padding**.

- _Reason:_ The CPU reads memory in "words" (e.g., 4 bytes at a time for 32-bit OS). To minimize CPU cycles, the compiler adds empty bytes (padding) to align data members to addresses that are multiples of their size.
- _Example:_ A class with `char` (1 byte) and `int` (4 bytes) will not take 5 bytes. It will likely take **8 bytes** (1 byte for char + 3 bytes padding + 4 bytes for int).

#### **Greedy Alignment**

To minimize memory waste, you should order variables by size (largest to smallest).

- _Optimization:_ Placing `double` first, then `int`, then `char` minimizes the need for padding compared to mixing them up.

---

### **5. Static vs. Dynamic Memory Allocation**

#### **Static Allocation**

Creating an object normally. Memory is allocated on the **Stack**.

- _Syntax:_ `Student s1;`

#### **Dynamic Allocation**

Creating an object using the `new` keyword. Memory is allocated on the **Heap**.

- _Syntax:_ `Student *s = new Student();`
- **Accessing Members:** When using a pointer to an object, you access members using the arrow operator `->` (e.g., `s->name`) or by dereferencing `(*s).name`.

---

### **Final Takeaway**

OOP allows you to create custom data types that mirror real-world entities, secure your data using access modifiers, and manage memory efficiently through understanding padding and allocation types.

**Reference Video:** [Lecture 70: Object Oriented Programming in C++](https://youtu.be/iw1Xf_33YM0)

http://googleusercontent.com/youtube_content/0
