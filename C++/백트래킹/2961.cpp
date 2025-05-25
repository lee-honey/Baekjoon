#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int N(0);
bool bIsVisited[10] = {false,};
int arr[10] = {0,};
int sinn[10] = {0,};
int ssen[10] = {0,};
int ans(2147483647);

void DFS(int depth)
{
    if(depth == N)
    {
        int tempSin(1), tempSsen(0);
        for(int i = 0; i < N; i++)
        {
            tempSin *= sinn[arr[i]];
            tempSsen += ssen[arr[i]];
        }
        ans = min(ans, abs(tempSin - tempSsen));
        return;
    }
    for(int i = 0; i < N; i++)
    {
        if(bIsVisited[i] == false)
        {
            bIsVisited[i] = true;
            arr[depth] = i;
            DFS(depth + 1);
            bIsVisited[i] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++)
        cin >> sinn[i] >> ssen[i];

    DFS(0);

    cout << ans << '\n';

    return 0;
}