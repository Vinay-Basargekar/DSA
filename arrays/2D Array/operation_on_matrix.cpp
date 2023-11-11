#include <iostream>
using namespace std;

int main()
{
    const int MAX = 100;
    int matrixA[MAX][MAX];
    int matrixB[MAX][MAX];
    int result[MAX][MAX];
    int rows = 3, cols = 3;

    // Input elements into the first 3x3 matrix
    cout << "Enter elements for the first 3x3 matrix:" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> matrixA[i][j];
        }
    }
    // Output the first entered matrix
    // cout << "First matrix entered:" << endl;
    // for (int i = 0; i < rows; i++)
    // {
    //     for (int j = 0; j < cols; j++)
    //     {
    //         cout << matrixA[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // Input elements into the second 3x3 matrix
    cout << "Enter elements for the second 3x3 matrix:" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> matrixB[i][j];
        }
    }
    // Output the second entered matrix
    // cout << "Second matrix entered:" << endl;
    // for (int i = 0; i < rows; i++)
    // {
    //     for (int j = 0; j < cols; j++)
    //     {
    //         cout << matrixB[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int choice;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Saddle Point\n";
        cout << "5. Transpose of Matrix A\n";
        cout << "6. Transpose of Matrix B\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            // Addition
            // Implement matrix addition here
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    result[i][j] = matrixA[i][j] + matrixB[i][j];
                }
            }
            // Output the addition result
            cout << "Addition Result:" << endl;
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    cout << result[i][j] << " ";
                }
                cout << endl;
            }
            break;
        case 2:
            // Subtraction
            // Implement matrix subtraction here
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    result[i][j] = matrixA[i][j] - matrixB[i][j];
                }
            }
            // Output the Subtraction result
            cout << "Subtraction Result:" << endl;
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    cout << result[i][j] << " ";
                }
                cout << endl;
            }
            break;
        case 3:
            // Multiplication
            // Implement matrix multiplication here
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    result[i][j] = 0;
                    for (int k = 0; k < cols; k++)
                    {
                        result[i][j] += matrixA[i][k] * matrixB[k][j];
                    }
                }
            }
            // Output the Multiplication result
            cout << "Multiplication Result:" << endl;
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    cout << result[i][j] << " ";
                }
                cout << endl;
            }
            break;
        case 4:
            // Saddle Point
            // Implement findSaddlePoint function here
            break;
        case 5:
            // Transpose of Matrix A
            // Implement transpose of matrix A here
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    cout << matrixA[j][i] << " ";
                }
                cout << endl;
            }
            break;
        case 6:
            // Transpose of Matrix B
            // Implement transpose of matrix B here
            break;
        case 0:
            // Exit the program
            cout << "Exiting program. Goodbye!";
            break;
        default:
            cout << "Invalid choice. Please try again.";
        }
    } while (choice != 0);

    return 0;
}
