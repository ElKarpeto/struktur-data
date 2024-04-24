#include <bits/stdc++.h>
using namespace std;

int searchElement(vector<int> arr, int target)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }

    return -1;
}

int searchTarget(vector<int> arr, int len, int target)
{
    if (len == 0)
    {
        return -1;
    }
    else if (arr[len - 1] == target)
    {
        return len - 1;
    }

    return searchTarget(arr, len - 1, target);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};

    int target;

    cin >> target;

    cout << searchTarget(arr, arr.size(), target) << endl;

    return 0;
}