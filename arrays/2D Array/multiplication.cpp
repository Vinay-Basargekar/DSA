#include<iostream>
using namespace std;

int main(){
    const int size = 10;
    int arr1[size][size];
    int arr2[size][size];
    int result[size][size];
    int n;
    cout << "Enter order: "; cin >> n;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            cin >> arr1[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr2[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {   
            result[i][j] = 0;
            for(int k=0 ; k<n ;k++){
                result[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << result[i][j]<<" ";
        }
        cout << endl;
    }
}