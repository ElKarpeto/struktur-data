#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    map<string, stack<string>> result;

    string operasi, temp, perintah;
    while (n--)
    {
        cin >> operasi >> temp >> perintah;
        if (operasi == "CREATE")
        {
            result[perintah];
        }
        else if (operasi == "WRITE")
        {
            result[temp].push(perintah);
        }
        else if (operasi == "READ")
        {
            if (result[perintah].empty())
            {
                cout << "Topic is empty";
                cout << "\n";
            }
            else
            {
                cout << result[perintah].top();
                cout << "\n";
                result[perintah].pop();
            }
        }
    }
}