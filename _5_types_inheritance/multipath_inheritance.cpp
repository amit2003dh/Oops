//  **4. Multipath Inheritance (Diamond Problem & Virtual Fix)**

// Without `virtual`, `CodeTeacher` would have two copies of `name` (one from `Engineer`-\>`Human` and one from `Youtuber`-\>`Human`).

#include <iostream>
using namespace std;

// Base Class
class Human
{
public:
    string name;
};

// Virtual Inheritance to prevent duplicate copies of Human
class Engineer : virtual public Human
{
public:
    string specialization;
};

class Youtuber : virtual public Human
{
public:
    int subscribers;
};

class CodeTeacher : public Engineer, public Youtuber
{
public:
    int salary;

    CodeTeacher(string name, string specialization, int subscribers, int salary)
    {
        this->name = name; // Now unambiguous due to 'virtual'
        this->specialization = specialization;
        this->subscribers = subscribers;
        this->salary = salary;
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Specialization: " << specialization << endl;
        cout << "Subscribers: " << subscribers << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main()
{
    CodeTeacher A1("Rohit", "CSE", 49000, 99);
    A1.display();
    return 0;
}
