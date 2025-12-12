// #### **2. Protected Access Modifier**

// This example demonstrates that `protected` members can be accessed inside the child class but not from `main()`.

#include <iostream>
using namespace std;

class Human
{
protected: // Accessible in derived class, but not outside
    string name;
    int age;

public:
    void fun(string n, int a)
    {
        name = n;
        age = a;
    }
};

class Student : public Human
{
public:
    void display()
    {
        // Can access 'name' and 'age' because they are protected in parent
        cout << "Name: " << name << ", Age: " << age << endl;
    }

    // Helper to set values since they are protected
    void setDetails(string n, int a)
    {
        name = n;
        age = a;
    }
};

int main()
{
    Student A;

    // A.name = "Rohit"; // ERROR: 'name' is protected (inaccessible outside)

    A.setDetails("Rohit", 20); // Setting via member function
    A.display();               // Accessing via member function

    return 0;
}
