#include<iostream>
#include<vector>
using namespace std;

int maxOnes(int arr[],int n){
    int count = 0;
    int max = 0;
    for(int i=0 ; i<n ; i++){
        if(arr[i] == 1){
            count++;
            if(max < count){
                max++;
            }
        }else{
            count = 0;
        }
    }
    return max;
}

int main(){
    int arr[] = {1,0,1,1,0,0,1,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout <<  maxOnes(arr,n);

    // cout << Max_Ones;
    return 0;
}