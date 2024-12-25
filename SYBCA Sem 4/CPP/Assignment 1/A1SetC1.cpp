#include <iostream>
using namespace std;

int main()
{
    int n, count = 1;
    cout << "Enter the number of rows: ";
    cin >> n;

    int space = n;

    for (int i = 0; i <= n; i++)
    {
        for (int k = 0; k < space; k++)
        {
            cout << "\t";
        }

        --space;
        
        for (int j = 0; j < i; j++)
        {
            cout << count++ << "\t";
        }
        cout << endl;
    }

    return 0;
}