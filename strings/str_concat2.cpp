#include <iostream>
#include <cstring>
using namespace std;

void concat(char *p1, char *p2) {
    int i, j;
    for (i = 0; p1[i] != '\0'; i++);
    p1[i] = ' ';
    i++;
    for (j = 0; p2[j] != '\0'; j++) {
        p1[i++] = p2[j];
    }
    // Null-terminate the concatenated string
    p1[i] = '\0';
    // while(p2[j] != '\0'){
    //     p1[i] = p2[j];
    //     j++;
    //     i++;
    // }
    // p1[i] = '\0';
}

int main() {
    char a1[50], a2[20];
    cout << "Enter name1: ";
    cin >> a1;
    cout << "Enter name2: ";
    cin >> a2;

    concat(a1, a2);

    cout << "Concatenated string: " << a1 << endl;

    return 0;
}
