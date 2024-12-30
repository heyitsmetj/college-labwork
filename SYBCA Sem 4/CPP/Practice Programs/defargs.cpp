#include <iostream>
using namespace std;

int add(int a, int b = 5)
{
    return (a + b);
}

int main()
{
    int a = 5,
        b = 10,
        c = 15;

    int result = add(a, b);
    cout << result << endl;

    result = add(a);
    cout << result << endl; 

    return 0;
}
