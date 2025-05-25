#include <iostream>
#include <cstring>

using namespace std;

int     N(0);

bool IsPrime(int num)
{
    if(num < 2)
        return false;
    for(int i = 2; i * i <= num; i++)
        if(num % i == 0)
            return false;
    return true;
}

void DFS(int depth, int num)
{
    if(IsPrime(num) == false) // 매 검사에서 소수인 경우만 아래 조건으로 이동 가능
        return;

    if(depth == N)
    {
        cout << num << '\n';
        return;
    }
    for(int i = 0; i <= 9; i++)
        DFS(depth + 1, num * 10 + i);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    
    int iStartNum[4] = {2,3,5,7};
    for(int i = 0; i < 4; i++)
        DFS(1, iStartNum[i]);

    return 0;
}