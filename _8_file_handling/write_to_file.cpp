// #### **1. Writing to a File**

// This creates a file named `zoom.txt` and writes "Hello India" into it.

#include <iostream>
#include <fstream> // Required library for file handling
using namespace std;

int main()
{
    // 1. Create Object for writing
    ofstream fout;

    // 2. Open the file (Creates 'zoom.txt' if it doesn't exist)
    fout.open("zoom.txt");

    // 3. Write data to the file
    fout << "Hello India";
    fout << "\nHello Coder Army"; // \n for new line

    // 4. Close the file (Good practice)
    fout.close();

    cout << "Data written successfully." << endl;
    return 0;
}
