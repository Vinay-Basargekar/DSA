#include<iostream>
using namespace std;

int main(){
    int arr[] = {1,3,5,2,4,8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int largest = arr[0];
    int slargest = -1;
    for(int i=1 ; i<n ; i++){
        if(largest < arr[i]){
            slargest = largest;
            largest = arr[i];
        }
        else if(slargest < arr[i] && arr[i] < largest){
            slargest = arr[i];
        }
    }
    cout << slargest;
    return 0;
}