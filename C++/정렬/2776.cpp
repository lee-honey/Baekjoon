#include <iostream>
#include <unordered_map>

using namespace std;

int T(0), N(0), M(0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while(T--)
    {
        cin >> N;
        unordered_map<int, int> mp;
        for(int i = 0; i < N; i++)
        {
            int temp(0);
            cin >> temp;
            mp[temp]++;
        }
        cin >> M;
        for(int i = 0; i < M; i++)
        {
            int temp(0), res(0);
            cin >> temp;
            if(mp.find(temp) != mp.end())
                res = 1;
            cout << res << '\n';
        }
    }

    return 0;
}