#include<iostream>
using namespace std;

int main(){
    int arr[] = {3,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    // Initialize 2 variables;
    int count = 0,el;

    // Moore's Voting Algorithm
    for(int i=0 ; i<n ; i++){
        if(count == 0){
            count = 1;
            el = arr[i];
        }
        else if(arr[i] == el){
            count++;
        }else{
            count--;
        }
    }
    int count1 = 0;
    for(int i=0 ; i<n ; i++){
        if(arr[i] == el){
            count1++;
        }
    }
    // for an majority element it must be greater than n/2
    if(count1 > n/2){
        cout << el;
    }else{
        cout << -1;
    }
}