#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char name1[] = "riyaz";
    char julie[] = "julie";

    // Concatenate the two strings using strcat
    char result[50]; // Make sure it's large enough to hold the concatenated string
    strcpy(result, name1);
    strcat(result, julie);

    // Print the concatenated string
    cout << result << endl;

    return 0;
}
