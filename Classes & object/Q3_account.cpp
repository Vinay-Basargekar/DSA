#include<iostream>
using namespace std;

class account{
    int bal; // Private member to store balance

public:
    account() { bal = 0; }      // Default constructor to initialize balance to 0
    account(int x) { bal = x; } // Parameterized constructor to set balance using provided value

    // Function to swap balances between two account objects
    void Swapping(account s){
        // int temp = bal;
        // bal = s.bal;
        // s.bal = temp;
        swap(bal, s.bal); // Swapping balances using swap function

        // Displaying balances after swapping
        cout << "Balance after Swapping: " << endl;
        cout << "Chintu's balance now: " << bal << endl; 
        cout << "Pintu's balance now: " << s.bal;
    }
};

int main(){
    cout << "Enter Balance of users: " << endl;
    int b1, b2;
    cout << "Chintu's Balance: "; cin >> b1; 
    cout << "Pintu's Balance: "; cin >> b2; 

    account chintu(b1), pintu(b2);
    chintu.Swapping(pintu); 
    return 0;
}
