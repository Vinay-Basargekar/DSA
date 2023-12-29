#include<iostream>
using namespace std;

// Test commment

int ap(int n){
    int b = 3*n + 7;
    return b;
}

int main(){
    int n;
    cout << "Enter the nth term: " << endl;
    cin >> n;
    
    int apwant = ap(n);
    cout << apwant;
    
}