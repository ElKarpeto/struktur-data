#include <bits/stdc++.h>
using namespace std;

const string COURSES[] = {"CS20A", "CS21A", "CS29A", "CS30A", "CS35A", "CS36A"};
const int NUM_COURSES = 6;

void result()
{
    ifstream file("registration_data.txt");
    if (!file.is_open())
    {
        cout << "ERROR DALAM MEMBUKA FILE" << endl;
        return;
    }

    unordered_map<string, vector<string>> courseLists;

    string registrationNumber;
    while (file >> registrationNumber && registrationNumber != "0")
    {
        for (int i = 0; i < NUM_COURSES; ++i)
        {
            int registration;
            file >> registration;
            if (registration == 1)
            {
                courseLists[COURSES[i]].push_back(registrationNumber);
            }
        }
    }

    for (const auto &course : COURSES)
    {
        cout << "Class list for " << course << ":" << endl;
        for (const auto &student : courseLists[course])
        {
            cout << student << endl;
        }
        cout << endl;
    }

    file.close();
}

int main()
{
    result();

    return 0;
}
