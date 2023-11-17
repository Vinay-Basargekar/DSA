#include <iostream>
using namespace std;

int sum(int arr[],int n){
    if(n==1){
        return arr[0];
    }
    return arr[n-1] + sum(arr , n -1 );
}

int main()
{
    // int arr[] = {1,3,4,5,6};
    int n;
    cout << "Enter no. of elements: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Sum of array is: " << sum(arr,n);
}