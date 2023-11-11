#include<iostream>
using namespace std;

//Lower Case to all character
char lowercase(char name){

    if(name >= 'a' && name<= 'z'){
        return name;
    }
    else{
        char temp = name - 'A' + 'a';
        return temp;
    }
}

bool checkPalindrome(string s){
    int start = 0;
    int end = s.size() - 1;
    while (start < end)
{
        if ((s[start] >= 33 && s[start] <= 47) || (s[start] >= 58 && s[start] <= 64) || isspace(s[start]))
        {
            start++;
            continue;
        }
        if ((s[end] >= 33 && s[end] <= 47) || (s[end] >= 58 && s[end] <= 64) || (isspace(s[end]))){
            end--;
            continue;
        }
        if (lowercase(s[start]) != lowercase(s[end])){
            return false;
        }

        else{
            start++;
            end--;
        }
    }
    return true;
}

int get_length(char name[]){
    int count=0;
    for (int i = 0; name[i]!='\0'; i++)
    {
        count++;
    }
    return count;
}

int main(){
    char name[20];
    cout << "Enteer a string to reverse: ";
    cin.getline(name,20);
    int n = get_length(name);
    cout << checkPalindrome(name);
    return 0;
}