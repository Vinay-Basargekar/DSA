#include<iostream>
using namespace std;

int main(){
    // const int size = 10;
    int m,n;
    cout <<"Enter the order of matrix: "; cin >> m >> n;
    int a[m][n];
    cout <<"Enter element for Matrix: "<<endl;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }    
    }
    cout <<"The matrix is: "<< endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}