// 브루트포스, 백트래킹

#include <iostream>

using namespace std;

int N(0);
int S[21][21] = {0,};
bool visited[21] = {false, };
int ans(2147483647);

void DFS(int depth, int num)
{
    if(depth == N / 2) // 일정 깊이까지 들어가면면
    {
        int temp1(0), temp2(0);
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                if(visited[i] == true && visited[j] == true)
                    temp1 += S[i][j];
                if(visited[i] == false && visited[j] == false)
                    temp2 += S[i][j];
            }
        }
        int cha = abs(temp1 - temp2);
        if(cha < ans)
            ans = cha;
        return; // return
    }

    for(int i = num; i <= N; i++) // 현재 위치부터 시작해서 for문을 돌림
    {
        visited[i] = true;
        DFS(depth + 1, i + 1); // 깊이 + 1, i는 현재값보다 하나 더 크게
        visited[i] = false; // DFS가 최종깊이까지 들어갔을 때 다시 false로 만들어주는 역할
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            cin >> S[i][j];

    DFS(0, 1); // 깊이 0, 숫자 1부터 시작.

    cout << ans << '\n';

    return 0;
}