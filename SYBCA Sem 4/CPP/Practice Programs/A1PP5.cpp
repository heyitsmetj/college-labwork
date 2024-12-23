#include <iostream>
using namespace std;

int main()
{
    int num,rev=0,rem=0;

    cout << "Enter the number to be reversed: ";
    cin >> num;

        cout << "Your number: " << num << endl;

    while(num!=0)
    {
        rem = num%10;
        rev = (rev*10) + rem;
        num = num/10;
    }

    cout << "Reversed number: " << rev << endl;

    return 0;
}