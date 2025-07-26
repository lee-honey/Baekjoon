#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int N(0);
unordered_map<long long, int> mp;
int maxNum(0);
vector<long long> vec;
long long ans(LLONG_MAX);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        long long temp(0);
        cin >> temp;
        mp[temp]++;
        if(mp[temp] > maxNum)
            maxNum = mp[temp];
    }

    for(auto& iter : mp)
    {
        if(iter.second == maxNum)
        {
            vec.push_back(iter.first);
        }
    }

    sort(vec.begin(), vec.end());

    cout << vec[0] << '\n';

    return 0;
}