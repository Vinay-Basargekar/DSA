#include<iostream>
using namespace std;

int linearSearch(int arr[],int key,int size){
    int count=0;
    for (int i = 0; i < size; i++)
    {
        if (key == arr[i])
        {
            count++;
        }
    }
    return count;
}

int main(){
    int arr[] = {1,2,3,4,5};
    int key,c;
    cin >> key;

    c = linearSearch(arr,key,5);

    if(c==1){
        cout << "Found";
    }
    else{
        cout << "Not found";
    }
}