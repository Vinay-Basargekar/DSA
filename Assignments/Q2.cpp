// Create a Dynamic array to store N integers and write a menu driven C++ program to
// perform following operations.
// a) Quick Sort
// b) Merge Sort

#include<iostream>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (i <= j)
    {
        while (i <= j && arr[i] <= pivot)
        {
            i++;
        }
        while (i <= j && arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    arr[low] = arr[j];
    arr[j] = pivot;
    return j;
}

void QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);
        QuickSort(arr, low, pivotIndex - 1);
        QuickSort(arr, pivotIndex + 1, high);
    }
}

void Merge(int arr[], int l, int mid, int h)
{
    int i = l;
    int j = mid + 1;
    int k = l;
    int temp[100];
    while (i <= mid && j <= h)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
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

void divide(int arr[], int l, int h)
{
    if (l < h)
    {
        int mid = (h + l) / 2;
        divide(arr, l, mid);
        divide(arr, mid + 1, h);
        Merge(arr, l, mid, h);
    }
}

int main(){
    int n;
    cout <<"Enter the size: "; cin >> n;
    int *arr = new int[n];
    cout << "Enter the array: ";
    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
    }
    int choice;
    while(choice != 3){
        cout << "Menu \n";
        cout << "1. Quick sort \n";
        cout << "2. Merge sort \n";
        cout << "3. Exit...\n";
        cout << "Enter the choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            QuickSort(arr, 0, n - 1);
            cout << "The Sorted array: ";
            for (int i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
            break;
        case 2:
            divide(arr, 0, n - 1);
            cout << "Sorted array: ";
            for (int i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
            break;
        case 3:
            cout << "Exiting...";
            return 0;
        default:
            cout << "Invalid choice! Please enter a valid choice.\n";
            break;
        }
    }
}