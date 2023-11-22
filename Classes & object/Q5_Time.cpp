#include <iostream>
using namespace std;

class Time
{
    int hr, min, sec;

public:
    // Default constructor 
    Time(){
        hr = 0;
        min = 0;
        sec = 0;
    }
    // Parameterized constructor 
    Time(int x, int y, int z){
        hr = x;
        min = y;
        sec = z;
    }

    // Function to calculate sum of time
    void SumTime(Time &t1, Time &t2)
    {
        sec = t1.sec + t2.sec; // Adding seconds
        min = sec / 60;        // Calculating minutes from seconds
        sec %= 60;             // Remaining seconds

        min += t1.min + t2.min; // Adding minutes
        hr = min / 60;          // Calculating hours from minutes
        min %= 60;              // Remaining minutes

        hr += t1.hr + t2.hr; // Adding hours
    }

    // Function to display time
    void displayTime(){
        cout << hr << " hours " << min << " minutes " << sec << " seconds";
    }
};

int main()
{
    Time t1(1, 20, 25); 
    Time t2(1, 30, 55); 
    Time t3;            

    t3.SumTime(t1, t2); 
    t3.displayTime();   
    return 0;
}
