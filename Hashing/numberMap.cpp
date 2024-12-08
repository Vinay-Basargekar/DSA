#include <iostream>
#include <map>
using namespace std;

// Function to calculate the hash value of a number
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    cout << "Original array: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Precompute frequencies
    map<int, int> mp;
    for (int i = 0; i < 5; i++) {
        mp[arr[i]]++;
    }

    cout << "Enter number of queries: ";
    int q = 5;
    // cin >> q;
    cout << "\nEnter " << q << " numbers to find their frequencies:" << endl;
    
    while (q--) {
        int num;
        cin >> num;
        // Fetch and print the result
        cout << "Frequency of " << num << " is: " << mp[num] << endl;
    }
}