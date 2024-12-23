#include <iostream>
using namespace std;

int main()
{
    int n, i, fact = 1;
    cout << "Enter a number: ";
    cin >> n;

    for (i = 1; i <= n; i++)
    {
        fact *= i;
    }
    cout << "Factorial of " << n << " = " << fact << endl;
    return 0;
}