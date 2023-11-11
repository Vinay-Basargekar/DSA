#include <iostream>
using namespace std;

const int size = 10;

// Function to perform matrix addition
void addition_matrix(int arrA[size][size], int arrB[size][size], int n)
{
    // Addition of matrices
    cout << "Addition of matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arrA[i][j] + arrB[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int arrA[size][size];
    int arrB[size][size];
    int n;

    cout << "Enter size of matrix: ";
    cin >> n;

    // Input for matrix A
    cout << "Enter elements of matrix A: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arrA[i][j];
        }
    }

    // Input for matrix B
    cout << "Enter elements of matrix B: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arrB[i][j];
        }
    }

    // Call the addition_matrix function
    addition_matrix(arrA, arrB, n);

    return 0;
}
