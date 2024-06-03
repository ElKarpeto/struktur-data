#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

// disini saya menggunakan asumsi f(x) = x^2, karena fungsi tersebut juga sesuai dengan 0 <= x <= 1 | 0 <= f(x) <= 1

double f(double x)
{
    return x * x;
}

double estimateIntegral(int numPoints)
{
    int pointsUnderCurve = 0;

    for (int i = 0; i < numPoints; ++i)
    {
        double x = static_cast<double>(rand()) / RAND_MAX;
        double y = static_cast<double>(rand()) / RAND_MAX;

        if (y < f(x))
        {
            pointsUnderCurve++;
        }
    }

    return static_cast<double>(pointsUnderCurve) / numPoints;
}

int main()
{
    int numPoints = 100000;
    double integralEstimate = estimateIntegral(numPoints);

    cout << "Estimated integral of f(x) from 0 to 1 is: " << integralEstimate << endl;

    return 0;
}
