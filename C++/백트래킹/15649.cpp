#include <iostream>

using namespace std;

int N(0), M(0);
bool bIsVisited[10] = {false,};
int arr[10] = {0,};
void Backtracking(int cnt)
{
    if(cnt == M)
    {
        for(int i = 0; i < M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = 1; i <= N; i++)
    {
        if(bIsVisited[i] == false)
        {
            bIsVisited[i] = true;
            arr[cnt] = i; // 현재 cnt 위치에 i를 넣어 arr을 채워나간다.
            Backtracking(cnt + 1);
            bIsVisited[i] = false;  
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    Backtracking(0);
    return 0;
}