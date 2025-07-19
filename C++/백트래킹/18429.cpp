#include <iostream>

using namespace std;

int N(0), K(0);
int arr[8] = {0,};
bool bIsVisited[8] = {false,};
int ans(0);

void BackTracking(int depth, int weight)
{
    if(weight < 500)
        return;
    
    if(depth == N)
    {
        ans++;
        return;
    }

    for(int i = 0; i < N; i++)
    {
        if(bIsVisited[i] == false)
        {
            bIsVisited[i] = true;
            BackTracking(depth + 1, weight - K + arr[i]);
            bIsVisited[i] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    BackTracking(0, 500);

    cout << ans << '\n';
    
    return 0;
}