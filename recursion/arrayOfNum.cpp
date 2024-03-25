#include<iostream>
using namespace std;

void printNos(int x){
    if(x==0){
        return;
    }
    printNos(x-1);
    cout << x << " ";
}

int main(){
    printNos(5);
}