### 1\. Difference Between Compile-time and Runtime Polymorphism

| Feature         | Compile-time Polymorphism (Static Binding)                                | Runtime Polymorphism (Dynamic Binding)                                                      |
| :-------------- | :------------------------------------------------------------------------ | :------------------------------------------------------------------------------------------ |
| **Definition**  | The function to be invoked is determined by the compiler at compile time. | The function to be invoked is determined by the system at runtime.                          |
| **Mechanism**   | Achieved via **Function Overloading** and **Operator Overloading**.       | Achieved via **Virtual Functions** and **Function Overriding**.                             |
| **Binding**     | Uses **Early Binding** (address of function is known at compile time).    | Uses **Late Binding** (address of function is determined at runtime using v-table).         |
| **Speed**       | Execution is faster as there is no runtime overhead.                      | Execution is comparatively slower due to the overhead of looking up the virtual table.      |
| **Flexibility** | Less flexible; exact types must be known at compile time.                 | More flexible; allows working with generic base class pointers for different derived types. |

---

### 2\. Operator Overloading Example

Here is a unique example using a **`Vector2D`** class (representing a 2D coordinate point).

- **Binary `*`:** Multiplies two vectors (dot product logic for simplicity, or component-wise). Let's do **scalar multiplication** or component-wise for clarity. Let's stick to **component-wise multiplication** (x*x, y*y) for this demo.
- **Unary `-`:** Negates the coordinates (x becomes -x).

<!-- end list -->

```cpp
#include <iostream>
using namespace std;

class Vector2D {
private:
    int x, y;

public:
    // Constructor
    Vector2D(int xVal = 0, int yVal = 0) : x(xVal), y(yVal) {}

    // 1. Overloading Binary Multiply (*)
    // Multiplies corresponding components of two vectors
    Vector2D operator*(const Vector2D& other) {
        Vector2D result;
        result.x = this->x * other.x;
        result.y = this->y * other.y;
        return result;
    }

    // 2. Overloading Unary Minus (-)
    // Negates the current object's values
    Vector2D operator-() {
        return Vector2D(-x, -y);
    }

    void display() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Vector2D v1(5, 10);
    Vector2D v2(2, 3);

    // Using Binary Multiply (*)
    Vector2D v3 = v1 * v2;
    cout << "Multiplication Result: ";
    v3.display(); // Expected: (10, 30)

    // Using Unary Minus (-)
    Vector2D v4 = -v1;
    cout << "Unary Minus Result: ";
    v4.display(); // Expected: (-5, -10)

    return 0;
}
```

---

### 3\. Virtual Function Example (Runtime Polymorphism)

This example uses a **`PaymentGateway`** system. The base class has a virtual function `processPayment()`, and derived classes (`CreditCard`, `PayPal`) override it. The compiler doesn't know which payment method will be used until the program actually runs.

```cpp
#include <iostream>
using namespace std;

// Base Class
class PaymentMethod {
public:
    // Virtual Function
    // 'virtual' ensures the derived class function is called
    // even when accessed via a base class pointer.
    virtual void processPayment() {
        cout << "Processing generic payment..." << endl;
    }
};

// Derived Class 1
class CreditCard : public PaymentMethod {
public:
    void processPayment() override {
        cout << "Payment processed via Credit Card." << endl;
    }
};

// Derived Class 2
class PayPal : public PaymentMethod {
public:
    void processPayment() override {
        cout << "Payment processed via PayPal." << endl;
    }
};

int main() {
    PaymentMethod* paymentPtr; // Base class pointer

    CreditCard cc;
    PayPal pp;

    // Pointing to CreditCard object
    paymentPtr = &cc;
    // Calls CreditCard::processPayment() because of Virtual Function mechanism
    paymentPtr->processPayment();

    // Pointing to PayPal object
    paymentPtr = &pp;
    // Calls PayPal::processPayment()
    paymentPtr->processPayment();

    return 0;
}
```

**Key Takeaway from Code:**
Without the `virtual` keyword in the base class, `paymentPtr->processPayment()` would have printed "Processing generic payment..." both times (Early Binding). Because we used `virtual`, C++ checked the actual object type at runtime (Late Binding) and called the correct function.
