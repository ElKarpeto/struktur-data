#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    int arr[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    deque<int> chat;
    map<int, int> cek;

    for (int i = 0; i < N; i++)
    {
        if (cek[arr[i]] == 1)
        {
            continue;
        }
        else
        {
            if (chat.size() >= K)
            {
                cek[chat.front()] = 0;
                chat.pop_front();
            }
            chat.push_back(arr[i]);
            cek[arr[i]] = 1;
        }
    }

    cout << chat.size() << endl;
    while (!chat.empty())
    {
        cout << chat.back() << " ";
        chat.pop_back();
    }
    cout << endl;

    return 0;
}
