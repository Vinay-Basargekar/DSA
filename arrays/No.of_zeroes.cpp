#include <iostream>
using namespace std;

int main()
{
    // const int max = 100;
    // int num[max], i, n, count = 0, c = 0;
    int count = 0,c = 0, n;
    cout << "Enter the number of values: ";
    cin >> n;
    int *num;
    num = new int[n];
    cout << "Enter " << n << " values one by one:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
        if (num[i] > 0)
        {
            count++;
        }
        else if (num[i] == 0)
        {
            c++;
        }
    }

    cout << "Number of positive numbers: " << count << endl;
    cout << "Number of zeroes: " << c;

    return 0;
}
