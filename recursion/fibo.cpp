#include<iostream>
using namespace std;

int fibo(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    
    return fibo(n - 1) + fibo(n - 2);
}

int main() {
    int n;
    cout << "Enter the number of terms in the Fibonacci series: ";
    cin >> n;

    cout << "Fibonacci Series: ";
    for (int i = 0; i < n; i++) {
        int result = fibo(i);
        cout << result << " ";
    }

    cout << endl;

    int nthFib = fibo(n);
    cout << "Fibonacci(" << n << ") = " << nthFib << endl;

    return 0;
}
