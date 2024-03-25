#include<iostream>
using namespace std;

int main(){
    int n,count;
    cin >> n;
    for(int i=1 ; i<=n ;i++){
        if(n%i == 0){
            count++;
        }
    }
    if(count == 2){
        cout << "Prime no.";
    }else{
        cout << "Not a prime no.";
    }
}