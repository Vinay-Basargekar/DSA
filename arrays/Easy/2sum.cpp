#include<iostream>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
    return {}; // No solution found
}

int main(){
    vector<int> arr = {2,7,11,15};
    int target = 9;

    vector<int> Sum = twoSum(arr,target);

    if (!Sum.empty()) {
        cout << "Indices: " << Sum[0] << ", " << Sum[1] << endl;
    } else {
        cout << "No solution found." << endl;
    }
}