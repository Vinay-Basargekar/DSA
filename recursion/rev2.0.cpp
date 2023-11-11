#include <iostream>

// Function to reverse a number using recursion
int reverseNumber(int num, int reversedNum = 0) {
    // Base case: If the number becomes 0, return the reversed number
    if (num == 0) {
        return reversedNum;
    }

    // Extract the last digit from the number
    int lastDigit = num % 10;

    // Add the last digit to the reversed number
    reversedNum = reversedNum * 10 + lastDigit;

    // Recursive call with the remaining part of the number
    return reverseNumber(num / 10, reversedNum);
}

int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    int reversed = reverseNumber(num);
    std::cout << "Reversed number: " << reversed << std::endl;

    return 0;
}
