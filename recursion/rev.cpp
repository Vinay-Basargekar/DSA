#include<iostream>
using namespace std;

int reverse(int num,int rev=0){
    if(num == 0){
        return rev;
    }
    int dig = num % 10;
    rev = rev * 10 + dig;
    return reverse(num/10,rev);
}

int main(){
    int num;
    cin >> num;
    
    cout << reverse(num);
}