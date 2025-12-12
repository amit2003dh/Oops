 Polymorphism and Virtual Function in C++" by Coder Army, dives deep into the concept of Polymorphism in C++, covering both Compile-time and Runtime polymorphism.

### **1. What is Polymorphism?**

  * **Definition:** Derived from Greek words meaning "many forms". It allows entities (like functions or operators) to behave differently based on the context.
  * **Real-world Analogy:** A man can be a father, a husband, an employee, or a son depending on the context, even though he is the same person.

### **2. Types of Polymorphism**

  * **Compile-time Polymorphism (Static):**
      * **Function Overloading:** Multiple functions with the same name but different parameters (number or type).
      * **Operator Overloading:** Giving special meaning to standard operators (like `+`, `-`) for user-defined data types.
  * **Runtime Polymorphism (Dynamic):**
      * **Virtual Functions:** Functions defined in a base class that can be overridden in a derived class. The decision of which function to call is made at runtime based on the type of object pointed to.

### **3. Function Overloading (Compile-time)**

  * **Concept:** You can have multiple functions named `area`. One might calculate the area of a circle (taking 1 radius parameter) and another for a rectangle (taking 2 parameters: length, breadth).
  * **Mechanism:** The compiler decides which function to call based on the arguments passed during compilation.

### **4. Operator Overloading (Compile-time)**

  * **Concept:** Standard operators like `+` work for integers (`2+3=5`) and strings (`"Hello"+"World"="HelloWorld"`). Operator overloading allows us to define how `+` works for custom objects like Complex numbers (`c1 + c2`).
  * **Implementation:** We define a special function named `operator+` inside the class.

### **5. Virtual Functions (Runtime)**

  * **The Problem:** If you have a base class pointer pointing to a derived class object (e.g., `Animal *p = new Dog();`) and call `p->speak()`, it calls the *base class* version (`Animal::speak`), not the derived one (`Dog::speak`). This happens because the link is static (early binding) based on the pointer type.
  * **The Solution:** Use the **`virtual`** keyword in the base class function. This tells the compiler to decide which function to call at *runtime* (late binding) based on the actual object type.
  * **Virtual Table (vtable):** A mechanism used internally by the compiler to support dynamic dispatch.

### **6. Pure Virtual Functions & Abstract Classes**

  * **Pure Virtual Function:** A function with no implementation in the base class, declared as `virtual void fun() = 0;`.
  * **Abstract Class:** A class containing at least one pure virtual function. You **cannot create objects** of an abstract class. It is meant to be inherited from, enforcing that derived classes *must* implement the specific function.

-----

http://googleusercontent.com/youtube_content/15
