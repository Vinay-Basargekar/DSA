#include <iostream>
using namespace std;

int Largest_row_sum(int arr[3][3]){
    int i, j;
    int largest=0;
    for( i=0 ; i<3 ;i++){
        int sum=0;
        for(j=0 ; j<3 ;j++){
            sum = sum + arr[i][j];
        }
        if(sum > largest){
            largest = sum;
            }
    }
    return largest;
}

int main()
{
    int arr[3][3];
    // Input elements into the 2D array
    cout << "Enter elements for a 3x3 matrix:" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }
    // Output the entered matrix
    cout << "Matrix entered:" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    // Function call
    cout <<"Largest row sum is: " << Largest_row_sum(arr);
    return 0;
}
