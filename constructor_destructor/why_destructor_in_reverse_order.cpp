#include <iostream>
using namespace std;

class Entity
{
    int id;

public:
    // Constructor
    Entity(int i)
    {
        id = i;
        cout << "Object " << id << " Created (Constructor)" << endl;
    }

    // Destructor
    ~Entity()
    {
        cout << "Object " << id << " Destroyed (Destructor)" << endl;
    }
};

int main()
{
    // Creating objects sequentially
    Entity e1(1);
    Entity e2(2);
    Entity e3(3);

    cout << "--- End of Main Function ---" << endl;
    return 0;
    // Destructors are called automatically here
}

// **Output:**

// ```text
// Object 1 Created (Constructor)
// Object 2 Created (Constructor)
// Object 3 Created (Constructor)
// --- End of Main Function ---
// Object 3 Destroyed (Destructor)  <-- Last created, First destroyed
// Object 2 Destroyed (Destructor)
// Object 1 Destroyed (Destructor)
// ```

// ### **Summary**

// | Action           | Order                     | Memory Rule           |
// | :--------------- | :------------------------ | :-------------------- |
// | **Construction** | Top to Bottom (1 → 2 → 3) | Push to Stack         |
// | **Destruction**  | Bottom to Top (3 → 2 → 1) | Pop from Stack (LIFO) |

// **Next Step:** Since you are learning about memory management, would you like to see how **Static members** behave differently from normal members in terms of memory allocation?
