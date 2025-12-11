#include <iostream>
using namespace std;

class Car
{
private:
    int year;
    double fuellevel;
    int speed;
    bool isRunning;
    string brand;

public:
    Car(int yr = 2020, double fuel = 50.0, string br = "Generic")
    {
        year = yr;
        fuellevel = fuel;
        speed = 0;
        isRunning = false;
        brand = br;
    }
    void start()
    {
        if (!isRunning)
        {
            isRunning = true;
            cout << "Car started." << endl;
            speed = 0;
        }
        else
        {
            cout << "Car is already running." << endl;
        }
    }
    void stop()
    {
        if (isRunning)
        {
            isRunning = false;
            speed = 0;
            cout << "Car stopped." << endl;
        }
        else
        {
            cout << "Car is already stopped." << endl;
        }
    }
    void accelerate(int increment)
    {
        if (isRunning)
        {
            speed += increment;
            cout << "Car accelerated. Current speed: " << speed << " km/h" << endl;
        }
        else
        {
            cout << "Start the car first to accelerate." << endl;
        }
    }
    void brake(int decrement)
    {
        if (isRunning)
        {
            speed -= decrement;
            if (speed < 0)
                speed = 0;
            cout << "Car decelerated. Current speed: " << speed << " km/h" << endl;
        }
        else
        {
            cout << "Start the car first to brake." << endl;
        }
    }
    void refuel(double amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid fuel amount." << endl;
            return;
        }
        fuellevel += amount;
        cout << "Car refueled. Current fuel level: " << fuellevel << " liters" << endl;
    }
    void printStatus()
    {
        cout << "Car Status:" << endl;
        cout << "Brand: " << brand << endl;
        cout << "Year: " << year << endl;
        cout << "Fuel Level: " << fuellevel << " liters" << endl;
        cout << "Speed: " << speed << " km/h" << endl;
        cout << "Running: " << (isRunning ? "Yes" : "No") << endl;
    }
};

int main()
{
    Car myCar(2021, 60.0);

    myCar.start();
    myCar.accelerate(50);
    myCar.brake(20);
    myCar.refuel(30);
    myCar.printStatus();
    myCar.stop();
    return 0;
}
