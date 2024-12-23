#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int num;

    cout << "Enter a number: ";
    cin >> num;

    int temp = num;
    int digits = 0;

    while(temp > 0)
    {
        temp /= 10;
        digits++;
    }

    int sum = 0;
    temp = num;
    
    for(int i = 0; i < digits; i++)
    {
        int digit = temp % 10;
        sum += pow(digit, digits);
        temp /= 10;
    }

    if(sum == num)
    cout << num << " is an Armstrong number.";
    else
    cout << num << " is not an Armstrong number.";
    return 0;
}