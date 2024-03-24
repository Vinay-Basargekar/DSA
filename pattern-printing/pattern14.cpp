// A
// A B
// A B C
// A B C D

#include<iostream>
using namespace std;

void pattern(int n){
    for(int i=1 ; i<=n ; i++){
        for(char ch = 'A' ; ch<='A'+ i ; ch++){
            cout << ch << " ";
        }
        cout << endl;
    }
}

int main(){
    pattern(4);
}