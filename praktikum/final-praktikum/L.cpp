#include <bits/stdc++.h>
using namespace std;

struct setConstruct
{
    set<int> s;
    unordered_map<int, int> count;
};

vector<int> cost;
unordered_map<int, int> belong;
unordered_map<int, setConstruct> minimum;

struct Graph
{
    long vertexCount;
    vector<vector<long>> adjList;

    Graph(long v) : vertexCount(v), adjList(v) {}

    void addEdge(long vertex1, long vertex2)
    {
        adjList[vertex1].push_back(vertex2);
        adjList[vertex2].push_back(vertex1);
    }

    void dfs(vector<long> &result, long start, vector<bool> &visited)
    {
        stack<long> st;
        st.push(start);
        visited[start] = true;
        result.push_back(start);

        while (!st.empty())
        {
            long temp = st.top();
            st.pop();

            for (auto vertex : adjList[temp])
            {
                if (!visited[vertex])
                {
                    visited[vertex] = true;
                    result.push_back(vertex);
                    st.push(vertex);
                }
            }
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, s;
    cin >> n >> m >> s;
    Graph g(n);
    cost.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
        belong[i] = -1;
    }

    for (int i = 0; i < m; i++)
    {
        long a, b;
        cin >> a >> b;
        g.addEdge(a - 1, b - 1);
    }

    vector<bool> visited(n, false);
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            vector<long> component;
            g.dfs(component, i, visited);
            for (auto v : component)
            {
                belong[v] = count;
                minimum[belong[v]].s.insert(cost[v]);
                minimum[belong[v]].count[cost[v]]++;
            }
            count++;
        }
    }

    int t;
    cin >> t;
    long long ans = 0;

    while (t--)
    {
        int type, x;
        cin >> type >> x;
        x--;
        if (type == 1)
        {
            int newvalue;
            cin >> newvalue;
            if (minimum[belong[x]].count[cost[x]] == 1)
            {
                minimum[belong[x]].s.erase(cost[x]);
            }
            minimum[belong[x]].count[cost[x]]--;
            cost[x] = newvalue;
            minimum[belong[x]].count[newvalue]++;
            minimum[belong[x]].s.insert(newvalue);
        }
        else if (type == 2)
        {
            if (belong[x] != belong[s - 1])
            {
                ans += *minimum[belong[x]].s.begin() + *minimum[belong[s - 1]].s.begin();
            }
            s = x + 1;
        }
    }

    cout << ans << endl;
    return 0;
}
