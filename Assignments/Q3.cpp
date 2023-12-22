#include <iostream>
using namespace std;

const int MAX_STUDENT = 100;
const int MAX_NAME_LENGTH = 50;

void linearSearch(string names[][MAX_NAME_LENGTH], int n,string key)
{
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (names[i][n] == key)
        {
            cout << "Name found.";
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Name not found.";
    }
}

int binarySearch(string names[][MAX_NAME_LENGTH], int n,string key)
{
    // int left = 0, right = n - 1;
    // while (left <= right)
    // {
    //     int mid = left + (right - left) / 2;

    //     if (names[mid][n] == key)
    //     {
    //         cout << "Name found";
    //         return;
    //     }

    //     if (names[mid][n] < key)
    //     {
    //         left = mid + 1;
    //     }
    //     else
    //     {
    //         right = mid - 1;
    //     }
    // }
    // cout << "Name not found";
    int row = n;
    int col = MAX_NAME_LENGTH;
    int l = 0, h = row * col - 1;

    while (l <= h)
    {
        int mid = l + (h - l) / 2;

        int tC = mid % col;
        int tR = mid / col;

        int val = names[tR][0].compare(key);

        if (val == 0)
        {
            cout << "Name found at index (" << tR << ", " << tC << ")." << endl;
            return(tR, tC);
        }

        if (val < 0)
            l = mid + 1;
        else
            h = mid - 1;
    }

    cout << "Name not found.\n";
    return (-1, -1);
}

int main()
{
    int n;
    cout << "Enter the number of students: ";
    cin >> n;
    string names[MAX_STUDENT][MAX_NAME_LENGTH];

    // Input student names
    cout<< "Enter the names of students:\n";
    for(int i=0 ; i<n ; i++){
        cout << "Student " << i + 1 << ": ";
        cin >> names[i][n];
    }
    int choice;
    string key;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Perform Linear Search\n";
        cout << "2. Perform Binary Search\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            // Input the element to be searched
            cout << "Enter the name to search: ";
            cin >> key;

            linearSearch(names, n, key);
            break;
        case 2:
            // Input the element to be searched
            cout << "Enter the name to search: ";
            cin >> key;

            // Perform binary search
            sort(&names[0][0], &names[0][0] + n * MAX_NAME_LENGTH); // Sorting the 2D array
            binarySearch(names, n, key);
            break;
        case 3:
            cout << "Exiting...";
            return 0;
        default:
            cout << "Invalid choice! Please enter a valid choice.\n";
            break;
        }
    } while (choice != 3);
    return 0;
}
