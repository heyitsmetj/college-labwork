#include <iostream>
using namespace std;

int main()
{
    // Floyd's triangle
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}