#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        ll n;
        cin >> n;
        map<ll, priority_queue<ll>> m;
        map<ll, ll> dec;
        map<ll, bool> exists;

        for (ll i = 0; i < n; i++)
        {
            ll a, b;
            cin >> a >> b;
            m[a].push(b);
            exists[a] = true;
        }

        ll sum = 0, counter = 0;
        for (auto &entity : m)
        {
            ll key = entity.first;
            priority_queue<ll> &pq = entity.second;

            while (!pq.empty())
            {

                ll temp = pq.top();
                sum += temp;
                pq.pop();
                dec[key]++;
                counter++;

                if (exists[counter])
                {
                    ll curr = counter;
                    // cout << "curr key: " << key << endl;
                    // cout << "counter: " << counter << endl;
                    counter -= dec[curr];
                    dec[curr] = 0;
                    // cout << "counter: " << counter << endl << endl;
                    if (curr == key)
                        break;
                }
            }
        }
        cout << "Duarr skor maksimumnya " << sum << endl;
    }
    return 0;
}