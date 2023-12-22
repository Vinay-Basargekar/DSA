// Create an array to store N integers and find min and max using function
#include<iostream>
using namespace std;

int findMin(int a[],int size){
    int min = a[0];
    for(int i=1 ; i<size ;i++){
        if(min > a[i]){
            min = a[i];
        }
    }
    return min;
}

int findMax(int a[], int size)
{
    int max = a[0];
    for (int i = 1; i < size; i++)
    {
        if (max < a[i])
        {
            max = a[i];
        }
    }
    return max;
}

const int MAX=100;

int main(){
    int a[MAX];
    int n;
    cout << "Enter the number of elements of the array (up to " << MAX << "): ";
    cin >> n;
    cout << "Enter the elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int minValue = findMin(a, n);
    int maxValue = findMax(a, n);

    cout << "Minimum value in array is: " << minValue << endl;
    cout << "Maximum value in array is: " << maxValue << endl;

    return 0;
}