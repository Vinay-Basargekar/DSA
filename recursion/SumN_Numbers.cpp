#include<iostream>
using namespace std;

void printSum(int i,int sum){
    if(i<1){
        cout << sum;
        return;
    }
    printSum(i-1,sum+i);
}

int main(){
    printSum(5,0);
}