#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<pair<int, string>> arr;

    int n;

    cin >> n;

    int prioritas;
    string tugas;

    while (n--)
    {
        cin >> prioritas;
        getline(cin, tugas);
        arr.push(make_pair(prioritas, tugas));
    }

    while (!arr.empty())
    {
        if (arr.top().second.find("seru-seruan") == string::npos)
        {
            cout << arr.top().second << endl;
        }
        arr.pop();
    }
}