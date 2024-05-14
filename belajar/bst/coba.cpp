#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long

int main()
{
    set<int> arr;

    arr.insert(1);
    arr.insert(2);
    arr.insert(3);
    arr.insert(4);
    arr.insert(5);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
}