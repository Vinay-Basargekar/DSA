#include<iostream>
#include<cstring>
using namespace std;

void concat(char *p1,char *p2){
    int i,j=0;
    for(i=0 ; p1[i] != '\0' ;i++);
    p1[i] =' ';
    i++;
    while(p2[j] != '\0'){
        p1[i] = p2[j];
        i++;
        j++;
    }
    p1[i] = '\0';
}

int main(){
    char str1[50],str2[50];
    cout<<"Enter string 1: "; cin>>str1;
    cout<<"Enter string 2: "; cin>>str2;
    concat(str1,str2);
    cout << str1;
}