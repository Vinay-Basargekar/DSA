
// A
// B B
// C C C

#include<iostream>
using namespace std;

void pattern(int n){
    char start = 'A';
    for(int i=0 ; i<=n ; i++){
        for(char ch = 'A' ; ch<='A'+ i ; ch++){
            cout << start << " ";
        }
        cout << endl;
        start++;
    }
}

int main(){
    pattern(4);
}