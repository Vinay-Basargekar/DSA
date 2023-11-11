#include<iostream>
using namespace std;

int main() {
    const int max = 100;
    double prices[max];
    int n, i;
    int costliestItemIndex = 0; 

    cout << "Enter the number of items: ";
    cin >> n;

    cout << "Enter prices of " << n << " items: " << endl;
    for (i = 0; i < n; i++) {
        cin >> prices[i];
        if (prices[i] > prices[costliestItemIndex]) {
            costliestItemIndex = i; 
        }
    }

    cout << "Price of the costliest item is: $" << prices[costliestItemIndex] << endl;
    return 0;
}
