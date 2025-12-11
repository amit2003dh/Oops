#include <iostream>
using namespace std;

class Laptop
{
private:
    double price;

    double screenSize; // in inches

    double batteryLife; // in hours
    int ram;            // in GB
    int storage;        // in GB
    bool isOn;
    string processor;
    string brand;
    string model;

public:
    Laptop(string br, string mo, double pr, double scSize, double batLife, int r, int stor, string proc)
    {
        brand = br;
        model = mo;
        price = pr;
        screenSize = scSize;
        batteryLife = batLife;
        ram = r;
        storage = stor;
        processor = proc;
        isOn = false;
    }
    void powerOn()
    {
        if (!isOn)
        {
            isOn = true;
            cout << "Laptop is now ON." << endl;
        }
        else
        {
            cout << "Laptop is already ON." << endl;
        }
    }
    void powerOff()
    {
        if (isOn)
        {
            isOn = false;
            cout << "Laptop is now OFF." << endl;
        }
        else
        {
            cout << "Laptop is already OFF." << endl;
        }
    }
    void chargeBattery(double hours)
    {
        batteryLife += hours;
        cout << "Battery charged. Current battery life: " << batteryLife << " hours." << endl;
    }
    void displaySpecs()
    {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Price: $" << price << endl;
        cout << "Screen Size: " << screenSize << " inches" << endl;
        cout << "Battery Life: " << batteryLife << " hours" << endl;
        cout << "RAM: " << ram << " GB" << endl;
        cout << "Storage: " << storage << " GB" << endl;
        cout << "Processor: " << processor << endl;
    }
};
int main()
{
    Laptop myLaptop("Dell", "XPS 13", 999.99, 13.3, 10, 16, 512, "Intel i7");
    myLaptop.displaySpecs();
    myLaptop.powerOn();
    myLaptop.chargeBattery(2);
    myLaptop.powerOff();
    return 0;
}