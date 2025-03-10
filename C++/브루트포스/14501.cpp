#include <iostream>

using namespace std;

int N(0);
pair<int, int> arr[16] = {{0, 0}, };
int DP[16] = {0,};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 1; i <= N; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }

    for(int i = 1; i <= N; i++)
    {

    }

    return 0;
}