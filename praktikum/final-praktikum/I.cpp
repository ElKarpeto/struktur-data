#include <bits/stdc++.h>
using namespace std;

bool closed(string pattern)
{
    stack<char> stack;
    for (int i = 0; i < pattern.length(); i++)
    {
        char element = pattern[i];

        if (element == '(' || element == '{' || element == '[' || element == '<')
        {
            stack.push(element);
        }

        else
        {

            if (!stack.empty())
            {
                char top = stack.top();
                if ((element == ')' && top == '(') || (element == '}' && top == '{') || (element == ']' && top == '[') || (element == '>' && top == '<'))
                {

                    stack.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {

                return false;
            }
        }
    }

    return stack.empty();
}

int main(int argc, char **argv)
{
    string test;

    cin >> test;

    if (closed(test))
    {
        cout << "Sudah ditutup";
        cout << "\n";
    }
    else
    {
        cout << "Belum ditutup";
        cout << "\n";
    }
}
