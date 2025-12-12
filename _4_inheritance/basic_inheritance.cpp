// #### **1. Basic Inheritance (Public Mode)**

// This code shows how `Student` inherits `name`, `age`, and `weight` from `Human`.

#include <iostream>
using namespace std;

// Base Class
class Human
{
public:
    string name;
    int age;
    int weight;
};

// Derived Class inheriting from Human publicly
class Student : public Human
{
public:
    int roll_number;
    int fees;
};

int main()
{
    Student A;
    // Accessing inherited members
    A.name = "Rohit";
    A.age = 20;
    A.weight = 70;

    // Accessing own members
    A.roll_number = 10;
    A.fees = 12000;

    cout << "Name: " << A.name << ", Age: " << A.age << endl;
    return 0;
}
