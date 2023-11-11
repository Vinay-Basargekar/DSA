#include<iostream>
using namespace std;

int main(){
    int *arr,n;
    cout << "Enter no. of elements: "; cin >> n;
    arr = new int[n];
    cout << "Enter array: ";
    for(int i = 0 ; i<n ; i++){
        cin >> arr[i];
    }

    //Selection sort
    for(int i=0 ; i<n-1 ; i++){
        int min = arr[i]; //set minimium array to first element! 
        int pos = i;
        for(int j=i+1 ; j<n ; j++){
            //check for min element in array if any!
            if(arr[j] < min){
                min = arr[j];
                pos = j;
            }
        }
        //swaping array!
            arr[pos] = arr[i];
            arr[i] = min;
    }
    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
}