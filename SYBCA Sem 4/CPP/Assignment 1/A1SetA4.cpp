#include <iostream>
using namespace std;

int main()
{
    int num;

    cout << "Enter number to be checked for palindrome: ";
    cin >> num;

    int og_num = num;

    int temp = num,rev = 0,rem;

    while(temp > 0)
    {
        rem = temp % 10;
        rev = (rev * 10) + rem;
        temp = temp / 10;
    }

    if(rev == og_num)
        cout << og_num << " is a Palindrome." << endl;

    else
        cout << og_num << " is NOT a Palindrome." << endl; 
    return 0;
}