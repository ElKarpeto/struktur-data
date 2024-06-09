#include <bits/stdc++.h>
using namespace std;

struct graph
{
    long vertexCount, edgeCount;
    vector<vector<long>> adjList;

    void init(long v)
    {
        vertexCount = v;
        edgeCount = 0;

        for (int i = 0; i < vertexCount; i++)
        {
            adjList.push_back({}); // inserts V ammount of empty vector
        }
    }

    void add_edge(long vertex1, long vertex2)
    {
        adjList[vertex1].push_back(vertex2);
        edgeCount++;
    }

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
                if (!visited[vertex])
                    st.push(vertex);
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
                if (!visited[vertex])
                {
                    q.push(vertex);
                    visited[vertex] = true;
                    result.push_back(vertex);
                }
                else
                {
                    cout << "Semak-semak\n";
                    return;
                }
            }
        }
        cout << "Pohon\n";
    }
};

int main()
{
    int n;
    cin >> n;

    graph G;
    G.init(51);

    int a, b;
    while (n--)
    {
        cin >> a >> b;
        G.add_edge(a, b);
    }

    vector<long> result;
    G.bfs(result, 1);
}