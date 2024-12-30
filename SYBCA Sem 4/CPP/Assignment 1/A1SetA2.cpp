#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number for multiplication table: ";
    cin >> n;

    for (int i = 1; i <= 10; i++)
    {
        cout << n << " * " << i << " = " << n * i << endl;
    }

    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            cout << " " << i * j << " ";
        }

        cout << endl;
    }

    return 0;
}