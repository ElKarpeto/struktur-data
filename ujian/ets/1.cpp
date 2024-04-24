#include <bits/stdc++.h>
using namespace std;

int monotonic(list<int> &arr)
{
    int temp = arr.front();
    while (!arr.empty())
    {
        arr.pop_front();
        if (temp > arr.front())
        {
            break;
        }
    }

    if (arr.empty())
        return 1;
    else
        return 0;
}

bool monotonicFunc(list<int> &arr)
{
    if (arr.empty())
    {
        return false;
    }

    arr.pop_front();
    return (arr.front() < monotonicFunc(arr));
}

int main()
{
    list<int> arr;
    arr.push_back(5);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);

    cout << monotonic(arr);

    return 0;
}