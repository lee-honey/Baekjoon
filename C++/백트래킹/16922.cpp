#include <iostream>

using namespace std;

int N(0);
int arr[4] = {1, 5, 10, 50};
bool bIsVisited[1001] = {false,};
int ans(0);

void BackTracking(int depth, int d, int num)
{
    if(depth == N)
    {
        if(bIsVisited[num] == false)
        {
            bIsVisited[num] = true; 
            ans++;
        }
        return;
    }

    for(int i = d; i < 4; i++)
    {
        BackTracking(depth + 1, i, num + arr[i]);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    BackTracking(0, 0, 0);

    cout << ans << '\n';

    return 0;
}