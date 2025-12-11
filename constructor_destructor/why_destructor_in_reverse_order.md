The short answer is: **Because local objects are stored in Stack Memory, which follows the LIFO (Last In, First Out) rule.**

Here is the detailed breakdown of why C++ operates this way.

### **1. The Stack Memory Concept**

When you create objects inside a function (like `main()`), they are allocated in the **Stack** memory segment.

- **Construction:** As you declare variables, they are "pushed" onto the stack one by one.
- **Destruction:** When the function ends (at the closing curly brace `}`), the stack must be "popped" to clear memory.
- **The Rule:** You can only remove the item that is currently at the top of the stack.

### **2. The "Dependency" Logic (Why it _must_ be this way)**

Imagine Object `B` is created _after_ Object `A`. It is very possible that **Object `B` depends on Object `A`**.

- If the compiler destroyed `A` first, then `B` might try to access `A` during its own destruction process (e.g., trying to save data to a file `A` opened).
- If `A` is already dead, `B` would crash.
- **Safety Rule:** To ensure safety, the "youngest" object (created last) is destroyed first because it might rely on the "older" objects.

### **3. Real World Analogy: Wearing Clothes**

Think of objects like layers of clothing:

1.  **Creation (Construction):** You put on your **Undershirt** (Obj 1), then your **Shirt** (Obj 2), then your **Jacket** (Obj 3).
2.  **Destruction (taking them off):** You cannot take off the Undershirt first. You must remove the **Jacket** (Obj 3) first, then the **Shirt** (Obj 2), and finally the **Undershirt** (Obj 1).
