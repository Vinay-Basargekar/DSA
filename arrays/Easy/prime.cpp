#include <iostream>
using namespace std;

bool isPrime(int num)
{
    if (num <= 1)
    {
        return false;
    }
    for (int i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int array[5];
    cout << "Enter elements: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> array[i];
    }

    for (int i = 0; i < 5; i++)
    {
        if (isPrime(array[i]))
        {
            cout << array[i] << " ";
        }
    }

    return 0;
}
