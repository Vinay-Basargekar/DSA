#include <iostream>

int reverseNumber(int num, int reversedNum = 0) {
    if (num == 0) {
        return reversedNum;
    }
    int lastDigit = num % 10;
    reversedNum = reversedNum * 10 + lastDigit;

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
