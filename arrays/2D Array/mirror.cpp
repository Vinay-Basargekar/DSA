#include <iostream>
using namespace std;

// Function to reverse the elements in each row of the matrix
void reverseMatrix(int arr[][100], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        int start = 0;
        int end = cols - 1;
        while (start < end)
        {
            // Swap elements in the current row
            swap(arr[i][start], arr[i][end]);
            start++;
            end--;
        }
    }
}

int main()
{
    int rows, cols;
    cout << "Enter number of rows and columns for the matrix: ";
    cin >> rows >> cols;

    int arr[100][100];

    // Reading input for the matrix elements
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> arr[i][j];
        }
    }

    // Convert the matrix into its mirror image
    reverseMatrix(arr, rows, cols);

    // Print the mirror image of the matrix
    cout << "Mirror image of the matrix:" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
