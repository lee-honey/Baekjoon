#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int N(0);
map<int, int> mp;
int ans(0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    while(N > 0)
    {
        if(N % 10 == 6 || N % 10 == 9)
        {
            if(mp[6] > mp[9])
                mp[9]++;
            else
                mp[6]++;
        }
        else
            mp[N % 10]++;
        N /= 10;
    }

    for(auto& iter : mp)
    {
        ans = max(ans, iter.second);
    }

    cout << ans << '\n';

    return 0;
}
       