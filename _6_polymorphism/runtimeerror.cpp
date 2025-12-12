// #### **3. Runtime Polymorphism (Virtual Functions)**

// Demonstrating how `virtual` ensures the correct function is called.

// ```cpp
#include <iostream>
#include <vector>
using namespace std;

// Base Class (Abstract Class)
class Animal
{
public:
    // Pure Virtual Function
    virtual void speak() = 0;
};

class Dog : public Animal
{
public:
    void speak()
    {
        cout << "Bark" << endl;
    }
};

class Cat : public Animal
{
public:
    void speak()
    {
        cout << "Meow" << endl;
    }
};

int main()
{
    // Pointer of Base class pointing to Derived class object
    Animal *p;
    p = new Dog();
    p->speak(); // Outputs "Bark" because of virtual function logic

    // Using vector to store different animals
    vector<Animal *> animals;
    animals.push_back(new Dog());
    animals.push_back(new Cat());

    // Loop works for ALL animal types dynamically
    for (int i = 0; i < animals.size(); i++)
    {
        animals[i]->speak();
    }
    // Output:
    // Bark
    // Meow

    return 0;
}
