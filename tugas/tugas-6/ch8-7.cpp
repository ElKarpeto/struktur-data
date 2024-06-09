#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
using namespace std;

#define DATAFILE "data.bin"
#define KEYFILE "key.bin"

/*
Harus diperhatikan, data pada data.bin harus berformat
Key, Nama, Posisi, No Telepon, Gaji, Pajak
*/

struct Data
{
    string nama, posisi, no_telp;
    int gaji, pajak;
};

map<int, string> keys;
map<string, Data> dataKaryawan;

void displayOption()
{
    cout << "========== OPTIONS ==========" << endl;
    cout << "1. Tampilkan Key" << endl;
    cout << "2. Tampilkan Semua Data" << endl;
    cout << "3. Tampilkan Data dengan Key" << endl;
    cout << "4. Keluar" << endl;
    cout << "=============================" << endl;
}

void inputData()
{
    ifstream fileInput(DATAFILE, ios_base::binary | ios_base::in);
    ofstream fileOutput(KEYFILE, ios_base::binary | ios_base::app);

    if (!fileInput.is_open() || !fileOutput.is_open())
    {
        cout << "Tidak berhasil membuka file" << endl;
        exit(1);
    }

    string line;

    int count = 0;
    while (getline(fileInput, line))
    {
        istringstream temp(line);
        string key;
        Data karyawan;

        getline(temp, key, ',');
        getline(temp, karyawan.nama, ',');
        getline(temp, karyawan.posisi, ',');
        getline(temp, karyawan.no_telp, ',');

        string tempGaji, tempPajak;
        getline(temp, tempGaji, ',');
        getline(temp, tempPajak, ',');
        karyawan.gaji = stoi(tempGaji);
        karyawan.pajak = stoi(tempPajak);

        keys[count] = key;
        dataKaryawan[key] = karyawan;

        char tulis[100];
        sprintf(tulis, "%d,%s", count, key.c_str());

        fileOutput.write(tulis, sizeof(tulis));

        count++;
    }

    fileOutput.close();
    fileInput.close();
}

void takeData(int key)
{
    string tempKey = keys[key];
    Data tempdata = dataKaryawan[tempKey];

    cout << "--------- DATA ---------" << endl;
    cout << "Nama: " << tempdata.nama << endl;
    cout << "Posisi: " << tempdata.posisi << endl;
    cout << "No Telepon: " << tempdata.no_telp << endl;
    cout << "Gaji: " << tempdata.gaji << endl;
    cout << "Pajak: " << tempdata.pajak << endl;
    cout << "-----------------------" << endl;
}

void displayKey()
{
    cout << "------- KEY -------" << endl;
    for (auto it = keys.begin(); it != keys.end(); it++)
    {
        cout << it->first << " - " << it->second << endl;
    }
    cout << "-------------------" << endl;
}

void displayAlldata()
{
    auto it = dataKaryawan.begin();
    int count = 1;
    while (it != dataKaryawan.end())
    {
        cout << "Karyawan " << count << ":" << endl;
        cout << "Nama: " << it->second.nama << endl;
        cout << "Posisi: " << it->second.posisi << endl;
        cout << "No Telepon: " << it->second.no_telp << endl;
        cout << "Gaji: " << it->second.gaji << endl;
        cout << "Pajak: " << it->second.pajak << endl;
        cout << endl;

        it++;
        count++;
    }
}

int main()
{
    inputData();
    int option;

    int key;
    while (option != 4)
    {
        displayOption();
        cin >> option;
        switch (option)
        {
        case 1:
            displayKey();
            break;
        case 2:
            displayAlldata();
            break;
        case 3:
            displayKey();
            cin >> key;
            takeData(key);
        default:
            cout << "KELUAR DARI PROGRAM" << endl;
            break;
        }
    }

    return 0;
}
