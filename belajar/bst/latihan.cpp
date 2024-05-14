#include <iostream>
#include <set>
using namespace std;

#define ull unsigned long long

int main()
{
    set<ull, greater<ull>> arr;

    int n, operation;
    ull data;

    cin >> n;

    while (n--)
    {
        cin >> operation;
        if (operation == 1)
        {
            cin >> data;
            arr.insert(data);
        }
        else if (operation == 2)
        {
            cin >> data;

            auto it = arr.find(data);

            if (it == arr.end())
            {
                cout << "Data tidak ada" << endl;
                continue;
            }

            int index = distance(arr.begin(), it);

            cout << index + 1 << endl;
        }
    }
}