#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &graph, int start, vector<int> &parent, vector<int> &distence)
{
    queue<int> q;

    distence[start] = 0;

    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int neighbour : graph[node])
        {
            if (distence[neighbour] == 1e9)
            {
                parent[neighbour] = node;
                distence[neighbour] = distence[node] + 1;
                q.push(neighbour);
            }
        }
    }
}

void shortessPath(vector<vector<int>> &graph, int start, int target, int V)
{
    vector<int> parent(V, -1);

    vector<int> distence(V, 1e9);

    bfs(graph, start, parent, distence);

    if (distence[target] == 1e9)
    {
        return;
    }

    vector<int> path;
    int currentNode = target;
    path.push_back(target);
    while (parent[currentNode] != -1)
    {
        path.push_back(parent[currentNode]);
        currentNode = parent[currentNode];
    }

    cout << path.size() - 1;
    cout << "\n";
}

int main()
{
    int V, E, a;
    cin >> V >> E >> a;
    vector<vector<int>> edges;
    int node1, node2;
    while (E--)
    {
        cin >> node1 >> node2;
        vector<int> temp = {node1, node2};

        edges.push_back(temp);
    }

    vector<vector<int>> graph(V);
    for (auto edge : edges)
    {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    int src, target;
    while (a--)
    {
        cin >> src >> target;
        shortessPath(graph, src, target, V);
    }

    return 0;
}