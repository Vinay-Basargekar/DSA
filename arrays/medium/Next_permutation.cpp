#include <iostream>
#include <algorithm> // For reverse and swap
using namespace std;

int main() {
    int nums[] = {2, 1, 5, 4, 3, 0, 0};
    int n = sizeof(nums) / sizeof(nums[0]);

    int index = -1;
    // Find the breakpoint where nums[i] < nums[i + 1]
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            index = i;
            break;
        }
    }

    // If there is no breakpoint, reverse the entire array
    if (index == -1) {
        reverse(nums, nums + n); // Correct usage for arrays
    } else {
        // Find the element just greater than nums[index]
        for (int i = n - 1; i > index; i--) {
            if (nums[i] > nums[index]) {
                swap(nums[i], nums[index]);
                break;
            }
        }
        // Reverse the rest of the array after the breakpoint
        reverse(nums + index + 1, nums + n);
    }

    // Output the resulting array
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
