#include <bits/stdc++.h>
using namespace std;

struct graph
{
    long vertexCount, edgeCount;
    vector<vector<pair<long, long>>> adjList;

    void init(long v)
    {
        vertexCount = v;
        edgeCount = 0;

        for (int i = 0; i < vertexCount; i++)
        {
            adjList.push_back({}); // inserts V ammount of empty vector
        }
    }

    void add_edge(long vertex1, long vertex2, long weight)
    {
        adjList[vertex1].push_back(make_pair(vertex2, weight));
        edgeCount++;
    }

    vector<int> harga;
    void dfs(vector<long> &result, long start)
    {
        vector<bool> visited(vertexCount, false);
        stack<long> st;

        st.push(start);
        visited[start] = true;
        result.push_back(start);

        while (!st.empty())
        {
            long temp = st.top();
            st.pop();

            if (!visited[temp])
            {
                result.push_back(temp);
                visited[temp] = true;
            }

            for (auto vertex : adjList[temp])
            {
                if (!visited[vertex.first])
                    st.push(vertex.first);

                if (temp == vertexCount - 1)
                {
                    break;
                }
                else
                {
                    harga.push_back(vertex.second);
                }
            }
        }
    }

    void bfs(vector<long> &result, long start)
    {
        vector<bool> visited(vertexCount, false);
        queue<long> q;

        q.push(start);
        visited[start] = true;
        result.push_back(start);

        while (!q.empty())
        {
            long temp = q.front();
            q.pop();

            for (auto vertex : adjList[temp])
            {
                if (!visited[vertex.first])
                {
                    q.push(vertex.first);
                    visited[vertex.first] = true;
                    result.push_back(vertex.first);
                }
            }
        }
    }
};

int main()
{
    int a, b;

    cin >> a >> b;

    graph G;

    G.init(a);

    int node1, node2, weight;
    while (b--)
    {
        cin >> node1 >> node2 >> weight;
        G.add_edge(node1, node2, weight);
    }

    vector<long> hasil;

    G.dfs(hasil, 0);

    // for (int i = 0; i < hasil.size(); i++)
    // {
    //     // cout << hasil[i] << endl;
    // }

    for (int i = 0; i < G.harga.size(); i++)
    {
        cout << G.harga[i] << endl;
    }
}
