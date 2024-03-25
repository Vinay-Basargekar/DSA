// Check if its a ArmStrong number or not.

#include<iostream>
using namespace std;

void ReverseNum(int n){
    int sum=0;
    while(n>0){
        int r = n%10;
        sum = sum + (r*r*r);
        n = n/10;
    }
    if(sum == n){
        cout << "Armstrong number";
    }else{
        cout <<"Not a Armstrong number";
    }
}

int main(){
    ReverseNum(153);
}