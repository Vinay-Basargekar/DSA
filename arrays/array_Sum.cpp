#include<iostream>
using namespace std;

int sum(int n[], int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum = sum + n[i];
    }
    return sum;
}

int main() {
    // const int max = 100;
    // int num[max], n, i;
    // cout << "Enter number of values: " ;
    // cin >> n;
    // cout << "Enter " << n << " values one by one :" << endl;
    // for(i = 0; i < n; i++) {
    //     cin >> num[i];
    // }
    // cout << "Sum of the array: " << sum(num, n) << endl;

    //Dyanamic array    
    int n;
    cout << "Enter the no. of elements of matrix: "; cin >> n;
    int *a;
    a = new int[n];
    cout <<"Enter the elements: ";
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
    }
    cout << "Sum of array is: " << sum(a,n);
}
