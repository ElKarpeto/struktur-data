#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(int argc, char **argv)
{
    vector<ll> arr(100000, 0);
    ll a = 1200, b = 2556, c = 3036, d = 1952;

    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 232;

    for (ll i = 3; i < 100000; i++)
    {
        arr[i] = (arr[i - 1] + a) % 7340033;
        a = (a + b) % 7340033;
        b = (b + c) % 7340033;
        c = (c + d) % 7340033;
        d = (d + 480) % 7340033;
    }

    int n;

    cin >> n;

    int num;
    while (n--)
    {
        cin >> num;

        cout << arr[num - 1];
        cout << "\n";
    }
}