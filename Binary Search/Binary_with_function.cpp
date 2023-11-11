#include <iostream>
using namespace std;

int dhundo(int even[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {

        if (even[mid] == key)
        {
            return mid;
        }
        if (key > even[mid])
        {
            start = mid + 1;
        }
        if (key < even[mid])
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}

int main()
{
    int even[] = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << dhundo(even, 8, 8);
    return 0;
}