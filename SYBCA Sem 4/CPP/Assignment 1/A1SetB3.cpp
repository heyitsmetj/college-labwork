#include <iostream>
#include <string>
using namespace std;

int main() {
    int num;

    cout << "Enter Decimal number to be converted into Hexadecimal number: ";
    cin >> num;

    char hexchar[6] = {'A','B','C','D','E','F'};
    string result = "";

    int temp = num;

    while(temp > 0)
    {
        int rem = temp % 16;

        if(rem >= 10 && rem <= 15)
        {
            result = (hexchar[rem - 10]) + result;
        }
        else
        {
            result +=(char)rem; 
        }

        temp /= 16;
    }

    cout << "Decimal: " << num << " Hexadecimal: " << result;

    return 0;
}