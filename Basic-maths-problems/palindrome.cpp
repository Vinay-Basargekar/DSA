// check if it a palindrome or not.

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
    int n;
    cin >> n;
    if(n == ReverseNum(n)){
        cout<<"Its a palindrome!";
    }else{
        cout<<"Not a palindrome!";
    }
}