#include<iostream>
using namespace std;

int main(){
    const int size=10;
    int arr[size][size];
    int n;
    cout <<"Enter the order of matrix: "; cin>>n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        int s = 0;
        for (int j = 0; j < n; j++)
        {
            s = s + arr[i][i];
        }
        cout << s <<endl;
    }
}