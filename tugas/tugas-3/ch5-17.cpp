#include <bits/stdc++.h>
using namespace std;

bool isPalindrom(queue<char> &list1, queue<char> &list2)
{
    while (list1.size() > 0)
    {
        if (list1.front() == list2.front())
        {
            list1.pop();
            list2.pop();
        }
        else
        {
            break;
        }
    }

    return (list1.size() == 0);
}

int main()
{
    string word;

    cin >> word;

    queue<char> list1, list2;

    for (int i = 0; i < word.size(); i++)
    {
        list1.push(word[i]);
    }

    for (int i = word.size() - 1; i >= 0; i--)
    {
        list2.push(word[i]);
    }

    if (!isPalindrom(list1, list2))
    {
        cout << "not ";
    }

    cout << "Palindrome" << endl;
}