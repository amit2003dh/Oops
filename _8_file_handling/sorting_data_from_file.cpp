// #### **3. Sorting Data from a File**

// This reads unsorted numbers from a file, sorts them, and saves the sorted list back to the file.

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> // For sort()
using namespace std;

int main()
{
    // ---- PART 1: WRITING INITIAL DATA ----
    ofstream fout("numbers.txt"); // Constructor can also open file
    fout << "5 1 4 2 8";
    fout.close();

    // ---- PART 2: READING & SORTING ----
    ifstream fin;
    fin.open("numbers.txt");

    vector<int> arr;
    int num;

    // Read integers until file ends
    while (fin >> num)
    {
        arr.push_back(num);
    }
    fin.close();

    // Sort the vector
    sort(arr.begin(), arr.end());

    // ---- PART 3: WRITING SORTED DATA BACK ----
    fout.open("numbers.txt"); // Re-open to overwrite/append
    fout << "Sorted Data: \n";

    for (int i = 0; i < arr.size(); i++)
    {
        fout << arr[i] << " ";
    }

    fout.close();

    cout << "Numbers sorted and saved to file!" << endl;
    return 0;
}
