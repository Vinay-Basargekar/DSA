#include<iostream>
using namespace std;

int main(){
    int *arr,n;
    cout << "Enter the number of elements: "; cin >> n;
    arr = new int[n];
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    //Selection sort!!
    for(int i=0 ; i<n ;i++){
        int minIndex = i;    //Assigining First element as minimum element!!
        for(int j=i+1 ; j<n ; j++){
            //Traversing in loop to check minimum element!
            if(arr[j] < arr[minIndex]){   
                minIndex = j;
            }
        }
        // swaping if min element found!!
        swap(arr[i],arr[minIndex]);
    }
    cout << "Sorted array from selection sort: ";
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i]<<" ";
    }
    
}