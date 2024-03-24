//   *  
//   * *
//   * * *  
//   * *
//   *   

#include<iostream>
using namespace std;

void pattern5(int n){
    for(int i=1 ; i<n ; i++){
        for(int j=1 ; j< i+1 ; j++){
            cout <<"* ";
        }
        cout << endl;
    }
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n-i ; j++){
            cout << "* ";
        }
        cout << endl;
    }
}

int main(){
    pattern5(3);
}