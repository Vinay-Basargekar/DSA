#include<iostream>
using namespace std;

class employee{
    int sal;

    public:
    employee(){ sal = 1000;} //Default constructor
    employee(int x){ sal = x;} //paramaterized constructor

    int avgsal(employee s1,employee s2){
        return (sal + s1.sal + s2.sal)/3;
    }
};

int main(){
    int c1,c2,c3;
    cout << "Enter sal of three employee: ";
    cin >> c1 >> c2 >>c3;
    employee vinay(c1),sid(c2),yash(c3);
    int avg = vinay.avgsal(sid,yash);
    cout <<"The avg sal of three is : " <<avg << endl;
}