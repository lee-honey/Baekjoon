#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

map<string, int> mp;
int cnt(0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    while(getline(cin, str))
    {
        mp[str]++;
        cnt++;
    }

    cout << fixed;      // 소수점자리수에대해서만 precision이 적용되도록 설정하는 부분
    cout.precision(4);  // 소수점4째자리
    for(auto iter : mp)
    {
        cout << iter.first << " " << ((double)iter.second / cnt) * 100 << '\n';
    }

    return 0;
}