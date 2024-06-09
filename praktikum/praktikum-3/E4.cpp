#include <bits/stdc++.h>

#define ll long long

using namespace std;

vector<vector<ll>> island(1000005, vector<ll>());
vector<ll> vis(1000005, 0);

struct UFDS
{
    vector<int> p, rank, setSize;
    int numSets;
    UFDS(int N)
    {
        setSize.assign(N, 1);
        numSets = N;
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++)
            p[i] = i;
    }
    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j)
    {
        if (!isSameSet(i, j))
        {
            numSets--;
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y])
            {
                p[y] = x;
                setSize[x] += setSize[y];
            }
            else
            {
                p[x] = y;
                setSize[y] += setSize[x];
                if (rank[x] == rank[y])
                    rank[y]++;
            }
        }
    }
    int numDisjointSets() { return numSets; }
    int sizeOfSet(int i)
    {
        return setSize[findSet(i)];
    }
};

ll dfs(ll temp)
{
    ll count = 0;
    for (auto i : island[temp])
    {
        if (!vis[i])
        {
            vis[i] = 1;
            count += dfs(i) + 1;
        }
    }
    return count;
}

void reset()
{
    for (ll i = 0; i < 1000005; i++)
    {
        vis[i] = 0;
    }
}

int main()
{
    ll n;
    cin >> n;
    ll v, e, w, p;

    while (n--)
    {
        // reset();
        cin >> v >> e >> w >> p;
        UFDS dsu(v);

        while (e--)
        {
            ll x, y;
            cin >> x >> y;
            x--;
            y--;
            dsu.unionSet(x, y);
        }

        ll islands = dsu.numDisjointSets();

        ll sum = islands * w;
        ll warkop = v * w;

        sum += (v - islands) * p;

        if (warkop < sum)
        {
            cout << warkop << endl;
        }
        else
        {
            cout << sum << endl;
        }
    }
    return 0;
}