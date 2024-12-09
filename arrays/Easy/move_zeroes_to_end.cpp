#include<iostream>
using namespace std;

int main(){
    int arr[] = {1,0,4,5,7,0,0,0,2,3};
    // 2 pointer approach
    
    int n = sizeof(arr)/sizeof(arr[0]);
    int j = -1;
    // set j to first 0th index
    for(int i=0 ; i<n ; i++){
        if(arr[i] == 0){
            j = i;
            break;
        }
    }
    //iterate i along with j
    for(int i=j+1 ; i<n ; i++){
        if(arr[i] != 0 ){
            swap(arr[i],arr[j]);
            j++;
        }
    }
    for(int i=0 ; i<n ; i++){
        cout << arr[i];
    }
}