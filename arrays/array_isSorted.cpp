#include<iostream>
using namespace std;

bool isSorted(int arr[],int size){
    if(size == 0 || size == 1){
        return true;
    }
    if(arr[0] > arr[1]){
        return false;
    }
    else{
        bool remainingpart = isSorted(arr+1,size-1);
        return remainingpart;
    }
}

int main(){
    // int arr[] = {1,3,4,5,6};
    int n;
    cout << "Enter no. of elements: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    bool ans = isSorted(arr,n);
    if(ans){
        cout << "Array is Sorted!!"<<endl;
    }
    else{
        cout << "Array is not Sorted!!" << endl;
    }
}