#include <iostream>
using namespace std;

int main()
{
    const int rows = 3;
    const int cols = 3;
    int arr[rows][cols];
    int row, col;

    // Input for row-wise
    cout << "Enter elements for a 3x3 matrix row-wise:" << endl;
    for (row = 0; row < rows; row++)
    {
        for (col = 0; col < cols; col++)
        {
            cin >> arr[row][col];
        }
    }

    // Output row-wise
    cout << "Matrix entered row-wise:" << endl;
    for (row = 0; row < rows; row++)
    {
        for (col = 0; col < cols; col++)
        {
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }

    // Input for column-wise
    cout << "Enter elements for a 3x3 matrix column-wise:" << endl;
    for (col = 0; col < cols; col++)
    {
        for (row = 0; row < rows; row++)
        {
            cin >> arr[row][col];
        }
    }

    // Output column-wise
    cout << "Matrix entered column-wise:" << endl;
    for (row = 0; row < rows; row++)
    {
        for (col = 0; col < cols; col++)
        {
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }

    return 0;
}
