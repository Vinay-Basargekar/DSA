#include <iostream>
using namespace std;

bool linearSearch(int arr[3][3], int key)
{
    // Loop through the 2D array to find the key
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (arr[i][j] == key){
                return true; // Key found, return true
            }
        }
    }
    return false; // Key not found, return false
}

int main(){
    const int rows = 3;
    const int cols = 3;
    int arr[rows][cols];

    // Input elements into the 2D array
    cout << "Enter elements for a 3x3 matrix:" << endl;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            cin >> arr[i][j];
        }
    }

    // Output the entered matrix
    cout << "Matrix entered:" << endl;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Input the element to be searched
    int key;
    cout << "Enter an element to be searched: ";
    cin >> key;

    // Perform linear search
    if (linearSearch(arr, key)){
        cout << "Element found!";
    }
    else{
        cout << "Element not found!";
    }
    return 0;
}
