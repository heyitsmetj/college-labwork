#include<iostream>
using namespace std;

int &max(int &a, int &b)
{
    if(a > b)
    return a;

    else
    return b;
}

int main()
{
    int a,b;
    cout << "Enter a & b: ";
    cin >> a >> b;

    max(a,b) = -1;

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    return 0; 
}

