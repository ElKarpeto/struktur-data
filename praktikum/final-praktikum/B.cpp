#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv)
{
    int num;

    vector<int> arr;
    while (true)
    {
        cin >> num;
        if (num == -1)
            break;

        arr.push_back(num);
    }

    int index;
    cin >> index;
    int kiri = index - 1, kanan = arr.size() - index;

    swap(arr[kiri], arr[kanan]);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\n";

    return 0;
}