#include<iostream>
using namespace std;

int main(){
    const int max=100;
    int temp[max],n;
    cin>>n;
    string cities[max];
    for (int i = 0; i < n; i++)
    {   
        cout <<"enter city name: ";
        cin>>cities[i];
        cout <<"Enter temp of city: ";
        cin>>temp[i];
    }
    double coldest = temp[0];
    int index_coldest = 0;
    for (int i = 0; i < n; i++)
    {
        if(temp[i] < coldest){
            coldest = temp[i];
            index_coldest = i;
        }
    }
    cout <<"Coldest temp is: " << coldest<< "is" << cities[index_coldest];
    
    
}