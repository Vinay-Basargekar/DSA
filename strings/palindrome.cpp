#include<iostream>
#include <cstring>
using namespace std;

bool checkpalindrome(char str[],int l){
    int s=0;
    int e=l-1;
    while(s<=e){
        if(str[s] = str[e] ){
            return 0;
        }
        else{
            s++;
            e--;
        }
    }
    return 1;
}

// int length(char str[]){
//     int count = 0;
//     for(int i=0 ; str[i] != '\0' ; i++){
//         count++;
//     }
//     return count;
// }

int main(){
    char str[50];
    cout << "Enter a string: "; cin >> str;
    // int l = length(str);
    int l = strlen(str);
    if(checkpalindrome(str,l)==0){
        cout<<"String is not a palindrome!";
    }
    else{
        cout<<"palindrome";
    }
    
}