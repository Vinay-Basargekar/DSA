// #include<iostream>
// using namespace std;

// int main() {
//     const int max = 100;
//     int city[max], n, cityage[max];
//     int i, oldestCityIndex = 0; 

//     cout << "Enter no. of cities: ";
//     cin >> n;
//     cout << "Enter " << n << " age of city: " << endl;
//     for (i = 0; i < n; i++) {
//         cin >> cityage[i];
//         if (cityage[i] > cityage[oldestCityIndex]) {
//             oldestCityIndex = i;
//         }
//     }

//     cout << "Enter " << n << " temp of corresponding city: " << endl;
//     for (i = 0; i < n; i++) {
//         cin >> city[i];
//     }

//     cout << "Temperature of the oldest city (" << cityage[oldestCityIndex] << " years old) is: " << city[oldestCityIndex] << endl;

//     return 0;
// }

#include <iostream>
using namespace std;

int main()
{
    const int size = 100;
    double temp[size];
    string cities[size];
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the name of city : ";
        cin >> cities[i];
        cout << "Enter the temperature in city : ";
        cin >> temp[i];
    }
    double coldestTemp = temp[0];
    int coldestCityIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if (temp[i] < coldestTemp)
        {
            coldestTemp = temp[i];
            coldestCityIndex = i;
        }
    }
    cout << "The coldest city is " << cities[coldestCityIndex] << " with a temperature of " << coldestTemp;
    return 0;
}
