#include <bits/stdc++.h>
using namespace std;

#define DATABASE_FILE "data.txt"

void addJob(string job, int priority)
{
    ofstream dokumen;

    dokumen.open(DATABASE_FILE, ios_base::app);

    if (!dokumen.is_open())
    {
        cout << "FILE DATA BASE PEKERJAAN TIDAK DAPAT DIBUKA" << endl;
        return;
    }

    dokumen << job << " " << priority << endl;

    dokumen.close();

    cout << "PEKERJAAN " << job << " DENGAN PRIORITAS " << priority << " TELAH BERHASIL DITAMBAHKAN" << endl;
}

void displayJob()
{
    ifstream dokumen;

    dokumen.open(DATABASE_FILE);

    if (!dokumen.is_open())
    {
        cout << "FILE DATA BASE PEKERJAAN TIDAK DAPAT DIBUKA" << endl;
        return;
    }

    priority_queue<pair<int, string>> job;
    pair<int, string> temp;

    while (dokumen >> temp.second >> temp.first)
    {
        job.push(temp);
    }

    dokumen.close();

    cout << left << setw(15) << "" << "DAFTAR" << right << setw(16) << "" << endl;
    cout << "-------------------------------------" << endl;
    cout << "| " << left << setw(20) << "JOB" << " |  " << setw(10) << "PRIORITY" << "|" << endl;
    cout << "-------------------------------------" << endl;
    while (!job.empty())
    {
        cout << "| " << left << setw(20) << job.top().second << " |  " << setw(10) << job.top().first << "|" << endl;

        job.pop();
    }
    cout << "-------------------------------------" << endl;
}

int main()
{
    int operation;

    cout << "Masukan Operasi yang Anda inginkan (\"1\" untuk Menambahkan Pekerjaan dan \"2\" untuk Menampilkan Pekerjaan): ";
    cin >> operation;

    string job;
    int priority;

    switch (operation)
    {
    case 1:
        cout << "Masukan Pekerjaan: ";
        cin >> job;

        cout << "Masukan Prioritas Pekerjaan: ";
        cin >> priority;
        addJob(job, priority);
        break;
    case 2:
        displayJob();
        break;
    default:
        break;
    }

    return 0;
}