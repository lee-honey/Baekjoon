#include <iostream>
#include <cmath>
#include <map>

using namespace std;

int N(0);
map<double, int> mp;
int ans(0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    while(N--)
    {
        int x(0), y(0);
        cin >> x >> y;
        double theta = atan2(y,x);
        mp[theta]++;
    }

    for(auto iter = mp.begin(); iter != mp.end(); iter++)
    {
        if(ans < (*iter).second)
            ans = (*iter).second;
    }

    cout << ans << '\n';

    return 0;
}