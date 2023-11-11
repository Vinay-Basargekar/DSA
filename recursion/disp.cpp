#include<iostream>
using namespace std;

void disp(int n){
    if(n==0){
        return;
    }
    disp(n-1);
    cout << n << endl;
}

int main(){
    disp(5);
}