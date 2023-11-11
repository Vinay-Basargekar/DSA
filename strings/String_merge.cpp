#include<iostream>
using namespace std;

int main(){
    char n1[50],n2[20];
    cout << "Enter string 1: ";
    cin>>n1;
    cout << "Enter string 2: ";
    cin>>n2;
    
    int i;
    for( i=0; n1[i]!='\0';i++);
    
    n1[i]=' ';
    i++;
    
    int j;
    while( n2[j] != '\0'){
        n1[i]=n2[j];
        i++;
        j++;
    }
    n1[i] = '\0';
    cout << "Concatenated: "<<n1;
    return 0;
}