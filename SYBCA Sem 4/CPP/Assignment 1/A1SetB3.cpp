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

/*
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
        int rem = temp % 16; // Corrected to use 16 for hexadecimal

        if(rem >= 10) // Adjusted condition to check for hex characters
        {
            result = hexchar[rem - 10] + result; // Prepend the hex character
        }
        else
        {
            result = (char)(rem + '0') + result; // Convert to character '0'-'9'
        }

        temp /= 16;
    }

    cout << "Decimal: " << num << " Hexadecimal: 0x" << result; // Added "0x" prefix

    return 0;
}

*/