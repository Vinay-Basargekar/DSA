#include<iostream>
using namespace std;

void Reverse(char array[],int n){
        int s = 0;
        int e = n - 1;
        while(s < e){
            swap(array[s++],array[e--]);
        }
}
int get_length(char array[])
{
    int count = 0, i;
    for (i = 0; array[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

int main(){
    char array[20];
    cout << "Enter a string to reverse: ";
    cin >> array;
    int l = get_length(array);
    Reverse(array,l);
    cout << array;
}