#include<iostream>
#include<cstring>
using namespace std;

void reverseString(string &str,int start,int end){

    //Base case
    if(start >= end){
        return;
    }

    swap(str[start],str[end]);
    start++;
    end--;

    //Recursive call
    reverseString(str,start,end);
}

int main(){
    string name = "vinay";
    cout << "Original string: " << name <<endl;

    reverseString(name,0,name.length()-1);

    cout <<"Reversed string: "<< name;
}