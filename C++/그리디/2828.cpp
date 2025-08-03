#include <iostream>

using namespace std;

int N(0), M(0);
int J(0);
int ans(0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    cin >> J;
    int cur(1);
    for(int i = 0; i < J; i++)
    {
        int goal(0);
        cin >> goal;

        if(cur == goal)
            continue;

        int minDist(0);
        if(cur < goal)
            minDist = (goal - cur - (M - 1));
        else
            minDist = -(goal - cur);

        if(minDist <= 0)
            continue;
        
        cur = goal + ((cur < goal) ? -(M - 1) : 0);

        ans += minDist;
    }

    cout << ans << '\n';

    return 0;
}