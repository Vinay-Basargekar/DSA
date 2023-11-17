#include <iostream>
using namespace std;

bool checkPalindrome(const string &str, int start, int end){
    // Base case
    if (start >= end)
        return true;

    if (str[start] != str[end])
        return false;
    else
        return checkPalindrome(str, start + 1, end - 1);
}

int main(){
    string name = "abccbba";

    bool isPalindrome = checkPalindrome(name, 0, name.length() - 1);

    if (isPalindrome){
        cout << "Palindrome";
    }
    else{
        cout << "Not a Palindrome";
    }
    return 0;
}
