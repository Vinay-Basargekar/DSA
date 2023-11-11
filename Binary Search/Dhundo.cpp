#include <iostream>
using namespace std;

int main()
{
    const int max = 100;
    int arr[max], n, i;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter " << n << " 4values one by one: " << endl;
    for (i = 0; i < n; i++)
    {
        cin >> arr[n];
    }
    int key;
    cout << "Enter the key: ";
    cin >> key;

    int start, end, mid;
    start = 0;
    end = n - 1;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (start == end)
        {
            break;
        }
        if (key > arr[mid])
        {
            start = mid + 1;
        }
        if (key < arr[mid])
        {
            end = mid - 1;
        }
    }
    if (start <= end)
    {
        cout << "Item found";
    }
    else
    {
        cout << "Item noy found";
    }
}