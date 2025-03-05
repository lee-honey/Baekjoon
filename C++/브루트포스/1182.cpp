#include <iostream>

using namespace std;

int N(0), S(0);
int arr[21] = {0, };
int ans(0);

void DFS(int n, int hap)
{
    if(N == n) // 이게 일종의 깊이임
    {
        if(S == hap)
            ans++;
        return ;
    }
    
    DFS(n + 1, hap + arr[n]); // 현재껄 더하는 경우와
    DFS(n + 1, hap); // 더하지 않는 경우로 나눔
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> S;

    for(int i = 0; i < N; i++)
        cin >> arr[i];

    DFS(0, 0);
    if(S == 0) // 공집합을 포함할 경우 부분수열의 크기가 양수가 아니므로 하나 제외
        cout<< ans - 1 << '\n';
    else
        cout << ans << '\n';

    return 0;
}