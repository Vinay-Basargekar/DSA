#include<iostream>
using namespace std;

void Merge(int arr[],int l,int mid,int h){
    int i = l;
    int j = mid+1;
    int k = l;
    int temp[100];
    while(i <= mid && j <= h){
        if(arr[i] < arr[j]){
            temp[k] = arr[i];
            i++;
            k++;
        }
        else{
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= h)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (i = l; i <= h; i++)
    {
        arr[i] = temp[i];
    }
}

void divide(int arr[],int l,int h){
    if(l<h){
        int mid = (h + l) / 2;
        divide(arr, l, mid);
        divide(arr, mid + 1, h);
        Merge(arr,l,mid,h);
    }
}

int main(){
    int n;
    cout << "Enter the size: ";
    cin >> n;

    int *arr = new int[n];

    cout << "Enter the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    divide(arr, 0, n - 1);

    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}