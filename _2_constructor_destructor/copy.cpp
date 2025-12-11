#include <iostream>
using namespace std;

class Student
{
public:
    string name;
    int *cgpaPtr; // Pointer variable

    // Constructor
    Student(string n, int cgpa)
    {
        name = n;
        cgpaPtr = new int(cgpa); // Allocating memory on Heap
    }

    // ---------------------------------------------------------
    // SCENARIO 1: SHALLOW COPY (Default behavior if we don't write this)
    // ---------------------------------------------------------
    // Student(const Student &obj) {
    //     this->name = obj.name;
    //     this->cgpaPtr = obj.cgpaPtr; // Copies only the ADDRESS!
    // }

    // ---------------------------------------------------------
    // SCENARIO 2: DEEP COPY (Custom Copy Constructor)
    // ---------------------------------------------------------
    Student(const Student &obj)
    {
        this->name = obj.name;
        // 1. Allocate NEW memory
        this->cgpaPtr = new int;
        // 2. Copy the VALUE, not the address
        *this->cgpaPtr = *obj.cgpaPtr;
    }

    void display()
    {
        cout << "Name: " << name << " | CGPA: " << *cgpaPtr << " | Address: " << cgpaPtr << endl;
    }
};

int main()
{
    Student s1("Rohit", 9);
    Student s2 = s1; // Copy Constructor called

    cout << "Before Change:" << endl;
    s1.display();
    s2.display();

    // Changing s1's CGPA
    *s1.cgpaPtr = 5;

    cout << "\nAfter Change (If Deep Copy, s2 remains 9):" << endl;
    s1.display();
    s2.display();

    return 0;
}