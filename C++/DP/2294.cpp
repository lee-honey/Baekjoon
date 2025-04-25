#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
map<int, int> mp;
vector<int> vec;
int DP[100001] = {0,};
int n(0), k(0);

int main(void)
{
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        int temp(0);
        cin >> temp;

        if(mp[i] == 0)
        {
            vec.push_back(temp);
            DP[temp] = 1;
        }

        mp[i]++;
    }

    sort(vec.begin(), vec.end());

    for(int j = 0; j < vec.size(); j++)
    {
        for(int i = 1; i <= k; i++)
        {
            if(vec[j] <= i && DP[i - vec[j]] != 0)
            {
                if(DP[i] != 0)
                    DP[i] = min(DP[i], DP[vec[j]] + DP[i - vec[j]]);
                else
                    DP[i] = DP[vec[j]] + DP[i - vec[j]];
            }
        }
    }

    if(DP[k] == 0)
        DP[k] = -1;

    cout << DP[k] << '\n';

    return 0;
}