#include<iostream>
using namespace std;

int printSum(int n){
    if(n==0){
        return 0;
    }
    return n + printSum(n-1); 
}

int main(){
    int sum = printSum(3);
    cout << "Sum of number: " << sum;
}