// #### **2. Multilevel Inheritance**

// `Manager` inherits from `Employee`, which inherits from `Person`.

// ```cpp
#include <iostream>
using namespace std;

class Person
{
protected:
    string name;

public:
    void introduce() { cout << "Hello my name is " << name << endl; }
};

class Employee : public Person
{
protected:
    int salary;

public:
    void monthly_salary() { cout << "My monthly salary is " << salary << endl; }
};

class Manager : public Employee
{
    string department;

public:
    Manager(string name, int salary, string department)
    {
        this->name = name;
        this->salary = salary;
        this->department = department;
    }
    void work() { cout << "I am leading the " << department << " department " << endl; }
};

int main()
{
    Manager A1("Rohit", 200, "Finance");
    A1.introduce();      // From Person
    A1.monthly_salary(); // From Employee
    A1.work();           // From Manager
    return 0;
}
