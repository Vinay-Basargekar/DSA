#include<iostream>
using namespace std;

int main(){
    const int size = 10;
    int arr[size][size];
    int n;
    cout << "Enter size of matrix: "; cin >> n;
    cout << "Enter element of matrix: " << endl;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            cin >> arr[i][j];
        }
    }
    cout <<"The matrix is: " << endl;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}