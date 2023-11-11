#include<iostream>
using namespace std;

int num_sum(int n){
    
    int sum = 0, rem = 0;
    
    while (n > 0) {
        rem = n % 10;   // Get the last digit of the number
        sum = sum + rem; // Add the last digit to the sum
        n = n / 10;      // Remove the last digit from the number
    }
    return sum;
}

int main(){
    
    int n;
    cin >> n;
    int s = num_sum(n);
    cout << s;
}