#include <iostream>
#include <cmath>
using namespace std;

class Point{
    float x, y;

public:
    // Default constructor 
    Point(){ x = 0; y = 0;}
    // Parameterized constructor 
    Point(float s, float p){
        x = s;
        y = p;
    }
    // Function to compute the distance between two points
    float compute(Point px){
        // Using Distance formula!
        return sqrt((x - px.x) * (x - px.x) + (y - px.y) * (y - px.y));
    }
};

int main(){
    float x1, y1, x2, y2;
    // Input for first point
    cout << "Enter x and y coordinates for point 1: ";
    cin >> x1 >> y1;

    // Input for second point
    cout << "Enter x and y coordinates for point 2: ";
    cin >> x2 >> y2;

    // Creating point objects using user-input coordinates
    Point p1(x1, y1), p2(x2, y2);
    float diff = p1.compute(p2);
    cout << "Distance between the two points: " << diff << endl;
    return 0;
}
