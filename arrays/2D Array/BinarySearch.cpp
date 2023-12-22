#include <iostream>
#include <algorithm>
using namespace std;

bool binarySearch(int arr[3][3], int key)
{
    int left = 0;
    int right = 3 * 3 - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int midValue = arr[mid / 3][mid % 3];

        if (midValue == key)
        {
            return true; // Key found
        }
        else if (midValue < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return false; // Key not found
}

int main()
{
    const int rows = 3;
    const int cols = 3;
    int arr[rows][cols];

    // Input elements into the 2D array
    cout << "Enter elements for a sorted 3x3 matrix:" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> arr[i][j];
        }
    }

    // Output the entered matrix
    cout << "Matrix entered:" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Input the element to be searched
    int key;
    cout << "Enter an element to be searched: ";
    cin >> key;

    // Perform binary search
    sort(&arr[0][0], &arr[0][0] + 3 * 3); // Sorting the 2D array
    if (binarySearch(arr, key))
    {
        cout << "Element found!";
    }
    else
    {
        cout << "Element not found!";
    }
    return 0;
}
