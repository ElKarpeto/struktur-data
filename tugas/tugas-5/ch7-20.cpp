#include <iostream>
#include <random>
#include <vector>

using namespace std;

const int NUM_SIMULATIONS = 50;
const int CAPS_PER_SIMULATION = 100;

int simulateCollection(std::mt19937 &gen, std::uniform_int_distribution<> &dis)
{
    int countA = 0, countP = 0, countL = 0, countE = 0;
    int totalCaps = 0;

    while (!(countA >= 1 && countP >= 2 && countL >= 1 && countE >= 1))
    {
        totalCaps++;
        int cap = dis(gen);
        if (cap < 40)
        {
            countA++;
        }
        else if (cap < 80)
        {
            countE++;
        }
        else if (cap < 90)
        {
            countP++;
        }
        else
        {
            countL++;
        }
    }

    return totalCaps;
}

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 99);

    int totalCapsCollected = 0;

    for (int i = 0; i < NUM_SIMULATIONS; ++i)
    {
        totalCapsCollected += simulateCollection(gen, dis);
    }

    double averageCaps = static_cast<double>(totalCapsCollected) / NUM_SIMULATIONS;

    cout << "Average number of caps per simulation to spell 'APPLE': " << averageCaps << endl;

    return 0;
}
