#include <iostream>
using namespace std;

void printDigit(int x)
{

    if (x < 10)
    {
        cout << x << " ";
    }
    else
    {
        printDigit(x / 10);
        cout << x % 10 << " ";
    }
}

int main()
{
    int num;

    cin >> num;

    printDigit(num);
    cout << endl;

    return 0;
}