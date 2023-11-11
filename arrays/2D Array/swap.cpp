#include<iostream>
using namespace std;

int main(){
    int matrix[3][3];
    int n;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> matrix[i][j];
        }
    }
    int row1=0,row2=0;
    cout <<"Rows to swap: ";
    cin >> row1 >> row2;

    for(int i=0 ; i<3 ; i++){
        int temp = matrix[row1][i];
        matrix[row1][i] = matrix[row2][i];
        matrix[row2][i] = temp;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << matrix[i][j]<<" ";
        }
        cout << endl;
    }
}