#include<iostream>
using namespace std;

int main(){
    int *arr,n;
    cout <<"Enter no. of element: "; cin >> n;
    arr = new int[n];
    cout <<"Enter elements: ";
    for(int i=0 ; i<n ;i++){
        cin >> arr[i];
    }

    //bubble sort!
    for(int i=0 ; i<n-1 ; i++){
        for(int j=0 ; j<n-1-i ; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
    cout << "Sorted element: ";
    for(int i=0 ; i<n ; i++){
        cout << arr[i] <<" ";
    }
}