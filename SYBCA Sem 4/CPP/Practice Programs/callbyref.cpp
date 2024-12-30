#include<iostream>
using namespace std;

void order(int &n1,int &n2)
{
    int temp = n1;
        n1 = n2;
        n2 = temp;

}

int main()
{
    int n1 = 99,
        n2 = 11,
        n3 = 88,
        n4 = 22;

    order(n1,n2);
    order(n3,n4);

    cout << "n1 = " << n1 << endl;
    cout << "n2 = " << n2 << endl;
    cout << "n3 = " << n3 << endl;
    cout << "n4 = " << n4 << endl;

    return 0;
}
