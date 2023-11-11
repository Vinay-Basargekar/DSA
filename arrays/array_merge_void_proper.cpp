#include <iostream>
using namespace std;

void merge(int p[], int q[], int n, int m)
{
    int c[n + m];
    for (int i = 0; i < n; i++)
    {
        c[i] = p[i];
    }
    for (int i = 0; i < m; i++)
    {
        c[n + i] = q[i];
    }
    for (int i = 0; i < n + m; i++)
    {
        cout << c[i] << " ";
    }
}

int main()
{
    int n, m;
    cout << "Enter the size of array1: ", cin >> n;
    cout << "Enter the size of array2: ", cin >> m;
    int *p, *q;
    p = new int[n];
    q = new int[m];
    cout << "Enter array 1: ";
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    cout << "Enter array 2: ";
    for (int i = 0; i < m; i++)
    {
        cin >> q[i];
    }
    merge(p, q, n, m);
}