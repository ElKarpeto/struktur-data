#include <bits/stdc++.h>
using namespace std;

void insert(list<int> &arr, int n, int j)
{
    if (j == 0)
    {
        arr.push_front(n);
    }
    else if (j >= arr.size())
    {
        arr.push_back(n);
    }
    else
    {
        auto it = arr.begin();

        for (int i = 0; i < arr.size(); i++)
        {
            if (i == j)
            {
                arr.insert(it, n);
            }
            it++;
        }
    }
}

int main()
{
    list<int> arr;

    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);

    int a, b;

    cin >> a >> b;

    insert(arr, a, b);

    while (!arr.empty())
    {
        cout << arr.front() << " ";

        arr.pop_front();
    }

    return 0;
}