#include <iostream>
#include <cmath>
using namespace std;
float PI = 3.14159;

inline float volume(float side)
{
    return pow(side,3); 
}

inline float volume(float r, float h)
{
    return PI * pow(r, 2) * h; 
}

inline float volume(float r,bool isSphere)
{
    return (4.0 / 3.0) * PI * pow(r, 3); 
}

int main() 
{
    float r,side,h;
    
    cout << "Enter the side of Cube: ";
    cin >> side;
    
    cout << "Volume of Cube with side: " << side << " is: " << volume(side) << endl;

    cout << "Enter the radius of the Cylinder: ";
    cin >> r;
    cout << "Enter the height of the Cylinder: ";
    cin >> h;
    
    cout << "Volume of Cylinder with radius: " << r << " & height: " << h << " is: " << volume(r, h) << endl;
    
    cout << "Enter the Radius of Sphere: ";
    cin >> r;
    
    cout << "Volume of Sphere with radius: " << r << " is: " << volume(r, true) << endl;

    return 0;
}