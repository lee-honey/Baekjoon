#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string s1, s2;
vector<vector<int>> vec;
int cnt(0);
string ans;
vector<vector<pair<int, int>>> temp;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s1 >> s2;

    if(s1 == s2)
    {
        cout << s1.size() << '\n';
        cout << s1 << '\n';
        return 0;
    }

    if(s1.size() < s2.size())
    {
        string temp = s2;
        s2 = s1;
        s1 = temp;
    }

    vec.resize(s2.size() + 1);
    for(int i = 0; i < vec.size(); i++)
        vec[i].resize(s1.size() + 1);

    temp.resize(s1.size());

    for(int i = 0; i < s2.size(); i++)
    {
        for(int j = 0; j < s1.size(); j++)
        {
            if(s2[i] == s1[j])
            {
                vec[1 + i][1 + j] = vec[i][j] + 1;
                cnt = max(cnt, vec[1 + i][1 + j]);
                if(vec[i][1 + j] != vec[1 + i][1 + j])
                    temp[vec[1 + i][1 + j]].push_back({1 + i, 1 + j});
            }
            else
                vec[1 + i][1 + j] = max(vec[1 + i][j], vec[i][j + 1]);
        }
    }

    if(cnt > 0)
    {
        ans.resize(cnt);
        int x(s2.size() + 1), y(s1.size() + 1);
        for(int i = cnt; i >= 1; i--)
        {
            for(int j = 0; j < temp[i].size(); j++)
            {
                if(temp[i][j].first < x && temp[i][j].second < y)
                {
                    x = temp[i][j].first;
                    y = temp[i][j].second;
                    ans[i - 1] = s1[y - 1];
                }
            }
        }
    }

    cout << cnt << '\n';
    if(cnt > 0)
        cout << ans << '\n';

    return 0;
}