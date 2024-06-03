#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long

ull maxRotation(ull num)
{
    int temp = pow(2, floor(log(num) / log(2.0)));

    return temp;
}

int main()
{
    ull num;

    cin >> num;

    if (num % 2 == 0)
    {
        cout << maxRotation(num);
    }
    else
    {
        cout << maxRotation(num);
    }
}