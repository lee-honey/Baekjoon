#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string s1, s2;
int ans(0);
vector<vector<int>> vec;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s1 >> s2;
    vec.resize(s1.size() + 1);
    for(int i = 0; i < vec.size(); i++)
        vec[i].resize(s2.size() + 1);

    for(int i = 0; i < s1.size(); i++)
    {
        for(int j = 0; j < s2.size(); j++)
        {
            if(s1[i] == s2[j])
            {
                vec[1 + i][1 + j] = vec[i][j] + 1;
                ans = max(ans, vec[i + 1][j + 1]);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}