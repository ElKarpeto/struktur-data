#include <bits/stdc++.h>
using namespace std;

int onlyOne(vector<int> &anak, int urutan)
{
    int flag = 1;
    auto it = anak.begin();
    while (anak.size() > 1)
    {
        if (flag % urutan == 0)
        {
            anak.erase(it);
        }
        else
        {
            it++;
        }

        if (it == anak.end())
        {
            it = anak.begin();
        }

        flag++;
    }

    return anak.front();
}

int main()
{
    int n, m;

    cin >> n >> m;

    vector<int> list;

    for (int i = 1; i <= n; i++)
    {
        list.push_back(i);
    }

    cout << onlyOne(list, m) << endl;
}