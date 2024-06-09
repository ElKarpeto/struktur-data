#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdlib>

using namespace std;

const int TOTAL_NUMBERS = 40;
const int NUMBERS_PER_SET = 7;
const int TOTAL_SETS = 5;

int getNextAvailableNumber(int current, vector<bool> &used)
{
    int nextNum = current;
    while (used[nextNum - 1])
    {
        nextNum++;
        if (nextNum > TOTAL_NUMBERS)
        {
            nextNum = 1;
        }
    }
    return nextNum;
}

void generateLottoNumbers()
{
    vector<bool> used(TOTAL_NUMBERS, false);
    vector<vector<int>> allSets(TOTAL_SETS, vector<int>(NUMBERS_PER_SET));

    for (int i = 0; i < TOTAL_SETS; ++i)
    {
        for (int j = 0; j < NUMBERS_PER_SET; ++j)
        {
            int randNum = rand() % TOTAL_NUMBERS + 1;
            int nextNum = getNextAvailableNumber(randNum, used);
            allSets[i][j] = nextNum;
            used[nextNum - 1] = true;
        }
    }

    for (int i = 0; i < TOTAL_SETS; ++i)
    {
        sort(allSets[i].begin(), allSets[i].end());
        cout << "Set " << i + 1 << ": ";
        for (int num : allSets[i])
        {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main()
{
    generateLottoNumbers();
    return 0;
}
