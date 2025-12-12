This video, "Lecture 76: Exception Handling in C++ | Try | Catch | Throw" by Coder Army, explains how to handle runtime errors gracefully in C++ to prevent abrupt program termination.

### **1. Introduction to Exception Handling**

  * **What is an Exception?** An unexpected problem that arises during the execution of a program (runtime) which causes the program to terminate suddenly.
  * **Real-life Analogy:** The 2019 Cricket World Cup Final.
      * Rule 1: Win by runs/wickets.
      * Exception 1: Match Tie -\> Solution: Super Over.
      * Exception 2: Super Over Tie -\> Solution: Boundary Count.
      * This illustrates handling unexpected situations with predefined fallback rules.
  * **Why do we need it?** Standard `if-else` checks can handle simple logic errors, but Exception Handling (`try-catch`) is cleaner, more readable, and separates error-handling code from core logic, especially for critical issues like memory failure (`bad_alloc`) or logical errors like division by zero.

### **2. Core Keywords**

  * **`try`:** A block of code that might throw an exception. You place risky code here.
  * **`throw`:** Used to signal that an exceptional condition has occurred. This transfers control to a `catch` block.
  * **`catch`:** A block that handles the exception thrown by the `try` block.

### **3. Key Examples Covered**

#### **A. Division by Zero (Basic)**

Instead of the program crashing or producing undefined behavior, we detect if the denominator is zero and `throw` an exception string.

#### **B. Memory Allocation Failure (`bad_alloc`)**

Demonstrates what happens when you try to allocate an impossibly large array using `new`. The system throws a `std::bad_alloc` exception, which can be caught to display a friendly error message instead of a crash.

#### **C. Catching All Exceptions**

Using `catch (...)` allows you to catch *any* type of exception if a specific handler isn't found. This acts as a default safety net.

#### **D. Custom Exception Classes**

You can create your own exception classes by inheriting from `std::exception` or `std::runtime_error`. This makes error messages more meaningful (e.g., `InvalidAmountError` or `InsufficientBalanceError`) compared to generic strings.

-----

http://googleusercontent.com/youtube_content/17
