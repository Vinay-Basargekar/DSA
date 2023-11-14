#include <iostream>
using namespace std;

int main()
{
    const int max = 100;
    int arr[max], n, i;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter " << n << "values one by one: " << endl;
    for (i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int key;
    cout << "Enter the key: ";
    cin >> key;

    int start, end, mid;
    start = 0;
    end = n - 1;
    while (start <= end){
        mid = (start + end) / 2;
        
        if (key == arr[mid]){
            cout << "Item Found";
            return 0;
        }
        if (key > arr[mid]){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }

    cout << "Item not found";
    return 0;
}