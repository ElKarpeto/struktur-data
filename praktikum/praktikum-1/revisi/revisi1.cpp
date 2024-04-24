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
    int max_index = 0;
    for (int i = 0; i < 10000; i++)
    {
        if (arr[i] > max && i > max_index)
        {
            max = arr[i];
            max_index = i;
        }
    }

    cout << max_index << endl;
}