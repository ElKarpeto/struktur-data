#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv)
{
    int n;

    cin >> n;

    int level = log2(n);
    vector<int> arr1, arr2;

    int node;
    while (n--)
    {
        cin >> node;
        arr1.push_back(node);
    }

    int flagArr = 1;
    if (level % 2 != 0)
    {
        while (level > 0)
        {
            if (flagArr % 2 != 0)
            {
                for (int i = 1; i < arr1.size(); i += 2)
                {
                    arr2.push_back(max(arr1[i], arr1[i - 1]));
                }

                arr1.clear();
            }
            else
            {
                for (int i = 1; i < arr2.size(); i += 2)
                {
                    arr1.push_back(min(arr2[i], arr2[i - 1]));
                }

                arr2.clear();
            }
            level--;
            flagArr++;
        }
    }
    else
    {
        while (level > 0)
        {
            if (flagArr % 2 != 0)
            {
                for (int i = 1; i < arr1.size(); i += 2)
                {
                    arr2.push_back(min(arr1[i], arr1[i - 1]));
                }

                arr1.clear();
            }
            else
            {
                for (int i = 1; i < arr2.size(); i += 2)
                {
                    arr1.push_back(max(arr2[i], arr2[i - 1]));
                }

                arr2.clear();
            }
            level--;
            flagArr++;
        }
    }

    if (!arr1.empty())
    {
        cout << arr1[0];
        cout << "\n";
    }

    if (!arr2.empty())
    {
        cout << arr2[0];
        cout << "\n";
    }

    return 0;
}