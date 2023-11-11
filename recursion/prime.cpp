#include <iostream>
#include <cmath>

using namespace std; // Add this line to use the std namespace

// Function to check if a number is prime using recursion
bool isPrime(int num, int divisor = 2) {
    // Base case: If the number is less than 2, it's not prime
    if (num < 2) {
        return false;
    }

    // Base case: If the divisor becomes greater than the square root of num, it's prime
    if (divisor > sqrt(num)) {
        return true;
    }

    // If num is divisible by the current divisor, it's not prime
    if (num % divisor == 0) {
        return false;
    }

    // Recursive call with the next divisor
    return isPrime(num, divisor + 1);
}

int main() {
    int num;
    cout << "Enter a positive integer: ";
    cin >> num;

    if (isPrime(num)) {
        cout << num << " is a prime number." << endl;
    } else {
        cout << num << " is not a prime number." << endl;
    }

    return 0;
}
