#include <iostream>
using namespace std;

int main()
{
    int a, b;

    cout << "Enter a & b: ";
    cin >> a >> b;

    char op;

    cout << "Give the operator symbol (+,-,*,/): ";
    cin >> op;

    switch (op)
    {
    case '+':
        cout << "Addition of a: " << a << " & " << "b: " << b << " = " << (a + b) << endl;
        break;

    case '-':
        cout << "Subtraction of a: " << a << " by " << "b: " << b << " = " << (a - b) << endl;
        break;
    
    case '*':
        cout << "Multiplication of a: " << a << " by " << "b: " << b << " = " << (a * b) << endl;
        break;

    case '/':
        cout << "Divison of a: " << a << " & " << "b: " << b << " = " << (a / b) << endl;
        break;
    
    default:
        break;
    }                
    return 0;
}