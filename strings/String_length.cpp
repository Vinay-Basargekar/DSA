#include<iostream>
using namespace std;

int get_length(char array[])
{
    int count=0, i;
    for (i = 0; array[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

int main(){
    char array[20];
    cout << "Enter a name: ";
    cin >> array;
    cout << get_length(array);
}