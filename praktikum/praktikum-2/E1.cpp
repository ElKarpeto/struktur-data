#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long

int main()
{
    set<ull> arr;

    int n;
    ull num;

    cin >> n;

    while (n--)
    {
        cin >> num;

        arr.insert(num);
    }

    cout << arr.size() << endl;
}