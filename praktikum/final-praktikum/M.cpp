#include <bits/stdc++.h>
using namespace std;

struct graph
{
    long vertexCount, edgeCount;
    map<string, vector<string>> adjList;

    void init(long v)
    {
        vertexCount = v;
        edgeCount = 0;
    }

    void add_edge(string vertex1, string vertex2)
    {
        adjList[vertex1].push_back(vertex2);
        adjList[vertex2].push_back(vertex1);
        edgeCount++;
    }

    void dfs(vector<string> &result, string start)
    {
        map<string, bool> visited;
        stack<string> st;

        st.push(start);
        visited[start] = true;
        result.push_back(start);

        while (!st.empty())
        {
            string temp = st.top();
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
};

int main(int argc, char **argv)
{
    int n;

    cin >> n;

    while (n--)
    {
        int a, b;

        cin >> a >> b;

        int awal = b;
        graph G;
        G.init(a);

        string mulai;
        string node1, node2;

        if (b > 0)
        {
            cin >> node1 >> node2;
            mulai = node1;
            G.add_edge(node1, node2);
            b--;
        }

        while (b--)
        {
            cin >> node1 >> node2;

            G.add_edge(node1, node2);
        }

        vector<string> result;

        G.dfs(result, mulai);

        if (result.size() < a)
        {
            cout << "Menyirkel";
            cout << "\n";
        }
        else
        {
            cout << "Tidak Menyirkel";
            cout << "\n";
        }
    }
}