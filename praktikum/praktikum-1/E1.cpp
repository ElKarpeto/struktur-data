#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    cin >> n;

    vector<string> arr;

    while (n--)
    {
        string operasi, buku;
        cin >> operasi;

        if (operasi == "BELI")
        {
            cin >> buku;

            arr.push_back(buku);
        }
        else if (operasi == "JUAL")
        {
            cin >> buku;

            auto it = arr.begin();

            while (1)
            {
                if (*it == buku)
                {
                    arr.erase(it);
                    break;
                }

                else
                {
                    it++;
                }
            }
        }
        else if (operasi == "PRINT")
        {
            auto it = arr.begin();

            for (it; it != arr.end(); it++)
            {
                cout << *it << endl;
            }
            cout << "---" << endl;
        }
    }
}