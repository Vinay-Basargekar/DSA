#include<vector>
#include<iostream>
using namespace std;

vector<int> FindIntersection(int arr1[], int arr2[], int n, int m){
    int i = 0,j = 0;
    vector<int> temp;
    while(i<n && j<m){
        if(arr1[i] > arr2[j]){
            i++;
        }
        else if(arr1[i] < arr2[j]){
            j++;
        }
        else{
            temp.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    return temp;
}

int main(){
    int n = 10, m = 7;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {2, 3, 4, 4, 5, 11, 12}; 
    vector < int > intersection = FindIntersection(arr1, arr2, n, m);
    cout << "Union of arr1 and arr2 is  " << endl;
    for (auto & val: intersection)
        cout << val << " ";
    return 0;
}
