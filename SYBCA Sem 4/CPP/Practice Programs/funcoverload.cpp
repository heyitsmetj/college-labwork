#include<iostream>
using namespace std;

int add(int a, int b,int c)
{
    return (a+b+c);
}

int add(int a, int b)
{
    return (a+b);
}

int main()
{
    int a = 5,
        b = 10,
        c = 15;

    int result = add(a,b);
    cout << result << endl;

    result = add(a,b,c);
    cout << result << endl;

    return 0;
}

