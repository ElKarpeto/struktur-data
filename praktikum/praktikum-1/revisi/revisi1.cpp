#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;

    cin >> n;

    vector<int> arr(10000, 0);

    while (n--)
    {
        cin >> m;

        arr[m]++;
    }

    int max = 0;
    for (auto it = arr.begin(); it < arr.end(); it++)
    {
        if (*it > max)
        {
            max = *it;
        }
    }

    for (int i = 10000 - 1; i >= 0; i--)
    {
        if (arr[i] == max)
        {
            cout << i << endl;
            break;
        }
    }
}