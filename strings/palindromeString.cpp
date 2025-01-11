#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string& str) {
    string reversedStr = str;
    reverse(reversedStr.begin(),reversedStr.end()) ;
    return reversedStr == str;
}

int main() {
    string str = "vinay";

    if (isPalindrome(str)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }
    return 0;
}
