#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> arr;
int banyakSatu(int x, int y)
{
    if (x < 0 || y >= 10 || x >= 10 || y < 0 || arr[x][y] != 1)
    {
        return 0;
    }

    arr[x][y] = -1;
    int total = 1;

    total += banyakSatu(x - 1, y);
    total += banyakSatu(x + 1, y);
    total += banyakSatu(x, y + 1);
    total += banyakSatu(x, y - 1);

    return total;
}

int main()
{

    int node;

    for (int i = 0; i < 10; i++)
    {
        arr.push_back({});
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> node;
            arr[i].push_back(node);
        }
    }

    vector<int> hasil;
    int temp;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (arr[i][j] == -1)
                continue;
            temp = banyakSatu(i, j);
            hasil.push_back(temp);
        }
    }

    int count = 0;

    for (int i = 0; i < hasil.size(); i++)
    {
        if (hasil[i] != 0)
        {
            count++;
        }
    }

    cout << count << endl;
}