#include<iostream>
using namespace std;

void printNos(int i,int n){
    if(i>n){
        return;
    }
    printNos(i+1,n);
    cout << i << " ";
}
int main(){
    printNos(1,5);
}