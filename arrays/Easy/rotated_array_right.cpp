#include<iostream>
using namespace std;

int main(){
    int arr[] = {1,2,3,4,5};
    int k;
    cin >> k;
    int temp[5];
    int n = sizeof(arr) / sizeof(arr[0]);
    for(int i=0 ; i < n ; i++){
        temp[(i+k) % n] = arr[i];
    }
    for(int i=0 ; i<n ; i++){
        cout << temp[i];
    }
}