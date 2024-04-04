#include <bits/stdc++.h>
using namespace std;

stack<int> sortStack(stack<int> &input)
{
    stack<int> tmpStack;

    while (!input.empty())
    {
        int tmp = input.top();
        input.pop();

        while (!tmpStack.empty() && tmpStack.top() < tmp)
        {
            input.push(tmpStack.top());
            tmpStack.pop();
        }

        tmpStack.push(tmp);
    }

    return tmpStack;
}

int main()
{
    stack<int> s1, s2;

    int n, num;

    cin >> n;

    while (n--)
    {
        cin >> num;

        s1.push(num);
    }

    s2 = sortStack(s1);

    while (!s2.empty())
    {
        cout << s2.top() << endl;
        s2.pop();
    }

    return 0;
}