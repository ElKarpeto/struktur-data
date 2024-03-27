#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<char> kiri;
    queue<char> kanan;

    int x, y;
    cin >> x >> y;

    while (x--)
    {
    }

    char temp = kiri.top();
    while (kiri.top() == temp || kanan.front() == temp)
    {
        if (kiri.top() == temp)
        {
            kiri.pop();
        }
        else if (kanan.front() == temp)
        {
            kanan.pop();
        }
    }
    temp = kiri.top();

    int result = kiri.size() + kanan.size();

    cout << result << endl;
}