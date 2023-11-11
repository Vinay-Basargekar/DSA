#include <iostream>
using namespace std;

int main()
{
    const int size = 10;
    int arr1[size][size];
    ;
    int n;
    cout << "Enter order: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr1[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr1[j][i] << " ";
        }
        cout << endl;
    }
}