#include<iostream>
using namespace std;

int main(){
    string s = "abcdabefc";

    int hash[26] = {0};
    for(int i=0; i<s.length(); i++){
        hash[s[i] - 'a']++;
    }

    cout << "Enter number of queries: ";
    int q = 5;

    while(q--){
        char c;
        cin >> c;
        if (c >= 'a' && c <= 'z') {
            cout << "Frequency of " << c << " is: " << hash[c - 'a'] << endl;
        } else {
            cout << "Please enter only lowercase letters (a-z)" << endl;
        }
    }
}