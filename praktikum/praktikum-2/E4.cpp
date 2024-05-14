#include <bits/stdc++.h>
using namespace std;

long long maxRotation(long long num)
{
    return num - 1 - (floor(log2(num)));
}

int main()
{
    long long n;

    while (n != -1144)
    {
        cin >> n;
        if (n == -1144)
            break;

        long long rotasi = n > 2 ? maxRotation(n) : 0;
        cout << rotasi * 2 << endl;
    }
}