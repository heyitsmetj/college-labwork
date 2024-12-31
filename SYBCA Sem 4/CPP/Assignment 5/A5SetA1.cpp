#include <iostream>
using namespace std;
float PI = 3.14159;

inline float areaC(float r)
{
    return PI * (r * r); 
}

inline float areaS(float side)
{
    return (side * side); 
}

inline float areaR(float l, float b)
{
    return (l * b); 
}

int main() 
{
    float r,side,l,b;
    
    cout << "Enter the radius of Circle: ";
    cin >> r;
    
    cout << "Area of Circle with radius: " << r << " is: " << areaC(r) << endl;

    cout << "Enter the side of Square: ";
    cin >> side;
    
    cout << "Area of Square with side: " << side << " is: " << areaS(side) << endl;
    
    cout << "Enter the length & breadth of Rectangle: ";
    cin >> l >> b;
    
    cout << "Area of Rectangle with length: " << l << " & breadth: " << b << " is: " << areaR(l,b) << endl;

    return 0;
}