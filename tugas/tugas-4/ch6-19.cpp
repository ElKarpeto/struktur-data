#include <iostream>
#include <vector>

using namespace std;

const int N = 8;

void printSolution(const vector<int> &solution)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (solution[i] == j)
            {
                cout << "1 ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

bool isSafe(const vector<int> &solution, int row, int col)
{
    for (int i = 0; i < row; ++i)
    {
        if (solution[i] == col || abs(i - row) == abs(solution[i] - col))
        {
            return false;
        }
    }
    return true;
}

bool solveNQueensUtil(vector<int> &solution, int row)
{
    if (row == N)
        return true;

    for (int col = 0; col < N; ++col)
    {
        if (isSafe(solution, row, col))
        {
            solution[row] = col;

            if (solveNQueensUtil(solution, row + 1))
                return true;

            solution[row] = -1;
        }
    }

    return false;
}

void solveNQueens()
{
    vector<int> solution(N, -1);

    if (!solveNQueensUtil(solution, 0))
    {
        cout << "Solusi tidak ada" << endl;
        return;
    }

    printSolution(solution);
}

int main()
{
    solveNQueens();
    return 0;
}
