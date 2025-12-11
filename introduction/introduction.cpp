#include <iostream>
using namespace std;

// ==========================================
// 1. Class Definition & Encapsulation
// ==========================================
class Student
{
    // Private members: Cannot be accessed directly from outside
private:
    string name;
    int age;
    int roll_number;
    string grade;

    // Public members: Methods to access and modify private data
public:
    // Setter with Validation
    void setName(string s)
    {
        if (s.size() == 0)
        {
            cout << "Invalid Name: Name cannot be empty" << endl;
            return;
        }
        name = s;
    }

    void setAge(int a)
    {
        if (a < 0 || a > 100)
        {
            cout << "Invalid Age" << endl;
            return;
        }
        age = a;
    }

    void setRollNumber(int r)
    {
        roll_number = r;
    }

    void setGrade(string g)
    {
        grade = g;
    }

    // Getter methods
    void getDetails()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll No: " << roll_number << endl;
        cout << "Grade: " << grade << endl;
    }

    // Example of restricted access (Password protected getter)
    string getGradeSecure(int pin)
    {
        if (pin == 123)
            return grade;
        return "Access Denied";
    }
};

// ==========================================
// 2. Class for Padding/Greedy Alignment Demo
// ==========================================
class PaddingDemo
{
    char c; // 1 byte
    int i;  // 4 bytes (Compiler adds 3 bytes padding after 'c')
    char d; // 1 byte (Compiler adds 3 bytes padding after 'd')
            // Expected: 1 + 4 + 1 = 6 bytes
            // Actual size due to padding: 12 bytes (typically)
};

class GreedyAlignment
{
    int i;  // 4 bytes
    char c; // 1 byte
    char d; // 1 byte
            // Padding adds 2 bytes at the end
            // Actual size: 8 bytes (More optimized)
};

class Empty
{
};

int main()
{
    // ==========================================
    // 3. Static Allocation (Stack Memory)
    // ==========================================
    cout << "--- Static Allocation (Stack) ---" << endl;
    Student s1;
    s1.setName("Rohit"); // Using Setter
    s1.setAge(10);
    s1.setRollNumber(21);
    s1.setGrade("A+");

    s1.getDetails(); // Using Getter

    // Testing Validation
    cout << "\n[Validation Check]: ";
    s1.setAge(-5); // Should print "Invalid Age"

    // ==========================================
    // 4. Dynamic Allocation (Heap Memory)
    // ==========================================
    cout << "\n--- Dynamic Allocation (Heap) ---" << endl;
    Student *s2 = new Student; // Created using 'new' keyword

    // Accessing using Arrow Operator (->)
    s2->setName("Mohit");
    s2->setAge(12);
    s2->setRollNumber(121);
    s2->setGrade("B+");

    cout << "Name (via pointer): " << s2->getGradeSecure(123) << endl; // Checking secure getter
    s2->getDetails();

    // ==========================================
    // 5. Sizeof & Padding Concept
    // ==========================================
    cout << "\n--- Structure Padding & Size ---" << endl;
    cout << "Size of PaddingDemo class: " << sizeof(PaddingDemo) << " bytes" << endl;
    cout << "Size of GreedyAlignment class: " << sizeof(GreedyAlignment) << " bytes" << endl;

    // Empty Class Size
    Empty e;
    cout << "Size of Empty class: " << sizeof(e) << " byte" << endl;

    // Clean up heap memory
    delete s2;

    return 0;
}