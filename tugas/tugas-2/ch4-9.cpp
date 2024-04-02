#include <bits/stdc++.h>
using namespace std;

void decimalToBinary(list<int> &linked, int num)
{
    while (num >= 1)
    {
        int i = num % 2;
        num /= 2;
        linked.push_back(i);
    }
}

int binaryToDecimal(list<int> &linked)
{
    int power = linked.size() - 1;

    int result = 0;
    while (power >= 0 && !linked.empty())
    {
        result += linked.back() * powf(2, power);
        linked.pop_back();
        power--;
    }

    return result;
}

void sizeEq(list<int> &num1, list<int> &num2)
{
    if (num1.size() > num2.size())
    {
        while (!(num1.size() == num2.size()))
        {
            num2.push_back(0);
        }
    }
    else if (num1.size() < num2.size())
    {
        while (!(num1.size() == num2.size()))
        {
            num1.push_back(0);
        }
    }
}

void addBinary(list<int> &result, list<int> &num1, list<int> &num2)
{
    sizeEq(num1, num2);

    int carry = 0;
    while (!num1.empty())
    {
        int temp = carry + num1.front() + num2.front();
        if (temp > 1)
        {
            if (temp % 2 == 0)
            {
                result.push_back(0);
                carry = 1;
            }
            else if (temp % 2 == 1)
            {
                result.push_back(1);
                carry = 1;
            }
        }
        else
        {
            result.push_back(temp);
            carry = 0;
        }

        num1.pop_front();
        num2.pop_front();
    }

    if (carry)
    {
        result.push_back(1);
    }
}

int main()
{
    int num1, num2, choice;

    cin >> num1 >> num2;

    cin >> choice;

    list<int> bin_num1, bin_num2, result;

    decimalToBinary(bin_num1, num1);
    decimalToBinary(bin_num2, num2);

    switch (choice)
    {
    case 1:
        decimalToBinary(result, (binaryToDecimal(bin_num1) + binaryToDecimal(bin_num2)));
        while (!result.empty())
        {
            cout << result.back() << " ";
            result.pop_back();
        }
        cout << endl;

        break;
    case 2:
        addBinary(result, bin_num1, bin_num2);

        while (!result.empty())
        {
            cout << result.back() << " ";
            result.pop_back();
        }
        cout << endl;

        break;
    default:
        break;
    }

    return 0;
}