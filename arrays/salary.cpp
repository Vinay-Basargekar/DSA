#include<iostream>
using namespace std;

int main() {
    const int max = 100;
    int salaries[max], n;
    int i;

    cout << "Enter the number of employees: ";
    cin >> n;

    cout << "Enter salaries of " << n << " employees: " << endl;
    for (i = 0; i < n; i++) {
        cin >> salaries[i];
    }

    cout << "Employees paying tax (salary > 20000):" << endl;
    for (i = 0; i < n; i++) {
        if (salaries[i] > 20000) {
            cout << "Employee " << i + 1 << ": Salary - " << salaries[i] <<endl;
        }
    }
    return 0;
}

