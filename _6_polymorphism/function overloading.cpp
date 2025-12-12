// #### **1. Function Overloading**

// Same function name `calculateArea` handles different shapes.

// ```cpp
#include <iostream>
using namespace std;

class Area
{
public:
    // Overloaded function for Circle
    int calculateArea(int r)
    {
        return 3.14 * r * r;
    }

    // Overloaded function for Rectangle
    int calculateArea(int l, int b)
    {
        return l * b;
    }
};

int main()
{
    Area A;
    cout << "Circle Area: " << A.calculateArea(4) << endl;       // Calls 1st function
    cout << "Rectangle Area: " << A.calculateArea(3, 4) << endl; // Calls 2nd function
    return 0;
}
