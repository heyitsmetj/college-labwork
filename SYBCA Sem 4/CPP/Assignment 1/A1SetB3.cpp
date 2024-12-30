#include <iostream>
#include <string>
#include<iomanip>
using namespace std;

int main() {
    int num;

    cout << "Enter Decimal number to be converted into Hexadecimal number: ";
    cin >> num;

    char hexchar[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    string result = "";

    int temp = num;

    while(temp > 0)
    {
        int rem = temp % 16;

        if(rem >= 0 && rem <= 15)
        {
            result = (hexchar[rem]) + result;
        }

        temp /= 16;
    }

    cout << "\nUsing Manual Conversion: " << endl << "Decimal: " << num << " Hexadecimal: " << result << "\n\n";
    
    cout << "Using In-Built Function: " << endl << "Decimal: " << num << " Hexadecimal: " << hex << uppercase << num;
    
    return 0;
}