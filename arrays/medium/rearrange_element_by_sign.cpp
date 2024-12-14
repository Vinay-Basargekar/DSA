#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> arr = {1,-2,3,-4,-1,4};
    int n = arr.size();
    vector<int> pos,neg;
    for(int i=0 ; i<n ; i++){
        if(arr[i] >= 0){
            pos.push_back(arr[i]);
        }else{
            neg.push_back(arr[i]);
        }
    }
    for(int i=0 ; i<n/2 ; i++){
        arr[i*2] = pos[i];
        arr[i*2+1] = neg[i];
    }
    for(int i=0 ; i<n ; i++){
        cout << arr[i] << " ";
    }
}