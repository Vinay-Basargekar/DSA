#include<iostream>
using namespace std;

class circle{
    int radius;
    public:
    circle(){ radius = 0;}
    circle(int x){ radius = x;}


    int Sum(circle cx,circle cy){
        int sum = cx.radius + cy.radius;
        radius = sum;
        return radius;
    }

};

int main(){
    int radius1, radius2;

    cout << "Enter radius of the first circle: ";
    cin >> radius1;
    cout << "Enter radius of the second circle: ";
    cin >> radius2;

    circle c1(radius1), c2(radius2), c3;
    cout << "Radius of another circle is: "<< c3.Sum(c1,c2);
}