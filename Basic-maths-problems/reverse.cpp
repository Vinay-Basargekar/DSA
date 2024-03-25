// reverse of a given number. If the number include zeroes at the end remove it and print the number only for ex. 1670 the reverse will be 761 instead of 0761.

#include<iostream>
using namespace std;

int ReverseNum(int n){
    int sum=0;
    while(n>0){
        int r = n%10;
        n = n/10;
        sum = sum*10 + r;
    }
    return sum;
}

int main(){
    cout << ReverseNum(1980);
}