#include<iostream>
using namespace std;

int main(){
    int i,n;
    cin>>n;
    i=1;
    while(i<=n){
        int j;
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        i++;
        cout<<endl;
    }
}