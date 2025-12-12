// #### **4. Reading Line by Line (using `getline`)**

// Useful for reading full sentences or paragraphs.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream fin;
    fin.open("zoom.txt");

    string line;

    // Read line by line
    while (getline(fin, line))
    {
        cout << line << endl;
    }

    fin.close();
    return 0;
}
