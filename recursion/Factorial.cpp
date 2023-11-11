#include <iostream>
using namespace std;

int factorial(int n){
    
    if(n==0){
        return 1;
    }
    int fact;
    fact = n * factorial(n-1);
    return fact;
}

int main()
{
    int n,v;
    cin >> n;
    v = factorial(n);    
    cout <<"factoria is :" << v;
    return 0;
}