
#include <iostream>
using namespace std;

int arithmatic()
{
    int a, b;
    float result;

    cout << "Enter a: ";
    cin >> a;

    cout << "Enter b: ";
    cin >> b;

    result = (float)a + b;
    cout << "\nAdd: " << result << endl;

    result = (float)a - b;
    cout << "Subtract: " << result << endl;

    result = (float)a * b;
    cout << "Multiply: " << result << endl;

    result = (float)a / b;
    cout << "Divide: " << result << endl;

    result = a % b;
    cout << "Mod: " << result << endl;

    return 0;
}

int factorial()
{
    int n, i, fact = 1;
    cout << "Enter a number: ";
    cin >> n;

    for (i = 1; i <= n; i++)
    {
        fact *= i;
    }
    cout << "Factorial of " << n << " = " << fact << endl;
    return 0;
}

void name()
{
    string name = "Tejas";
    cout << "Hello, " << name << "!" << endl;
}

void max(){
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "Maximum: " << (a > b? a : b) << endl;
}
int main()
{
    arithmatic();
    factorial();
    name();
}