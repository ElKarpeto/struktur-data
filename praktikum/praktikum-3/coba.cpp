#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define ll long long

void dfs(ll node, unordered_map<ll, vector<ll>> &graph, unordered_set<ll> &visited)
{
    visited.insert(node);
    for (ll neighbor : graph[node])
    {
        if (visited.find(neighbor) == visited.end())
        {
            dfs(neighbor, graph, visited);
        }
    }
}

ll count_graphs(ll n, vector<pair<ll, ll>> &edges)
{
    unordered_map<ll, vector<ll>> graph;

    for (const auto &edge : edges)
    {
        ll a = edge.first;
        ll b = edge.second;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    unordered_set<ll> visited;
    ll graph_amt = 0;

    for (const auto &node : graph)
    {
        if (visited.find(node.first) == visited.end())
        {
            dfs(node.first, graph, visited);
            graph_amt++;
        }
    }

    for (const auto &edge : edges)
    {
        if (visited.find(edge.first) == visited.end())
        {
            graph_amt++;
            visited.insert(edge.first);
        }
        if (visited.find(edge.second) == visited.end())
        {
            graph_amt++;
            visited.insert(edge.second);
        }
    }

    return graph_amt;
}

int main()
{
    ll x;
    cin >> x;
    while (x--)
    {
        ll v, e, w, p;
        cin >> v >> e >> w >> p;
        vector<pair<ll, ll>> edges(e);

        for (ll i = 0; i < e; ++i)
        {
            ll a, b;
            cin >> a >> b;
            edges[i] = make_pair(a, b);
        }

        ll graph_amt = count_graphs(e, edges);
        ll printme = graph_amt * w + p * (v - graph_amt) < v * w ? graph_amt * w + p * (v - graph_amt) : v * w;
        cout << printme << endl;
    }
    return 0;
}