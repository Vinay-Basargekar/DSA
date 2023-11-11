#include <iostream>
using namespace std;

// Function to calculate and display row sums of a 2D array
void calculateRowSums(int arr[3][3])
{
    for (int i = 0; i < 3; i++){
        int rowSum = 0;
        // Calculate sum of current row
        for (int j = 0; j < 3; j++){
            rowSum += arr[i][j];
        }
        // Display sum of current row
        cout << "Sum of row " << i + 1 << ": " << rowSum << endl;
    }
}

int main(){
    int arr[3][3];
    // Input elements into the 2D array
    cout << "Enter elements for a 3x3 matrix:" << endl;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cin >> arr[i][j];
        }
    }
    // Output the entered matrix
    cout << "Matrix entered:" << endl;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    // Function call
    calculateRowSums(arr);
    return 0;
}
