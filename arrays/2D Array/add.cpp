#include <iostream>
using namespace std;

int main()
{
    const int size = 10;
    int arrA[size][size];
    int arrB[size][size];
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;
    //Input of a matrix
    cout << "Enter element of matrixA: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arrA[i][j];
        }
    }

    cout << "Enter element of matrixB: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arrB[i][j];
        }
    }

    //Addition of matrix 
    cout << "Addition of matrix: "<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arrA[i][j] + arrB[i][j] << " ";
        }
        cout << endl;
    }

    //Subtraction of Matrix
    cout << "Subtraction of matrix: "<<endl;
    for(int i=0 ; i<n ; i++){
        for(int j =0 ; j<n ; j++){
            cout << arrA[i][j] - arrB[i][j] << " ";
        }
        cout << endl;
    }
}