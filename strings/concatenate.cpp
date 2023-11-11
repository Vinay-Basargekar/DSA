#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char arr1[50],arr2[50];
    cout << "Enter array 1: "; cin >> arr1;
    cout << "Enter array 2: "; cin >> arr2;

    int i;
    for(i=0 ; arr1[i] != '\0' ;i++);
    arr1[i] = ' ';
    i++;

    int j=0;
    while(arr2[j] != '\0'){
        arr1[i] = arr2[j];
        i++;
        j++;
    }

    arr1[i] = '\0';
    
    cout << "Concatenated: "<<arr1;
}