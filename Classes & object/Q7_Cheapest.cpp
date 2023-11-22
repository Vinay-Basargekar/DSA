#include <iostream>
using namespace std;

class item
{
    float price;

public:
    item(){ price = 0;}         //Default constructor
    item(float x) { price = x; } // Parameterized constructor

    float find_cheapest(item ix, item iy){
        if (price < ix.price && price < iy.price)
            return price;
        else if (ix.price < price && ix.price < iy.price)
            return ix.price;
        else
            return iy.price;
    }

    void show(){
        cout << "Cheapest price: " << price;
    }
};

int main()
{
    item i1(20), i2(50), i3(70);
    item cheapest;
    cheapest = cheapest.find_cheapest(i2, i3);
    cheapest.show();

    return 0;
}
