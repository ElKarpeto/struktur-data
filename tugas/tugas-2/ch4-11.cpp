#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string word1, string word2)
{
    if (word1.size() != word2.size())
    {
        return false;
    }

    priority_queue<char> queue1, queue2;

    int len = word1.size();
    for (int i = 0; i < len; i++)
    {
        queue1.push(word1[i]);
        queue2.push(word2[i]);
    }

    while (!queue1.empty())
    {
        if (queue1.top() == queue2.top())
        {
            queue1.pop();
            queue2.pop();
        }
        else
        {
            break;
        }
    }

    return (queue1.size() == 0);
}

int main()
{
    string word1, word2;

    cin >> word1 >> word2;

    if (isAnagram(word1, word2))
    {
        cout << "Anagram" << endl;
    }
    else
    {
        cout << "not Anagram" << endl;
    }
}