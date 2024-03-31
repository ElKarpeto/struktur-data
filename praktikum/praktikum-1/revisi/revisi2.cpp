#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int len = n / 2;

    stack<int> arr1, arr2;

    for (int i = 0; i < len; i++)
    {
        arr1.push(arr[i]);
    }

    for (int i = len; i < n; i++)
    {
        arr2.push(arr[i]);
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