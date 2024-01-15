#include <iostream>
using namespace std;

const int MAX_STUDENTS = 100;

void linearSearch(string names[][1], int n, string key)
{
    for (int i = 0; i < n; i++)
    {
        if (names[i][0] == key)
        {
            cout << "Name found." << endl;
            return;
        }
    }
    cout << "Name not found." << endl;
}

void insertionSort(string names[][1], int n)
{
    cout << "Sorted Names:" << endl;
    for (int i = 0; i < n; i++)
    {
        string current = names[i][0];
        int j = i - 1;
        while (j >= 0 && names[j][0] > current)
        {
            names[j + 1][0] = names[j][0];
            j--;
        }
        names[j + 1][0] = current;
        cout << names[i][0] << endl; // Display the name as it's sorted
    }
    cout << "Names sorted in alphabetical order using Insertion Sort." << endl;
}

int binarySearch(string names[][1], int n, string key)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (names[mid][0] == key)
        {
            cout << "Name found." << endl;
            return mid;
        }
        else if (names[mid][0] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << "Name not found." << endl;
    return -1;
}

int main()
{
    int n;
    cout << "Enter the number of students: ";
    cin >> n;
    string names[MAX_STUDENTS][1];

    // Input student names
    cout << "Enter the names of students:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Student " << i + 1 << ": ";
        cin >> names[i][0]; // Assuming only one name per student for simplicity
    }

    int choice;
    string key;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Perform Linear Search\n";
        cout << "2. Perform Insertion Sort (Alphabetical Order)\n";
        cout << "3. Perform Binary Search\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the name to search: ";
            cin >> key;
            linearSearch(names, n, key);
            break;
        case 2:
            insertionSort(names, n);
            break;
        case 3:
            cout << "Enter the name to search: ";
            cin >> key;
            insertionSort(names, n); // Sort the names before binary search
            binarySearch(names, n, key);
            break;
        case 4:
            cout << "Exiting...";
            return 0;
        default:
            cout << "Invalid choice! Please enter a valid choice.\n";
            break;
        }
    } while (choice != 4);

    return 0;
}
