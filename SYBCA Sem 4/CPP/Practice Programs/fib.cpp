#include <iostream>
using namespace std;

int main() {
    int n, a = 0, b = 1, c;
    cout << "Enter the number of terms: ";
    cin >> n;

    cout << "Fibonacci series: ";
    cout << a << " " << b;

    for (int i = 2; i < n; ++i) {
        c = a + b;
        cout << " " << c;
        a = b;
        b = c;
    }

    return 0;
}