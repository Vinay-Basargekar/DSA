#include<iostream>
using namespace std;

int main(){
    int n,count;
    cin >> n;
    for(int i=1 ; i<=n ;i++){
        if(n%i == 0){
            cout << i << " ";
            count++;
        }
    }
    cout << endl;
    cout << "divisor: " << count;
}