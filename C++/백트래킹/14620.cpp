#include <iostream>
#include <algorithm>
#define MAX 2147483647
using namespace std;

int N(0);
int arr[11][11] = {0,};
bool bIsVisited[11][11] = {false,};
int ans(MAX);

void BackTracking(int depth, int cost)
{
    if(depth == 3)
    {
        ans = min(ans, cost);
        return ;
    }

    for(int i = 1; i < N - 1; i++)
    {
        for(int j = 1; j < N - 1; j++)
        {
            if(bIsVisited[i][j] == false && bIsVisited[i][j - 1] == false && bIsVisited[i][j + 1] == false
            && bIsVisited[i - 1][j] == false && bIsVisited[i + 1][j] == false)
            {
                bIsVisited[i][j] = true;        bIsVisited[i][j - 1] = true;    bIsVisited[i][j + 1] = true;
                bIsVisited[i - 1][j] = true;    bIsVisited[i + 1][j] = true;
                
                BackTracking(depth + 1, cost + (arr[i][j] + arr[i][j - 1] + arr[i][j + 1] + arr[i - 1][j] + arr[i + 1][j]));
                
                bIsVisited[i][j] = false;        bIsVisited[i][j - 1] = false;  bIsVisited[i][j + 1] = false;
                bIsVisited[i - 1][j] = false;    bIsVisited[i + 1][j] = false;
            }
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
    {
        for(int j = 0; j < N; j++)
            cin >> arr[i][j];
    }

    BackTracking(0, 0);

    cout << ans << '\n';

    return 0;
}