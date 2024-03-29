#include <bits/stdc++.h>
using namespace std;

int jamToMenit(int a)
{
    return a * 60;
}

int selisih(int a, int b, int c, int d)
{
    if (a > c)
    {
        int setZero = 24 - a;
        return jamToMenit(setZero) + jamToMenit(c) + d - b;
    }
    else if (a == c)
    {
        if (d > b)
        {
            return d - b;
        }
        else if (b == d)
        {
            return 0;
        }
        else
        {
            return 24 - (d - b);
        }
    }
    else
    {
        return jamToMenit(c - a) + d - b;
    }
}

int main()
{
    int jam1, menit1, jam2, menit2;

    cin >> jam1 >> menit1 >> jam2 >> menit2;

    int result = selisih(jam1, menit1, jam2, menit2);

    printf("selisih antara jam %d.%d dan jam %d.%d adalah %d menit\n", jam1, menit1, jam2, menit2, result);

    return 0;
}