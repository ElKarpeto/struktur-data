#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int modulo = 1e9 + 7;

int main()
{
    int n;
    cin >> n;

    ll faktorial = 1;
    for (int i = 1; i <= n; ++i)
    {
        faktorial = (faktorial * i) % modulo;
    }

    cout << faktorial;
    return 0;
}