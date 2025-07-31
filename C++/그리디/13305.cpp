#include <iostream>
#include <vector>

using namespace std;

int N(0);
vector<int> load;
vector<int> cost;
long long sum(0);
long long cur(0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    load.resize(N);
    cost.resize(N);

    for(int i = 1; i < N; i++)
        cin >> load[i];
    for(int i = 0; i < N; i++)
        cin >> cost[i];

    cur = cost[0];
    sum = cur * load[1];

    for(int i = 1; i < N - 1; i++)
    {
        if(cur >= cost[i])
            cur = cost[i];
        sum += cur * load[i + 1];
    }

    cout << sum << '\n';

    return 0;
}