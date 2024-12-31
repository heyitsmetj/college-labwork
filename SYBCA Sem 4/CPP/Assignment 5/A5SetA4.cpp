#include <iostream>
using namespace std;

float calculate(int p, float r = 7, float t = 10)
{
    return (p * r * t) / 100;
}

int main()
{
    int principal, r, years;

    char ch;

    cout << "Enter the principal amount: ";
    cin >> principal;

    cout << "Do you want to provide ROI & Time period?(Y/N): ";
    cin >> ch;

    if (ch == 'Y' || ch == 'y')
        cout << "Simple Interest with given ROI & Time period: " << calculate(principal, r, years) << endl;
    else
        cout << "Simple Interest with default ROI & Time period: " << calculate(principal) << endl;

    return 0;
}