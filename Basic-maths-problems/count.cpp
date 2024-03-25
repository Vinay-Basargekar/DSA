//Count the number of digits in a number.

#include<iostream>
using namespace std;

int countNum(int n){
    int count = 0 ;
    while(n>0){
        // int last = n % 10;
        count++;
        n = n / 10;
    }
    return count;
}

int main(){
    cout << countNum(1234123124);
}

// TC : O(logbase10 N)