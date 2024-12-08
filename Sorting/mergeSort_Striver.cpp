#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high) {
    int temp[high - low + 1]; // Temporary array to store merged elements
    int left = low;          // Starting index for the left subarray
    int right = mid + 1;     // Starting index for the right subarray
    int k = 0;               // Index for the temporary array

    // Merge the two sorted subarrays
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp[k++] = arr[left++];
        } else {
            temp[k++] = arr[right++];
        }
    }

    // Copy any remaining elements from the left subarray
    while (left <= mid) {
        temp[k++] = arr[left++];
    }

    // Copy any remaining elements from the right subarray
    while (right <= high) {
        temp[k++] = arr[right++];
    }

    // Copy the sorted elements back into the original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(int arr[], int low, int high) {
    if (low >= high) {
        return;
    }

    int mid = (low + high) / 2;

    // Divide the array into two halves
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    // Merge the sorted halves
    merge(arr, low, mid, high);
}

int main() {
    int n;
    cout << "Enter the size: ";
    cin >> n;

    int arr[n];

    cout << "Enter the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
