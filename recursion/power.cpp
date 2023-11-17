#include<iostream>
#include <cmath>
using namespace std;

int power(int n,int a){
    
    if(n==0){
        return 1;
    }
    double num = a * pow(a, n - 1); // Calculate 2^(n-1) using pow function}
    return num;
}
    
int main(){
    
    int n,a;
    cout << "enter the number : ";
    cin >> a;
    cout << "enter the power of number : ";
    cin >> n;
    int p = power(n,a);
    cout << p << endl;
}