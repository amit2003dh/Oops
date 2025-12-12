
// #### **2. Reading from a File (Character by Character)**

// This reads `zoom.txt` and prints its content, including spaces.

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // 1. Create Object for reading
    ifstream fin;

    // 2. Open the file
    fin.open("zoom.txt");

    char c;
    // 3. Read char by char until End of File (EOF)
    c = fin.get(); // Reads first char (handling spaces)

    while (!fin.eof())
    {                  // Loops until end of file
        cout << c;     // Print char
        c = fin.get(); // Read next char
    }

    // 4. Close the file
    fin.close();

    return 0;
}