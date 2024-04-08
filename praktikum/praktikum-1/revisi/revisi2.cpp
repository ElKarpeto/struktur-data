#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;

    cin >> n;

    stack<int> arr1, arr2;
    int len = n / 2;

    while (n--)
    {
        cin >> m;
        if (n >= len)
        {
            arr1.push(m);
        }
        else
        {
            arr2.push(m);
        }
    }

    while (!arr1.empty())
    {
        cout << arr1.top() << " ";
        arr1.pop();
    }

    cout << endl;

    while (!arr2.empty())
    {
        cout << arr2.top() << " ";
        arr2.pop();
    }

    cout << endl;

    return 0;
}