#include<iostream>
using namespace std;

int main(){
    int n1,n2,gcd=0;
    cout <<"Enter a num1: ";
    cin >> n1;
    cout <<"Enter a num2: ";
    cin >> n2;
    for(int i=1 ; i<=n1 ; i++){
        if(n1%i==0 && n2%i==0){
            gcd = i;
        }
    }
    cout <<"gcd of "<<n1<<" and "<<n2<<" is: "<< gcd;
}
