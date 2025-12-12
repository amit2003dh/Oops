// #### **2. Operator Overloading**

// Adding two complex numbers using the `+` operator.

#include <iostream>
using namespace std;

class Complex
{
    int real, imag;

public:
    Complex(int r = 0, int i = 0)
    {
        real = r;
        imag = i;
    }

    // Operator Overloading Function
    Complex operator+(Complex &C)
    {
        Complex ans;
        ans.real = real + C.real;
        ans.imag = imag + C.imag;
        return ans;
    }

    void display()
    {
        cout << real << " + i" << imag << endl;
    }
};

int main()
{
    Complex c1(3, 4), c2(2, 6);
    Complex c3 = c1 + c2; // Calls operator+ function
    c3.display();         // Output: 5 + i10
    return 0;
}
