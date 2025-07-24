#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int t(0), n(0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--)
    {
        cin >> n;
        unordered_map<string, int> mp;
        bool bIsConsiquent(true);
        for(int i = 0; i < n; i++)
        {
            string temp;
            cin >> temp;
            mp[temp]++;
        }
        for(auto iter : mp)
        {
            string str = iter.first;
            string temp = "";
            for(int i = 0; i < str.size() - 1; i++)
            {
                temp += str[i];
                if(mp.find(temp) != mp.end()) // O(1) 상수 시간복잡도
                {
                    bIsConsiquent = false;
                    break;
                }
            }
        }
        if(bIsConsiquent)   cout << "YES" << '\n';
        else                cout << "NO" << '\n';
    }

    return 0;
}