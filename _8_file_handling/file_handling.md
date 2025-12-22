This video titled **"Lecture 77: File Handling in C++"** by **Coder Army** explains how to read from and write to files in C++, enabling data persistence (saving data permanently) instead of losing it when the program ends.

### **1. What is File Handling?**

- **Concept:** It's the process of storing data in a file (on the hard disk) using a C++ program.
- **Why use it?** Standard variables store data in RAM, which is volatile (data is lost when the program ends or the computer turns off). Files store data in Secondary Memory (Hard Disk), which is permanent.
- **Key Classes:**
  - `ofstream`: Used to **write** (output) to a file.
  - `ifstream`: Used to **read** (input) from a file.
  - `fstream`: Can be used for both reading and writing.

### **2. Writing to a File**

- **Step 1:** Create an object of `ofstream`.
- **Step 2:** Open the file using `.open("filename")`. If the file doesn't exist, it creates one.
- **Step 3:** Use the insertion operator `<<` to write data.
- **Step 4:** Close the file using `.close()` to release resources.

### **3. Reading from a File**

- **Step 1:** Create an object of `ifstream`.
- **Step 2:** Open the file.
- **Step 3:** Read data.
  - Use `>>` to read word by word (stops at spaces).
  - Use `.get()` to read character by character (includes spaces).
  - Use `getline()` to read line by line.
- **Step 4:** Close the file.

### **4. Real-World Application (Sorting Example)**

The video demonstrates a practical use case:

1.  Read a list of numbers from a file (e.g., `original.txt`).
2.  Store them in a vector/array in the program.
3.  Sort the vector using `sort()`.
4.  Write the sorted numbers back to the same file or a new file.

---

### **Code Snippets**

http://googleusercontent.com/youtube_content/19
