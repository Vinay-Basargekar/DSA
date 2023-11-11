#include<iostream>
using namespace std;

int main(){
    int a1,a2;
    int a[]={6,4,3,7,1};
    int b[]={8,9,2,4,1};
    int c[10];
    for(int i=0;i<5;i++){
        c[i] = a[i];
        c[i+5] = b[i];
    }
    for(int i=0;i<10;i++){
        cout << c[i];
        cout<< ' ';
    }
    
}