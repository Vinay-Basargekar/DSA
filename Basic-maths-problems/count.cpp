#include <iostream>
using namespace std;

// Function to count digits of n that divide n evenly
int countDivisibleDigits(int n) {
    int original = n;  
    int count = 0;

    while (n > 0) {
        int digit = n % 10; 
        if (digit != 0 && original % digit == 0) { 
            count++;
        }
        n = n / 10; 
    }
    return count;
}

int main() {
    int n = 2446; 
    cout << "Number of divisible digits in " << n << ": " << countDivisibleDigits(n) << endl;
    return 0;
}
