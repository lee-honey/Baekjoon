#include <iostream>

using namespace std;

int N(0), result(0);
int arr[16];

void DFS(int row);
bool isRight(int row);

int main(void)
{
    cin >> N;
    DFS(0);
    cout << result << endl;
}

void DFS(int row)
{
    if(row == N)
    {
        result++;
        return; //이전 분기점으로 이동
    }
    for(int i = 0; i < N; i++)
    {
        arr[row] = i;
        if(isRight(row))
        {
            DFS(row + 1);
        }
    }
}

bool isRight(int row)
{
    for(int i = 0; i < row; i++)
    {
        if(arr[row] == arr[i] || abs(row - i) == abs(arr[row] - arr[i]))
            return false;
    }
    return true;
}