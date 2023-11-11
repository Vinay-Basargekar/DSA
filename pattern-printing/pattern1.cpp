#include<iostream>
using namespace std;

int main(){
    int i,n;
    cin>>n;
    i=1;
    while(i<=n){
        int j;
        for(int j=1;j<=n;j++){
            cout<<j;
        }
        i++;
        cout<<endl;
    }
}