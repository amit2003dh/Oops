// #### **1. Single Inheritance**

// `Student` inherits `name` and `age` from `Human`.

// ```cpp
#include <iostream>
using namespace std;

class Human
{
protected:
    string name;
    int age;

public:
    Human() {} // Default constructor required if not calling parameterized one
    Human(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
};

class Student : public Human
{
    int roll_number;
    int fees;

public:
    // Calling Parent Constructor
    Student(string name, int age, int roll_number, int fees) : Human(name, age)
    {
        this->roll_number = roll_number;
        this->fees = fees;
    }

    void display()
    {
        cout << name << " " << age << " " << roll_number << " " << fees << endl;
    }
};

int main()
{
    Student s1("Rohit", 26, 32, 99);
    s1.display();
    return 0;
}
