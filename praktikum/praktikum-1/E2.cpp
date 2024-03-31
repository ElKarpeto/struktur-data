#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, y;

    cin >> x >> y;

    string element1, element2;

    cin >> element1 >> element2;

    list<char> arr1, arr2;

    for (int i = x - 1; i >= 0; i--)
    {
        arr2.push_back(element1[i]);
    }

    for (int i = 0; i < y; i++)
    {
        arr1.push_back(element2[i]);
    }

    while (!(arr1.empty() || arr2.empty()))
    {
        if (arr1.front() == arr2.front())
        {
            char temp = arr1.front();

            while (arr1.front() == temp)
            {
                arr1.pop_front();
            }

            while (arr2.front() == temp)
            {
                arr2.pop_front();
            }
        }
        else
        {
            break;
        }
    }

    int result = arr1.size() + arr2.size();

    cout << result << endl;
}