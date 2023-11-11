#include <iostream>
using namespace std;

int main()
{

    string bio;

    // Information logged to the console
    cout << "Tell us about yourself: ";

    /* This prompts the user to input a string and I typed in this: 				"JavaScript is my favorite language"
     */
    getline(cin,bio);

    /* When logging out the bio inputed above, only "JavaScript" was logged 		out
     */
    cout << "Your bio says: " << bio;
    // Your bio says: JavaScript
}