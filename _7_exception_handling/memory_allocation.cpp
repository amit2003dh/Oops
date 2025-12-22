// #### **3. Handling Memory Allocation Failure (`bad_alloc`)**

// Catching standard library exceptions.

// ```cpp
#include <iostream>
#include <exception> // Required for exception handling
using namespace std;

int main()
{
    try
    {
        // Trying to allocate a huge amount of memory
        int *p = new int[100];
        cout << "Memory Allocation Successful" << endl;
        delete[] p;
    }
    catch (const exception &e)
    {
        // e.what() gives the description of the error
        cout << "Exception Occurred: " << e.what() << endl;
    }

    return 0;
}
