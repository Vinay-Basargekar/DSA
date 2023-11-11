#include<iostream>
using namespace std;

int printevenodd(int n){
    int rem;
    rem = n%2;
    return rem;
}

int main(){
    int n;
    cout << "Enter the number: "; cin >> n;
    
    if(printevenodd==0){
        cout << "even";
    }
    else{
        cout<<"odd";
    }
    
}