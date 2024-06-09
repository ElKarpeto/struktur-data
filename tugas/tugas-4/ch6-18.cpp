#include <iostream>
using namespace std;

int northPath(int a, int b, int targetX, int targetY)
{
    if (a == targetX)
    {
        return 1;
    }

    if (b == targetY)
    {
        return 1;
    }

    return northPath(a + 1, b, targetX, targetY) + northPath(a, b + 1, targetX, targetY);
}

int main()
{
    int a, b, targetX, targetY;

    cin >> a >> b >> targetX >> targetY;

    int result = northPath(a, b, targetX, targetY);

    cout << result << endl;
}