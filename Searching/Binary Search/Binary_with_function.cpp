#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key)
{
    int low = 0, high = size - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return 1;
        else if (key >= arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int key, c;
    cout << "enter the key: ";
    cin >> key;
    c = binarySearch(arr, 5, key);
    if (c == 1)
        cout << "Found!";
    else
        cout << "Not found";
}