#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num;

    cin >> num;

    priority_queue<int> arr;

    while (num--)
    {
        string operasi;
        int nilai;

        cin >> operasi;

        if (operasi == "TAMBAH")
        {
            cin >> nilai;

            arr.push(nilai);
        }
        else if (operasi == "LIHAT")
        {
            int len = arr.size();
            if (len < 3)
            {
                cout << "Belum ada ulasan" << endl;
            }
            else
            {
                auto temp = arr;
                int ambil = len / 3;

                for (int i = 0; i < ambil; i++)
                {
                    cout << temp.top() << " ";
                    temp.pop();
                }

                cout << endl;
            }
        }
    }

    return 0;
}