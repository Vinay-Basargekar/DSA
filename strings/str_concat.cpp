#include<iostream>
#include<cstring>
using namespace std;

int main() {
    char a1[50], a2[20];
    cout << "Enter name1: ";
    cin >> a1;
    cout << "Enter name2: ";
    cin >> a2;

    int i;
    for (i = 0; a1[i] != '\0'; i++);
    // a1[i] = ' '; // Add a space after the first string
    // i++;

    int j = 0;
    while (a2[j] != '\0') {
        a1[i] = a2[j];
        i++;
        j++;
    }
    a1[i] = '\0'; // Null-terminate the concatenated string
    cout << "Concatenated string: " << a1 << endl;
    return 0;
}
