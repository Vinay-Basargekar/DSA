#include<iostream>
using namespace std;

void reverseArr(int arr[], int l, int r){
    if(l >= r){
        return;
    }
    swap(arr[l], arr[r]);
    reverseArr(arr, l+1, r-1);
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    reverseArr(arr, 0, 4);

    for(int i = 0; i < 5; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
