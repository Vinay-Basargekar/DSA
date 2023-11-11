#include<iostream>
using namespace std;

void reverse(char str[],int n){
    char temp = 0;
    for(int i=0 ; i<n/2 ; i++){
        temp = str[i];
        str[i] = str[n-i-1];
        str[n-i-1] = temp;
    }
    cout <<"Reverse of string is: ";
}
int length(char str[]){
    int count = 0;
    for(int i=0 ; str[i] != '\0' ; i++){
        count++;
    }
    return count;
}

int main(){
    char str[50];
    cout << "Enter a string: "; cin >> str;
    int l = length(str);
    reverse(str,l);
    cout << str;
}