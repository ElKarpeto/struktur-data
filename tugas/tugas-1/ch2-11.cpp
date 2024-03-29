#include <bits/stdc++.h>
using namespace std;

#define DATABASE_FILE "data.txt"

struct Toko
{
    string nama;
    float pemasukan, pengeluaran;
};

void result()
{
    ifstream file(DATABASE_FILE);

    if (!file.is_open())
    {
        cout << "ERROR DALAM MEMBUKA FILE" << endl;
        return;
    }

    Toko temp;
    vector<pair<float, string>> arr;
    float total_netIncome = 0;

    while (file >> temp.nama >> temp.pemasukan >> temp.pengeluaran)
    {
        float netIncome = temp.pemasukan - temp.pengeluaran;
        total_netIncome += netIncome;
        arr.push_back(make_pair(netIncome, temp.nama));
    }
    file.close();

    sort(arr.begin(), arr.end());

    int len = arr.size();
    printf("======== Urutan Toko ========\n");
    for (int i = len - 1; i >= 0; i--)
    {
        cout << "- " << arr[i].second << " " << arr[i].first << endl;
    }
    printf("=============================\n");

    cout << "Jumlah Toko pada Bazar : " << len << endl;

    cout << "Total Keuntungan Semua Toko pada Bazar : " << total_netIncome << endl;
    cout << "Toko dengan Keuntungan Terbesar adalah " << arr[len - 1].second << " dengan Keuntungan Sebesar " << arr[len - 1].first << endl;
}

int main()
{
    result();

    return 0;
}