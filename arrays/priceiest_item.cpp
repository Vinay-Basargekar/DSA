#include<iostream>
using namespace std;

int main(){
    const int max=100;
    int price[max],n;
    string item[max];
    cout << "Enter no. of items: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {   
        cout << "Enter item name: ";
        cin >> item[i];
        cout << "Enter the price of item: ";
        cin >> price[i];
    }

    int costliest = price[0];
    int item_index = 0;
    for (int i = 1; i <= n; i++)
    {
        if(price[i] > costliest){
            costliest = price[i];
            item_index = i;
        }
    }
    cout << "costliest item named " << item[item_index] << " having price "<< costliest;
    return 0;
}