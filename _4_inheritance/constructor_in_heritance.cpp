// #### **3. Constructor in Inheritance**

// This shows how to initialize parent class data using the child class constructor.

#include <iostream>
using namespace std;

class Human
{
protected:
    string name;
    int age;

public:
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
    // Student Constructor calls Human Constructor explicitly
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
    Student A("Rohit", 20, 55, 12000);
    A.display();
    return 0;
}
