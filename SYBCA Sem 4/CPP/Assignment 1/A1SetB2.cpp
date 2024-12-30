#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter a number of the series: ";
    cin >> num;

    int result = 0; 

    for(int i = 1;i <= num;i++)
    {
        int sum = 0;

        for(int j = 1; j <= i; j++)
        {
            sum += j;
        }

        result += sum;
    }

    cout << "Result = " << result << endl;

    return 0;
}