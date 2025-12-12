// #### **1. Basic Division by Zero**

// This example prevents a crash when dividing by zero.

// ```cpp
#include <iostream>
using namespace std;

int main()
{
    int a = 10, b = 0;

    try
    {
        if (b == 0)
        {
            throw "Division by zero is not possible!";
        }
        int c = a / b;
        cout << c << endl;
    }
    catch (const char *e)
    {
        cout << "Exception Occurred: " << e << endl;
    }

    return 0;
}
