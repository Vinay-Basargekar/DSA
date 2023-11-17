#include <iostream>
using namespace std;

bool linearSearch(int arr[], int size, int key){
    if (size == 0)
        return false; // Base case: element not found

    if (arr[0] == key)
        return true; // Base case: element found at the current index
    else
        return linearSearch(arr + 1, size - 1, key); // Recursive call
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int key;
    cin >> key;

    bool found = linearSearch(arr, 5, key); // Using bool directly to store the result

    if (found)
        cout << "Found";
    else
        cout << "Not found";
    return 0;
}
