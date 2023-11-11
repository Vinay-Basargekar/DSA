#include <iostream>
using namespace std;

int main()
{   
    const int max=100;
    int num[max],n;
    cout <<"Enter no. of Integer: "; cin >> n;
    cout <<"Enter "<<n<<" integer Values: "<<endl;
    for(int i=0 ; i<n ; i++){
        cin >> num[i];
    }
    int temp;
    for(int i=0 ; i<n/2 ; i++){
        temp = num[i];
        num[i]=num[n-i-1];
        num[n-i-1]=temp;
    }
    cout << "Reversed array: ";
    for (int i = 0; i < n; i++) {
        cout << num[i] << " ";
    }
    cout << endl;
    return 0;
}