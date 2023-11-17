#include<iostream>
using namespace std;

bool Binarysearch(int arr[],int key,int s,int e){
    //base Case
    if(s>e)
        return false;

    int mid = (s+e)/2;

    if(arr[mid]==key)
        return true;

    if(key>arr[mid])
        return Binarysearch(arr,key,mid+1,e);
    else
        return Binarysearch(arr,key,s,mid-1);
}

int main(){
    int arr[] = {1,2,3,4,5};

    int c = Binarysearch(arr,5,0,5);
    if(c==0){
        cout << "Element not present";
    }
    else
        cout <<"present";
    return 0;
}