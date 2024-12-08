#include<iostream>
using namespace std;

int printName(int n){
    // if(n==0){
    //     return;
    // }
    // cout << "GFG ";
    // printName(n-1);
    if( n == 0){
        return 0;
    } 
    return (n*n*n) + printName(n-1);
}

int main(){
    printName(5);
}

// void printName(int i,int n){
//     if(i>n){
//         return;
//     }
//     cout << "Vinay ";
//     printName(i+1,n);
// }

// int main(){
//     printName(1,5);
// }