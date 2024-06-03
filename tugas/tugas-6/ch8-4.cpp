#include <bits/stdc++.h>
using namespace std;

vector<int> arr;

int main()
{
    ifstream file;
    string namaFile = "data.bin";

    file.open(namaFile, ios_base::binary | ios_base::in);

    if (!file.is_open())
    {
        cout << "File tidak berhasil dibuka" << endl;
        exit(1);
    }

    int num;
    while (file.read(reinterpret_cast<char *>(&num), sizeof(num)))
    {
        arr.push_back(num);
    }

    file.close();

    sort(arr.begin(), arr.end());

    int countFile = 0;
    int i = 0;

    while (i < arr.size())
    {
        string outputFileName;
        if (countFile == 0)
        {
            outputFileName = namaFile;
        }
        else
        {
            outputFileName = "data" + to_string(countFile) + ".bin";
        }

        ofstream fileOutput(outputFileName, ios_base::binary | ios_base::out);

        if (!fileOutput.is_open())
        {
            cout << "File tidak berhasil dibuka" << endl;
            exit(1);
        }

        for (int j = 0; j < 20 && i < arr.size(); j++, i++)
        {
            fileOutput.write(reinterpret_cast<char *>(&arr[i]), sizeof(arr[i]));
        }

        fileOutput.close();
        countFile++;
    }

    return 0;
}
