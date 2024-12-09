#include<iostream>
using namespace std;

int main(){
    int *arr,n;
    cout << "Enter the size of array: "; cin >> n;
    cout << "Enter the elements: " << endl;
    arr = new int[n];
    for(int i = 0 ; i<n ; i++){
        cin >> arr[i];
    }
    
    int largest = arr[0];
    for (int i = 0; i < n; i++)
    {
        if(arr[i] > largest){
            largest = arr[i];
        }
    }
    cout << "Largest element of array is: "<<largest;
    

}