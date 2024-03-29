#include <iostream>
#include <deque>
#include <set>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    deque<int> messages;
    set<int> friends;

    for (int i = 0; i < N; ++i)
    {
        int Pi;
        cin >> Pi;

        // Jika teman sudah ada dalam set, abaikan pesan tersebut
        if (friends.find(Pi) != friends.end())
            continue;

        // Jika jumlah obrolan sudah mencapai K, hapus obrolan terakhir
        if (messages.size() == K)
        {
            int lastFriend = messages.back();
            messages.pop_back();
            friends.erase(lastFriend);
        }

        // Tambahkan ID teman ke set dan sisipkan ke depan deque
        friends.insert(Pi);
        messages.push_front(Pi);
    }

    // Tampilkan hasil akhir
    cout << messages.size() << endl;
    for (int friendID : messages)
    {
        cout << friendID << " ";
    }
    cout << endl;

    return 0;
}
