#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv)
{
    int n;

    cin >> n;

    int num;
    vector<int> genap, ganjil;
    while (n--)
    {
        cin >> num;
        if (num % 2 == 0)
            genap.push_back(num);
        else
            ganjil.push_back(num);
    }

    sort(genap.begin(), genap.end());
    sort(ganjil.begin(), ganjil.end());

    cout << "Angka Genap:\n";
    for (int i = 0; i < genap.size(); i++)
    {
        cout << genap[i] << " ";
    }
    cout << "\n";

    cout << "Angka Ganjil:\n";
    for (int i = ganjil.size() - 1; i >= 0; i--)
    {
        cout << ganjil[i] << " ";
    }
    cout << "\n";

    return 0;
}